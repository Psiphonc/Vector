#pragma once
#define DEFAULT_CAPACITY 10

template <typename T>
class Vector
{
public:
	/*constructor*/
	Vector(T e = (T)0, int s = 0, int c = DEFAULT_CAPACITY)
	{
		elem_ = new T[capacity_ = c];
		for (size_ = 0; size_ < s; elem_[size_++] = e);
	}
	Vector(T* array, int lo, int hi) { copyFrom(array, lo, hi); }
	Vector(T* array, int n) { copyFrom(array, 0, n); }
	Vector(Vector<T> const& v) { copyFrom(v.elem_, 0, v.size_); }
	Vector(Vector<T> const& v, int lo, int hi) { copyFrom(v.elem_, lo, hi); }
	~Vector() { delete elem_; }

	/*manipulator*/
	Vector<T>& operator=(Vector<T> const& v);
	T& operator[](int loc) { return elem_[loc]; }
	T insert(T const& e, int loc);
	T append(T const& e);//insert an element in the last
	int removeFrom(int lo, int hi);//remove elements in range of [lo,hi)
	T remove(int loc);

protected:
	T* elem_;
	int capacity_;
	int size_;

	void copyFrom(T* array, int lo, int hi);//function to copy an array to a vector
	void expand();//check if the capacity reach litmit,if so ,then alloc more 
};

#include "vector_implement.h"
