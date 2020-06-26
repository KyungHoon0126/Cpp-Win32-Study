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

#if false
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
#endif // false

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

#pragma region Date Class(Date Ŭ����)
// Q : SetDate �� ���״�� Date �Լ� ���θ� �ʱ�ȭ �ϴ� ���̰�
//	   AddDay, AddMonth, AddYear �� ��, ��, ���� ���ϴ� ��ŭ ���ϰ� �ȴ�.
//	   �� ���� ������ ���� ���� 2012 �� 2 �� 28 �Ͽ� 3 ���� ���ϸ� 
//     2012 �� 2 �� 31 ���� �Ǵ� ���� �ƴ϶� 2012 �� 3 �� 2 ���� �ȴ�.

#if false 
// Date:: �� �Լ� �̸� �տ� �ٿ��ְ� �Ǹ� �� �Լ��� "Date Ŭ������ ���ǵ� �Լ�"��� �ǹ�
// Date:: �� ������ Ŭ������ ��� �Լ��� �ƴ϶� �׳� �Ϲ����� �Լ��� �ȴ�.
class Date
{
	int year;
	int month; // 1���� 12����
	int day; // 1���� 31����
	
public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	// �ش� ���� �� �� ���� ���Ѵ�.
	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();
};

void Date::SetDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
	static int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month != 2)
	{
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		return 29; // ����
	}
	else
	{
		return 28;
	}
}

void Date::AddDay(int inc)
{
	while (true)
	{
		// ���� ���� �� �� ��
		int currnet_month_total_days = GetCurrentMonthTotalDays(year, month);

		// ���� �� �ȿ� ���´ٸ�
		if (day + inc <= currnet_month_total_days)
		{
			day += inc;
			return;
		}
		else
		{
			// �����޷� �Ѿ�� �Ѵ�.
			inc -= (currnet_month_total_days - day + 1);
			day = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc)
{
	AddYear((inc + month - 1) / 12);
	month = month + inc % 12;
	month = (month == 12 ? 12 : month % 12);
}

void Date::AddYear(int inc)
{
	year += inc;
}

void Date::ShowDate()
{
	std::cout << "������ " << year << "��" << month << "��" << day << "�� �Դϴ�." << std::endl;
}

int main()
{
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31); // ����
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();

	return 0;
}
#endif // false
#pragma endregion
