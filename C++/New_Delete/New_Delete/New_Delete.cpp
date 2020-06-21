#include <iostream>

#if false
// Use new & delete

int main()
{
	// new : malloc과 대응되는 것으로 메모리 할당
	// delete : free에 대응되는 것으로 메모리 해제

	int* p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;
	return 0;
}
#endif // false

#if false
// new로 배열 할당하기
int main()
{
	int arr_size;
	
	std::cout << "array size : ";
	std::cin >> arr_size;

	int* list = new int[arr_size];

	for (int i = 0; i < arr_size; i++)
	{
		std::cin >> list[i];
	}

	for (int i = 0; i < arr_size; i++)
	{
		std::cout << i << "the element of list : " << list[i] << std::endl;
	}

	delete[] list;

	return 0;
}
#endif // false

#if true

#endif // true
