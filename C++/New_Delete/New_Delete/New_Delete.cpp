#include <iostream>

#if false
// Use new & delete

int main()
{
	// new : malloc�� �����Ǵ� ������ �޸� �Ҵ�
	// delete : free�� �����Ǵ� ������ �޸� ����

	int* p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;
	return 0;
}
#endif // false

#if false
// new�� �迭 �Ҵ��ϱ�
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
