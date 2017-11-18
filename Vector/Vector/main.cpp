#include "Vector.h"
#include <iostream>

int main(int argc, char* argv[])
{
	int a[] = { 4,4,5,7,8,0,2,2,4,76,4,87,1 };
	Vector<int> v(a, sizeof(a) / sizeof(int));
	v.shellSort(0,v.size());
//	for (int i = 0; i < v.size(); ++i)
//	{
//		std::cout << v[i] << ' ';
//	}
}
