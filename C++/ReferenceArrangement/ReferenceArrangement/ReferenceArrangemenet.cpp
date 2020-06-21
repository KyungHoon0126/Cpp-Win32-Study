#include <iostream>

// ������(Pointer)
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

// ������(���۷��� - reference)
#if false
int main() 
{
	// �����ڸ� ���ϴ� ����� ����Ű���� �ϴ� Ÿ�� �ڿ� & �� ���̸� �ȴ�.
	// ������ Ÿ���� �����ڸ� ������� int*&�� ���� �ȴ�.
	
	// �� ���۷����� �ݵ�� ó���� ������ ������ �� ������ �����ؾ� �Ѵ�.
	// C���� ������ int *p�� ���������� int& another_a(������)�� ���� �����ϴ� ���� �Ұ���.
	// ���� �� �� ������ �Ǹ� ����� �ٸ� ���� ������ �� �� ����.

	int a = 3;
	int& another_a = a; // a�� ������ another_a, another_a�� a�� �Ǵٸ� �̸�, �� another_a�� �۾��� �����ϸ� a�� �۾��� �ϴ� �Ͱ� ����.

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
}
#endif // false

#if false
// �Լ� ���ڷ� ���۷��� �ޱ�
int change_val(int& p)
{
	p = 3;
	return 0;
}

int main()
{
	int number = 5;

	std::cout << number << std::endl;
	// int& p �� �ȵȴٰ� ���� �ʾҳ� ?
	// �׷��� p �� ���ǵǴ� ������ change_val(number)�� ȣ���� �� �̹Ƿ�
	// ��ǻ� int& p = number �� ����ȴٰ� �����ϸ� �ȴ�.
	change_val(number);
	std::cout << number << std::endl;
}
#endif // true

// �������� ������ ����
#if false
int main()
{
	int x;
	int& y = x;
	int& z = y;

	// x, ������ y, ������ z �� ���� 1�� �����ϴ�.
	// �� ������, y�� z�� x�� �������̹Ƿ� x�� ���� �����ϴ� ���̳� y or z�� ���� �����ϴ� �Ͱ� ���� �����̴�.
	x = 1;
	std::cout << "x : " << x << " y :" << y << " z : " << z << std::endl;

	// ���� �����ϰ� ���� ���ϴ� ������ �۵��Ѵ�.
	y = 2;
	std::cout << "x : " << x << " y :" << y << " z : " << z << std::endl;
	
	// ���� �����ϰ� ���� ���ϴ� ������ �۵��Ѵ�.
	z = 3;
	std::cout << "x : " << x << " y :" << y << " z : " << z << std::endl;
}

#endif // false

// ����� ���� ������
#if false
int main()
{
	// ��� �� ��ü�� ���ͷ� �̱� ������ ���� �Ұ�
	// int& ref = 4;

	// std::cout << ref << std::endl;

	// ��� �����ڷ� �����Ѵٸ� ���ͷ��� ���� ����
	const int& ref = 4;

	int a = ref; // a = 4;

	std::cout << ref << std::endl;
}
#endif // false

// ���۷����� �迭�� �迭�� ���۷���
#if false
int main()
{
	// ���۷����� �迭�� �ҹ��̶�� �����ִ�.
	// int a, b;
	// int& arr[2] = { a, b };

	// �׷��� �ּҰ��� �����Ѵٶ�� �ǹ̴� �ش� ���Ұ� �޸� �󿡼� �����Ѵ� ���
	// �ǹ̿� ����.������ ���۷����� Ư���� ��찡 �ƴ� �̻� �޸� �󿡼�
	// ������ ���� ���� �ʴ´�.���� �̷��� ��� ������ ���۷������� �迭��
	// �����ϴ� ���� ��� �������� ������ �Ǿ� �ִ� ���Դϴ�.

	// �� ������ �迭���� ���۷����� �Ұ��� �� ���� �ƴϴ�.
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

// ���۷����� �����ϴ� �Լ�
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
// ���������� ���۷��� ����
int& function() 
{
	int a = 2;
	return a;
}

int main() 
{
	// function�� ����Ÿ���� int& �̴�. ���� �����ڸ� �����ϰ� �ȴ�.
	// �׷��� ������ �����ϴ� function �ȿ� ���ǵǾ� �ִ� a�� �Լ��� ���ϰ� �Բ� �������.
	int b = function();

	// ��
	// int& ref = a;
	// a �� �����
	//int b = ref;
	// �� ����. ���۷����� �ִµ� ���� ���� �ϴ� ���� ����� ���۷����� ��۸� ���۷���(Dangling Reference)��� �θ���.
	// Dangling�� ���� �� : �޶��޶�, ���۷����� �����ؾ� �� ������ ������� ȥ�ڼ� ���׷��� ���� �ִ� ��Ȳ�� �����ϴ�.

	b = 3;
	return 0;
}
#endif // false

// �ܺ� ������ ���۷����� ����
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

// �����ڰ� �ƴ� ���� �����ϴ� �Լ��� �����ڷ� �ޱ�
#if true
int function()
{
	int a = 5;
	return a;
}

int main()
{
	// int& c = function(); => Dangling Reference

	// ��Ģ�� �Լ��� ���ϰ��� �ش� ������ ������ �Ҹ�Ǵ� ���� �����̴�.
	// ���� ������ int& �� �޾��� ������ ������ ��ü�� �ȵǾ����ϴ�.
	// ������ ���������� ��� ���۷����� ���ϰ��� �ް� �Ǹ� �ش� ���ϰ���
	// ������ ����˴ϴ�.�׸��� �� ����Ǵ� �Ⱓ�� ���۷����� ����� �� ���� �Դϴ�.
	const int& c = function();
	std::cout << "c : " << c << std::endl;

	return 0;
}
#endif // true
