#include <iostream>

#if true
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
#endif // true