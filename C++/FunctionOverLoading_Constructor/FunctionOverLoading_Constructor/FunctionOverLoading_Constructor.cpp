#include <iostream>

#if false
void print(int x)
{
	std::cout << "int : " << x << std::endl;
}

void print(char x)
{
	std::cout << "char : " << x << std::endl;
}

void print(double x)
{
	std::cout << "double : " << x << std::endl;
}

int main()
{
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);
}
#endif // false

#if true
void print(int x)
{
	std::cout << "int : " << x << std::endl;
}

void print(double x)
{
	std::cout << "double : " << x << std::endl;
}

int main()
{
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);
}
#endif // true

#pragma region C++ �����ε� ��Ģ
// 1 �ܰ� : �ڽŰ� Ÿ���� ��Ȯ�� ��ġ�ϴ� �Լ��� ã�´�.

// 2 �ܰ� : ��Ȯ�� ��ġ�ϴ� Ÿ���� ���� ��� �Ʒ��� ���� ����ȯ�� ���ؼ� ��ġ�ϴ�
//         �Լ��� ã�ƺ���.

// Char, unsigned char, short �� int �� ��ȯ�ȴ�.
// Unsigned short �� int �� ũ�⿡ ���� int Ȥ�� unsigned int �� ��ȯ�ȴ�.
// Float �� double �� ��ȯ�ȴ�.
// Enum �� int �� ��ȯ�ȴ�.

// 3 �ܰ�
// ���� ���� ��ȯ�ص� ��ġ�ϴ� ���� ���ٸ� �Ʒ��� ���� �������� ����ȯ�� ���� ��ġ�ϴ� �Լ��� ã�´�.
// ������ ����(numeric) Ÿ���� �ٸ� ���� Ÿ������ ��ȯ�ȴ�. (���� ��� float -> int)
// Enum �� ������ ���� Ÿ������ ��ȯ�ȴ�(���� ��� Enum -> double)
// 0 �� ������ Ÿ���̳� ���� Ÿ������ ��ȯ�� 0 �� ������ Ÿ���̳� ���� Ÿ������ ��ȯ�ȴ�
// �����ʹ� void �����ͷ� ��ȯ�ȴ�.

// 4 �ܰ�
// ���� ���ǵ� Ÿ�� ��ȯ���� ��ġ�ϴ� ���� ã�´�.
// ���࿡ �����Ϸ��� �� ������ ���ϴ��� ��ġ�ϴ� �Լ��� ã�� �� ���ų�
// ���� �ܰ迡�� �� �� �̻��� ��ġ�ϴ� ��쿡 ��ȣ�ϴ�(ambiguous) ��� �Ǵ��ؼ� 
// ������ �߻��ϰ� �˴ϴ�.
#pragma endregion

