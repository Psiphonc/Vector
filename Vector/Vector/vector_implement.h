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
	for (int i = size_; i < size_; --i)//move all elements which are behind loc 1 step forward 
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