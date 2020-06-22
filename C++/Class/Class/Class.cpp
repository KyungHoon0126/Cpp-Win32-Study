#include <iostream>

class Animal
{
#pragma region 멤버 변수, 멤버 함수
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
		std::cout << "이 동물의 food : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
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