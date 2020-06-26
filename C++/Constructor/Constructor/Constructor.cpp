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

	// 해당 월의 총 일 수를 구한다.
	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();

	// 생성자
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
	std::cout << "오늘은 " << year << "년 " << month << "월 " << day << "일 입니다." << std::endl;
}

int main()
{
	Date day(2011, 3, 1); // 생성자를 통한 초기화 1 : 암시적 방법
	Date day2 = Date(2012, 3, 1); // 생성자를 통한 초기화 2 : 명시적 방법

	day.ShowDate();
	day2.ShowDate();

	day.AddYear(10);
	day.ShowDate();

	day2.AddYear(10);
	day2.ShowDate();

	return 0;
}
#pragma endregion
