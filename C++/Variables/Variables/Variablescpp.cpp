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

	// 변수의 이름만 보았을 때 무엇을 하는지 확실히 알 수 있어야 함
	int number_of_people;
	double interest_rate;

	// C에서 *와 &가 하였던 역할을 C++에서도 그대로 사용
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

	std::cout << "합은 : " << sum << std::endl;
#pragma endregion

#pragma region While
	int j = 1, sum2 = 0;

	while (j <= 10) {
		sum2 += j;
		j++;
	}

	std::cout << "합은 : " << sum2 << std::endl;
#pragma endregion
	
#pragma region If ~ Else
	int lucky_number = 7;
	std::cout << "행운의 숫자를 맞추어 보세요!" << std::endl;

	int user_input;

	while (1) {
		std::cout << "입력 : ";
		std::cin >> user_input; // 사용자의 입력

		if (lucky_number == user_input)
		{
			std::cout << "행운의 숫자" + lucky_number << "를 맞추셨습니다!" << std::endl;
			break;
		}
		else
		{
			std::cout << "틀렸습니다! 다시 생각해 보세요." << std::endl;
		}
	}
#pragma endregion

#pragma region Switch
	int user_input2;
	
	cout << "나의 정보를 표시한다." << endl;
	cout << "1. 이름" << endl;
	cout << "2. 나이" << endl;
	cout << "3. 성별" << endl;
	cin >> user_input2;

	switch (user_input2) 
	{
		case 1:
			cout << "KyungHoon!" << endl;
			break;

		case 2:
			cout << "18살" << endl;

		case 3:
			cout << "남자" << endl;

		default:
			cout << "궁금한게 없는가 봐요" << endl;
			break;
	}
#pragma endregion


	return 0;
}