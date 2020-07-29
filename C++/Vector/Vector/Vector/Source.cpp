#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
						  2, 6, 7, 8, 5, 6, 2, 6, 7, 4,
						  5, 7, 8, 5, 3, 5, 4, 6, 4, 6,
						  2, 1, 34, 5, 6, 5, 2, 4 , 6 };

	// ������ ����
	array.push_back(1);

	// ������ ����(�� �������� ���� �� ����)
	array.pop_back();

	// ������ ���� �ε��� ����
	// array.insert(2, 22);

	// push_back ���� �迭 ���·� �� ���� ����
	int SIZE = 5;
	vector<int> iVec(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		iVec[i] = i * 10;
	}

	// erase : ������ ���� �ε��� ����
	array.erase(array.begin() + 5); // array.begin()�� 0�� ��� 5��° �ε��� ����

	// array.begin() ~ array.begin() + 3 �� 0 ~ 3�� ° �ε��� ����
	array.erase(array.begin(), array.begin() + 3);

	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << std::endl;
	}
}