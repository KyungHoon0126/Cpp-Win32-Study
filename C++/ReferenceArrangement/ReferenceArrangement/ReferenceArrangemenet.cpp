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
#if false
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
#endif // false

// 레퍼런스의 배열과 배열의 레퍼런스
#if false
int main()
{
	// 레퍼런스의 배열은 불법이라고 나와있다.
	// int a, b;
	// int& arr[2] = { a, b };

	// 그런데 주소값이 존재한다라는 의미는 해당 원소가 메모리 상에서 존재한다 라는
	// 의미와 같다.하지만 레퍼런스는 특별한 경우가 아닌 이상 메모리 상에서
	// 공간을 차지 하지 않는다.따라서 이러한 모순 때문에 레퍼런스들의 배열을
	// 정의하는 것은 언어 차원에서 금지가 되어 있는 것입니다.

	// ※ 하지만 배열들의 레퍼런스가 불가능 한 것은 아니다.
	int arr[3] = { 1, 2, 3 };
	int(&ref)[3] = arr;

	ref[0] = 4;
	ref[1] = 5;
	ref[2] = 6;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;

	int arr2[3][2] = { 1, 2, 3, 4, 5, 6 };
	int(&ref)[3][2] = arr2;
}
#endif // false

// 레퍼런스를 리턴하는 함수
#if false
int function()
{
	int a = 2;
	return a;
}

int main()
{
	int b = function();
	return 0;
}
#endif // false

#if false
// 지역변수의 레퍼런스 리턴
int& function() 
{
	int a = 2;
	return a;
}

int main() 
{
	// function의 리턴타입은 int& 이다. 따라서 참조자를 리턴하게 된다.
	// 그러나 문제는 리턴하는 function 안에 정의되어 있는 a는 함수의 리턴과 함께 사라진다.
	int b = function();

	// 즉
	// int& ref = a;
	// a 가 사라짐
	//int b = ref;
	// 와 같다. 레퍼런스는 있는데 원래 참조 하던 것이 사라진 레퍼런스를 댕글링 레퍼런스(Dangling Reference)라고 부른다.
	// Dangling의 원래 뜻 : 달랑달랑, 레퍼런스가 참조해야 할 변수가 사라져서 혼자서 덩그러니 남아 있는 상황과 유사하다.

	b = 3;
	return 0;
}
#endif // false

// 외부 변수의 레퍼런스를 리턴
#if false
int& function(int& a)
{
	int a = 5;
	return a;
}

int main()
{
	int b = 2;
	int c = function(b);
	return 0;
}
#endif // true

// 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
#if true
int function()
{
	int a = 5;
	return a;
}

int main()
{
	// int& c = function(); => Dangling Reference

	// 원칙상 함수의 리턴값은 해당 문장이 끝나면 소멸되는 것이 정상이다.
	// 따라서 기존에 int& 로 받았을 때에는 컴파일 자체가 안되었습니다.
	// 하지만 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의
	// 생명이 연장됩니다.그리고 그 연장되는 기간은 레퍼런스가 사라질 때 까지 입니다.
	const int& c = function();
	std::cout << "c : " << c << std::endl;

	return 0;
}
#endif // true
