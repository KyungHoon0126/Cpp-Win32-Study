#include <iostream>

// ������ ���� ���� ���α׷�
#if true

#define PET_LIMIT 10

// Animal Struct ����
typedef struct Animal
{
    char kind[30]; // ����
    char name[30];  // �̸�
    int age;        // ����

    int health;  // ü��
    int food;    // ��θ�
    int clean;   // ������
} Animal; // struct Animal�� Animal�� ���

// ���� ����
void create_animal(Animal* animal)
{
    std::cout << "������ ����? ";
    std::cin >> animal->kind;

    std::cout << "������ �̸�? ";
    std::cin >> animal->name;

    std::cout << "������ ����? ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

// ���
void play(Animal* animal)
{
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

// ���ֱ�
void feed(Animal* animal)
{
    animal->food += 50;
}

// ����ϱ�
void wash(Animal* animal)
{
    animal->clean += 50;
}

// �Ϸ簡 ����
void one_day_pass(Animal* animal)
{
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

// ���� ����
void show_stat(Animal* animal)
{
    std::cout << animal->name << "�� ���� ����" << std::endl;
    std::cout << "ü��    : " << animal->health << std::endl;
    std::cout << "��θ� : " << animal->food << std::endl;
    std::cout << "û��    : " << animal->clean << std::endl;
}

// ���� ����Ʈ
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
        std::cout << "1. ���� �߰��ϱ�" << std::endl;
        std::cout << "2. ��� " << std::endl;
        std::cout << "3. ���ֱ� " << std::endl;
        std::cout << "4. ����ϱ� " << std::endl;
        std::cout << "5. ���� ���� " << std::endl;

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
            std::cout << "������ �? : ";
            show_pet_list(animal_num, list);
            std::cin >> do_with;

            if (do_with < animal_num)
            {
                play(list[do_with]);
                show_stat(list[do_with]);
            }
            break;

        case 3:
            std::cout << "�������� ���� �ٷ�? : ";
            show_pet_list(animal_num, list);
            std::cin >> do_with;

            if (do_with < animal_num)
            {
                feed(list[do_with]);
                show_stat(list[do_with]);
            }
            break;

        case 4:
            std::cout << "������ ����ų��? : ";
            show_pet_list(animal_num, list);
            std::cin >> do_with;

            if (do_with < animal_num)
            {
                wash(list[do_with]);
                show_stat(list[do_with]);
            }
            break;

        case 5:
            std::cout << "������ ���¸� ����? : ";
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

    // �޸� ����
    for (int i = 0; i != animal_num; i++)
    {
        delete list[i];
    }
}
#endif // true