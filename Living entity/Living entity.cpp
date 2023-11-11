#include <iostream>
#include <string>
#include <Windows.h>
#include <string.h>
#define size 10
using namespace std;

enum struct LivingType
{
    bird,
    livestock,
    human
};

struct Characteristic
{
    double speedOfBird;
    bool livestockYorN;
    int IQ;
};

struct LivingEntity
{
    double speed;
    LivingType type;
    string colour;
    Characteristic character;
};

void input(LivingEntity& entity)
{
    int type;
    cout << "Введите тип сущности (0 - птица, 1 - скот, 2 - человек): ";
    cin >> type;
    entity.type = LivingType(type);
    cout << "Введите скорость: ";
    cin >> entity.speed;
    cout << "Введите цвет: ";
    cin >> entity.colour;
    
    string True;

    switch (entity.type)
    {
    case LivingType::bird:
        cout << "Введите скорость полета: ";
        cin >> entity.character.speedOfBird;
        break;
    case LivingType::livestock:
        cout << "Парнокопытное: Да/Нет" << endl;
        cin >> True;
        if (True == "Да" || "да")
        {
            entity.character.livestockYorN = true;
        }
        else if (True == "Нет" || "нет")
        {
            entity.character.livestockYorN = false;
        }
        break;
    case LivingType::human:
        cout << "Введите уровень IQ: " << endl;
        cin >> entity.character.IQ;
        break;
    }
}

void print(LivingEntity& entity)
{
    switch (entity.type)
    {
    case LivingType::bird:
        cout << "Птица:" << endl << "Скорость полёта птички: " << entity.character.speedOfBird << endl;
        break;
    case LivingType::livestock:
        cout << "Скот: " << endl << "Скот является ли Парнокопытным: Да/Нет  " << (entity.character.livestockYorN ? "Да":"Нет") << endl;
        break;
    case LivingType::human:
        cout << "Человек: " << endl << "Уровень IQ у человека: " << entity.character.IQ << endl;
        break;
    }
    cout << "Cкорость передвижения: " << entity.speed << endl;
    cout << "Цвет: " << entity.colour << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    LivingEntity entity[size];
    for (int i = 0; i < size; i++)
    {
        input(entity[i]);
    }
    for (int i = 0; i < size; i++)
    {
        print(entity[i]);
        cout << endl;
    }

    
    
}
