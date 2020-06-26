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

#pragma region C++ 오버로딩 규칙
// 1 단계 : 자신과 타입이 정확히 일치하는 함수를 찾는다.

// 2 단계 : 정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는
//         함수를 찾아본다.

// Char, unsigned char, short 는 int 로 변환된다.
// Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.
// Float 은 double 로 변환된다.
// Enum 은 int 로 변환된다.

// 3 단계
// 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.
// 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)
// Enum 도 임의의 숫자 타입으로 변환된다(예를 들어 Enum -> double)
// 0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다
// 포인터는 void 포인터로 변환된다.

// 4 단계
// 유저 정의된 타입 변환으로 일치하는 것을 찾는다.
// 만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나
// 같은 단계에서 두 개 이상이 일치하는 경우에 모호하다(ambiguous) 라고 판단해서 
// 오류를 발생하게 됩니다.
#pragma endregion

#pragma region Date Class(Date 클래스)
// Q : SetDate 는 말그대로 Date 함수 내부를 초기화 하는 것이고
//	   AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 된다.
//	   한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 
//     2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 된다.

#if false 
// Date:: 를 함수 이름 앞에 붙여주게 되면 이 함수가 "Date 클래스의 정의된 함수"라는 의미
// Date:: 가 없으면 클래스의 멤버 함수가 아니라 그냥 일반적인 함수가 된다.
class Date
{
	int year;
	int month; // 1부터 12까지
	int day; // 1부터 31까지
	
public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	// 해당 월의 총 일 수를 구한다.
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
		return 29; // 윤년
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
		// 현재 달의 총 일 수
		int currnet_month_total_days = GetCurrentMonthTotalDays(year, month);

		// 같은 달 안에 들어온다면
		if (day + inc <= currnet_month_total_days)
		{
			day += inc;
			return;
		}
		else
		{
			// 다음달로 넘어가야 한다.
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
	std::cout << "오늘은 " << year << "년" << month << "월" << day << "일 입니다." << std::endl;
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

	day.SetDate(2012, 1, 31); // 윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();

	return 0;
}
#endif // false
#pragma endregion
