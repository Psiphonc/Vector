#pragma once
#define DEFAULT_CAPACITY 10

template<typename T>
class Vector
{
public:
	Vector(T e=(T)0,int s=0,int c=DEFAULT_CAPACITY)
	{
		elem_ = new T[capacity_ = c];
		for (int i = 0; i < s; elem_[i++] = e);
	}
	~Vector();
protected:
	T *elem_;
	int capacity_;
	int size_;

};

