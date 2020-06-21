#include <iostream>

#if true
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
#endif // true