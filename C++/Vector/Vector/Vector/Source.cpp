#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
						  2, 6, 7, 8, 5, 6, 2, 6, 7, 4,
						  5, 7, 8, 5, 3, 5, 4, 6, 4, 6,
						  2, 1, 34, 5, 6, 5, 2, 4 , 6 };

	// 데이터 삽입
	array.push_back(1);

	// 데이터 삭제(맨 마지막에 들어갔던 값 삭제)
	array.pop_back();

	// 데이터 지정 인덱스 삽입
	// array.insert(2, 22);

	// push_back 없이 배열 상태로 값 삽입 가능
	int SIZE = 5;
	vector<int> iVec(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		iVec[i] = i * 10;
	}

	// erase : 데이터 지정 인덱스 삭제
	array.erase(array.begin() + 5); // array.begin()이 0인 경우 5번째 인덱스 제거

	// array.begin() ~ array.begin() + 3 즉 0 ~ 3번 째 인덱스 제거
	array.erase(array.begin(), array.begin() + 3);

	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << std::endl;
	}
}