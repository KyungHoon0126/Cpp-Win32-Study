#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
#pragma region Variables
	// int i;
	char c;
	double d;
	float f;

	// ������ �̸��� ������ �� ������ �ϴ��� Ȯ���� �� �� �־�� ��
	int number_of_people;
	double interest_rate;

	// C���� *�� &�� �Ͽ��� ������ C++������ �״�� ���
	int arr[10];
	int* parr = arr;

	int i;
	int* pi = &i;
#pragma endregion

#pragma region For
	for (i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
	}

	int sum = 0;

	for (i = 1; i <= 10; i++)
	{
		sum += i;
	}

	std::cout << "���� : " << sum << std::endl;
#pragma endregion

#pragma region While
	int j = 1, sum2 = 0;

	while (j <= 10) {
		sum2 += j;
		j++;
	}

	std::cout << "���� : " << sum2 << std::endl;
#pragma endregion
	
#pragma region If ~ Else
	int lucky_number = 7;
	std::cout << "����� ���ڸ� ���߾� ������!" << std::endl;

	int user_input;

	while (1) {
		std::cout << "�Է� : ";
		std::cin >> user_input; // ������� �Է�

		if (lucky_number == user_input)
		{
			std::cout << "����� ����" + lucky_number << "�� ���߼̽��ϴ�!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Ʋ�Ƚ��ϴ�! �ٽ� ������ ������." << std::endl;
		}
	}
#pragma endregion

#pragma region Switch
	int user_input2;
	
	cout << "���� ������ ǥ���Ѵ�." << endl;
	cout << "1. �̸�" << endl;
	cout << "2. ����" << endl;
	cout << "3. ����" << endl;
	cin >> user_input2;

	switch (user_input2) 
	{
		case 1:
			cout << "KyungHoon!" << endl;
			break;

		case 2:
			cout << "18��" << endl;

		case 3:
			cout << "����" << endl;

		default:
			cout << "�ñ��Ѱ� ���°� ����" << endl;
			break;
	}
#pragma endregion


	return 0;
}