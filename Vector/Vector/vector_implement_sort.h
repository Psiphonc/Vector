#pragma once
#include <ostream>
#include <iostream>

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
	for (int i = 0, j = lo; j < mi; ++i, ++j)
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

#include "D:\OneDrive\OneDrive - stu.ncwu.edu.cn\PQ_ComplHeap\PQ_ComplHeap\PQ_ComplHeap/PQ_ComplHeap.h"

template <typename T>
void Vector<T>::heapSort(int lo, int hi)
{
	PQ_ComplHeap<T> pq(elem_, hi - lo);
	for (int i = hi - 1; i >= lo; --i)
	{
		elem_[i] = pq.delMax();
	}
}

template <typename T>
void Vector<T>::quickSort(int lo, int hi)
{
	if (hi - lo < 2)
		return;
	int mi = partition(lo, hi - 1);
	quickSort(lo, mi);
	quickSort(mi + 1, hi);
}

template <typename T>
int Vector<T>::partition(int lo, int hi)
{
	std::swap(elem_[lo], elem_[lo + rand() % (hi - lo + 1)]);
	T pivot = elem_[lo];
	while (lo < hi)
	{
		while ((lo < hi) && (pivot <= elem_[hi]))
			--hi;
		elem_[lo] = elem_[hi];
		while ((lo < hi) && (elem_[lo] <= pivot))
			++lo;
		elem_[hi] = elem_[lo];
	}
	elem_[lo] = pivot;
	return lo;
}

template <typename T>
void Vector<T>::shellSort(int lo, int hi)
{
	int a[] = {1,3,7,15,31,64};
	Vector<int> step(a, sizeof(a) / sizeof(int));
	for (int i = step.search(hi - lo); i >= 0; --i)
	{
		shellInsert(lo, hi, step[i]);
		for (int i = 0; i < this->size(); ++i)
		{
			std::cout << elem_[i] << ' ';
		}
		std::cout << std::endl;
	}
}

template <typename T>
void Vector<T>::shellInsert(int lo, int hi, int step)
{
	for (int col = 0; col < step; ++col)
	{
		int cur_elem;
		for (cur_elem = lo + step + col; cur_elem < hi; cur_elem += step)
		{
			int loc_to_insert;
			T temp = elem_[cur_elem];
			for (loc_to_insert = cur_elem - step; loc_to_insert >= lo; loc_to_insert -= step)
			{
				if (elem_[loc_to_insert] < elem_[cur_elem])
					break;
			}
			for (int move_index = cur_elem - step; move_index > loc_to_insert; move_index -= step)
			{
				elem_[move_index + step] = elem_[move_index];
			}
			elem_[loc_to_insert + step] = temp;
		}
	}
}
