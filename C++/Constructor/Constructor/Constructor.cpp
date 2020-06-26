#include <iostream>

#pragma region Constructor
class Date 
{
	int year;
	int month; // 1 ~ 12
	int day; // 1 ~ 31

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	// �ش� ���� �� �� ���� ���Ѵ�.
	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();

	// ������
	Date(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
};

void Date::AddYear(int inc)
{
	year += inc;
}

void Date::ShowDate()
{
	std::cout << "������ " << year << "�� " << month << "�� " << day << "�� �Դϴ�." << std::endl;
}

int main()
{
	Date day(2011, 3, 1); // �����ڸ� ���� �ʱ�ȭ 1 : �Ͻ��� ���
	Date day2 = Date(2012, 3, 1); // �����ڸ� ���� �ʱ�ȭ 2 : ����� ���

	day.ShowDate();
	day2.ShowDate();

	day.AddYear(10);
	day.ShowDate();

	day2.AddYear(10);
	day2.ShowDate();

	return 0;
}
#pragma endregion
