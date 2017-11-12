#pragma once
#define DEFAULT_CAPACITY 10

template<typename T>
class Vector
{
public:
/*constructor*/
	Vector(T e=(T)0,int s=0,int c=DEFAULT_CAPACITY)
	{
		elem_ = new T[capacity_ = c];
		for (size_ = 0; size_ < s; elem_[i++] = e);
	}
	Vector(T *array, int lo, int hi) { copyFrom(array, lo, hi); }
	Vector(T *array, int n) { copyFrom(array, 0, n); }
	Vector(Vector<T> const &v) { copyFrom(v.elem_, 0, v.size_); }
	Vector(Vector<T> const &v, int lo, int hi) { copyFrom(v.elem_, lo, hi); }
	~Vector() { delete elem_; }

/*manipulator*/
	Vector<T>& operator=(Vector<T> const &v);
	T& operator[](int loc) { return elem_[loc]; }
	
protected:
	T *elem_;
	int capacity_;
	int size_;

	void copyFrom(T *array, int lo, int hi);//function to copy an array to a vector
	void expand();//check if the capacity reach litmit,if so ,then alloc more 


};

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& v)
{
	if (this->elem_) delete[]elem_;//delete old element array if it exsists
	copyFrom(v.elem_, 0, v.size_);
	return *this;
}

template <typename T>
void Vector<T>::copyFrom(T* array, int lo, int hi)
{
	elem_ = new T[capacity_ = (hi - lo) << 1];//alloc elem and set capacity
	size_ = 0;
	while (lo<hi)
	{
		elem_[size_++] = array[lo++]; //copy array
	}
}
template <typename T>
void Vector<T>::expand()
{
	if (size_ < capacity_) return; //if the capacity havn't reach the limit ,do nothing but return
	T *temp = elem_;
	copyFrom(temp, 0, size_);//copy old elem to a bigger one
	delete[]temp;//free old array
}

