#include "Vector.h"
#include <iostream>

int main(int argc, char* argv[])
{
	int a[] = {1,2,3,4,5,6,7,8};
	Vector<int> v(a, 8);
	v.sort();
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ' ';
	}
	std::cout << v.search(5);
	v.insert(4, 4);
	std::cout << v.search(5);
	v.remove(4);
	std::cout << v.search(5);
}
