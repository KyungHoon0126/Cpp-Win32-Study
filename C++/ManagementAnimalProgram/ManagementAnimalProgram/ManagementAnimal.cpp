#include <iostream>

// 간단한 동물 관리 프로그램
#if true

#define PET_LIMIT 10

// Animal Struct 선언
typedef struct Animal
{
    char kind[30]; // 종류
    char name[30];  // 이름
    int age;        // 나이

    int health;  // 체력
    int food;    // 배부름
    int clean;   // 깨끗함
} Animal; // struct Animal을 Animal로 사용

// 동물 생성
void create_animal(Animal* animal)
{
    std::cout << "동물의 종류? ";
    std::cin >> animal->kind;

    std::cout << "동물의 이름? ";
    std::cin >> animal->name;

    std::cout << "동물의 나이? ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

// 놀기
void play(Animal* animal)
{
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

// 밥주기
void feed(Animal* animal)
{
    animal->food += 50;
}

// 목욕하기
void wash(Animal* animal)
{
    animal->clean += 50;
}

// 하루가 지남
void one_day_pass(Animal* animal)
{
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

// 동물 상태
void show_stat(Animal* animal)
{
    std::cout << animal->name << "의 현재 상태" << std::endl;
    std::cout << "체력    : " << animal->health << std::endl;
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결    : " << animal->clean << std::endl;
}

// 동물 리스트
void show_pet_list(int animal_cnt, Animal* animal[10])
{
    for (int i = 0; i != animal_cnt; i++)
    {
        std::cout << animal[i]->name << " : " << "[" << i << "]";
        std::cout << ", ";
    }

    std::cout << std::endl;
}

int main()
{
    Animal* list[PET_LIMIT];
    int animal_num = 0;

    for (;;)
    {
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기 " << std::endl;
        std::cout << "3. 밥주기 " << std::endl;
        std::cout << "4. 목욕하기 " << std::endl;
        std::cout << "5. 상태 보기 " << std::endl;

        // User Command
        int input;
        std::cin >> input;

        switch (input)
        {
            // int play_with;
            int do_with;

        case 1:
            list[animal_num] = new Animal;
            create_animal(list[animal_num]);
            animal_num++;
            break;

        case 2:
            std::cout << "누구랑 놀래? : ";
            show_pet_list(animal_num, list);
            std::cin >> do_with;

            if (do_with < animal_num)
            {
                play(list[do_with]);
                show_stat(list[do_with]);
            }
            break;

        case 3:
            std::cout << "누구에게 밥을 줄래? : ";
            show_pet_list(animal_num, list);
            std::cin >> do_with;

            if (do_with < animal_num)
            {
                feed(list[do_with]);
                show_stat(list[do_with]);
            }
            break;

        case 4:
            std::cout << "누구를 목욕시킬래? : ";
            show_pet_list(animal_num, list);
            std::cin >> do_with;

            if (do_with < animal_num)
            {
                wash(list[do_with]);
                show_stat(list[do_with]);
            }
            break;

        case 5:
            std::cout << "누구의 상태를 볼래? : ";
            show_pet_list(animal_num, list);
            std::cin >> do_with;

            if (do_with < animal_num)
            {
                show_stat(list[do_with]);
                show_stat(list[do_with]);
            }
            break;
        }

        for (int i = 0; i != animal_num; i++)
        {
            one_day_pass(list[i]);
        }
    }

    // 메모리 해제
    for (int i = 0; i != animal_num; i++)
    {
        delete list[i];
    }
}
#endif // true