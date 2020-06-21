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

#if true
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
