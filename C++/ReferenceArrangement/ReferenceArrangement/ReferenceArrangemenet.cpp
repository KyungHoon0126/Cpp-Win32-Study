#include <iostream>

// 포인터(Pointer)
#if false
int change_val(int* p)
{
	*p = 3;
	return 0;
}

int main()
{
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}
#endif  // false

// 참조자(레퍼런스 - reference)
#if false
int main() 
{
	// 참조자를 정하는 방법은 가리키고자 하는 타입 뒤에 & 를 붙이면 된다.
	// 포인터 타입의 참조자를 만드려면 int*&로 쓰면 된다.
	
	// ※ 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 한다.
	// C에서 포인터 int *p는 가능하지만 int& another_a(참조자)를 먼저 선언하는 것은 불가능.
	// 또한 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.

	int a = 3;
	int& another_a = a; // a의 참조자 another_a, another_a는 a의 또다른 이름, 즉 another_a에 작업을 수행하면 a에 작업을 하는 것과 같다.

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
}
#endif // false

#if true
// 함수 인자로 레퍼런스 받기
int change_val(int& p)
{
	p = 3;
	return 0;
}

int main()
{
	int number = 5;

	std::cout << number << std::endl;
	// int& p 는 안된다고 하지 않았나 ?
	// 그러나 p 가 정의되는 순간은 change_val(number)로 호출할 때 이므로
	// 사실상 int& p = number 가 실행된다고 생각하면 된다.
	change_val(number);
	std::cout << number << std::endl;
}
#endif // true
