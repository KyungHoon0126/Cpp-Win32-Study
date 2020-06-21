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

#if false
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

// 여러가지 참조자 예시
#if false
int main()
{
	int x;
	int& y = x;
	int& z = y;

	// x, 참조자 y, 참조자 z 의 값은 1로 동일하다.
	// 그 이유는, y와 z가 x의 참조자이므로 x의 값을 변경하는 것이나 y or z의 값을 변경하는 것과 같기 때문이다.
	x = 1;
	std::cout << "x : " << x << " y :" << y << " z : " << z << std::endl;

	// 위와 동일하게 값이 변하는 것으로 작동한다.
	y = 2;
	std::cout << "x : " << x << " y :" << y << " z : " << z << std::endl;
	
	// 위와 동일하게 값이 변하는 것으로 작동한다.
	z = 3;
	std::cout << "x : " << x << " y :" << y << " z : " << z << std::endl;
}

#endif // false

// 상수에 대한 참조자
#if true
int main()
{
	// 상수 값 자체는 리터럴 이기 때문에 참조 불가
	// int& ref = 4;

	// std::cout << ref << std::endl;

	// 상수 참조자로 선언한다면 리터럴도 참조 가능
	const int& ref = 4;

	int a = ref; // a = 4;

	std::cout << ref << std::endl;
}
#endif // true