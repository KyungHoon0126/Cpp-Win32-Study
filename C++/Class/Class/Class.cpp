#include <iostream>

class Animal
{
#pragma region ��� ����, ��� �Լ�
private:
	int food;
	int weight;

public:
	void set_animal(int food, int weight)
	{
		this->food = food;
		this->weight = weight;
	}

	void increase_food(int inc)
	{
		food += inc;
		weight += (inc / 3);
	}

	void view_stat()
	{
		std::cout << "�� ������ food : " << food << std::endl;
		std::cout << "�� ������ weight : " << weight << std::endl;
	}
#pragma endregion
};

int main()
{
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}