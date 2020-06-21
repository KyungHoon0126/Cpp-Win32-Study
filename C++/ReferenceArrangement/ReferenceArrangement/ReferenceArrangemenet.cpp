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
#if true
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
#endif // true