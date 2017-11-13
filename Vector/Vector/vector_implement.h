#pragma once
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& v)
{
	if (this->elem_) delete[]elem_;//delete old element array if it exsists
	copyFrom(v.elem_, 0, v.size_);
	return *this;
}

template <typename T>
T Vector<T>::insert(T const& e, int loc)
{
	expand();//check out if elem is full
	for (int i = size_; loc < i; --i)//move all elements which are behind loc 1 step forward 
	{
		elem_[i] = elem_[i - 1];
	}
	size_++;
	return elem_[loc] = e;
}

template <typename T>
T Vector<T>::append(T const& e)
{
	return insert(e, size_);
}

template <typename T>
int Vector<T>::removeFrom(int lo, int hi)
{
	while (hi < size_) elem_[lo++] = elem_[hi++];
	size_ = lo;
	return hi - lo;
}

template <typename T>
T Vector<T>::remove(int loc)
{
	T temp = elem_[loc];//backup
	removeFrom(loc, loc + 1);
	return temp;
}

template <typename T>
void Vector<T>::copyFrom(T* array, int lo, int hi)
{
	elem_ = new T[capacity_ = (hi - lo) << 1];//alloc elem and set capacity
	size_ = 0;
	while (lo < hi) elem_[size_++] = array[lo++]; //copy array
}

template <typename T>
void Vector<T>::expand()
{
	if (size_ < capacity_) return; //if the capacity havn't reach the limit ,do nothing but return
	T* temp = elem_;
	copyFrom(temp, 0, size_);//copy old elem to a bigger one
	delete[]temp;//free old array
}
template<typename T>
int Vector<T>::search(T const& e,int lo,int hi) const 
{
	while(lo<hi)
	{
		int mi = (lo + hi) >> 1;
		if (e < elem_[mi])
			hi = mi;
		else
			lo = mi + 1;
	}
	return --lo;
}
template <typename T>
void Vector<T>::mergeSort(int lo, int hi)
{
	if (hi - lo < 2) return;
	int mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}
template <typename T>
void Vector<T>::merge(int lo, int mi, int hi)
{
	T* former = new T[mi - lo];
	for (int i = 0,j=lo; j < mi; ++i,++j)
	{
		former[i] = elem_[j];
	}
	for (int i = 0, j = mi, k = lo; i < mi - lo || j < hi;)
	{
		if ((i < mi - lo) && ((!(j < hi) || former[i] <= elem_[j])))
			elem_[k++] = former[i++];
		if ((j < hi) && (!(i < mi - lo) || former[i] > elem_[j]))
			elem_[k++] = elem_[j++];
	}
	delete[]former;
}