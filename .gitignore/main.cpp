#include <iostream>
#include <locale>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <windows.h>

using namespace std;

class garage
{
public:
    garage() {}
    virtual void set_mark()=0;      ///Установка марки транспорта
    virtual void get_mark()=0;      ///Получение марки транспорта
    virtual void set_model()=0;     ///Установка модели транспорта
    virtual void get_model()=0;     ///Получение модели транспорта
    virtual ~garage()=0;
};
garage::~garage(){}

class car : public garage
{
private:
    char car_mark[20];
    char car_model[20];
    int car_engine;
    char car_color[15];
    char car_kpp[15];
public:
	car(){}
    void set_mark()         ///МАРКА АВТОМОБИЛЯ
    {
        cout<<"Введите марку автомобиля: ";     gets(car_mark);
    }
    void get_mark()
    {
        for(int i=0; i<strlen(car_mark); i++)
            cout<<car_mark[i];
        cout<<" ";
    }
    void set_model()         ///МОДЕЛЬ АВТОМОБИЛЯ
    {
        cout<<"Введите модель автомобиля: ";    gets(car_model);
    }
    void get_model()
    {
        for(int i=0; i<strlen(car_model); i++)
            cout<<car_model[i];
        cout<<". ";
    }
    void set_car_engine()         ///ОБЪЕМ ДВИЖКА АВТОМОБИЛЯ
    {
        cout<<"Введите объем двигателя автомобиля: ";   cin>>car_engine;    getchar();
    }
    void get_car_engine()
    {
        cout<<"Объем двигателя - "<<car_engine<<" л. ";
    }
    void set_color()         ///ЦВЕТ АВТОМОБИЛЯ
    {
        cout<<"Введите цвет автомобиля: ";      gets(car_color);
    }
    void get_color()
    {
        cout<<"Цвет - ";
        for(int i=0; i<strlen(car_color); i++)
            cout<<car_color[i];
        cout<<". ";
    }
    void set_kpp()         ///КОРОБКА ПЕРЕДАЧ АВТОМОБИЛЯ
    {
        cout<<"Введите тип КПП автомобиля: ";       gets(car_kpp);
    }
    void get_kpp()
    {
        cout<<"Коробка передач - ";
        for(int i=0; i<strlen(car_kpp); i++)
            cout<<car_kpp[i];
        cout<<". ";
    }

    ~car() override{};
};

class motorbike : public garage
{
private:
    char motorbike_mark[20];
    char motorbike_model[20];
    int motorbike_engine;
    int motorbike_power;
    char motorbike_terrain[20];
public:
	motorbike(){}
    void set_mark()         ///МАРКА МОТОЦИКЛА
    {
        cout<<"Введите марку мотоцикла: ";          gets(motorbike_mark);
    }
    void get_mark()
    {
        for(int i=0; i<strlen(motorbike_mark); i++)
            cout<<motorbike_mark[i];
        cout<<" ";
    }
    void set_model()         ///МОДЕЛЬ МОТОЦИКЛА
    {
        cout<<"Введите модель мотоцикла: ";         gets(motorbike_model);
    }
    void get_model()
    {
        for(int i=0; i<strlen(motorbike_model); i++)
            cout<<motorbike_model[i];
        cout<<". ";
    }
    void set_moto_engine()         ///ОБЪЕМ ДВИЖКА МОТОЦИКЛА
    {
        cout<<"Введите объем двигателя мотоцикла: ";       cin>>motorbike_engine;      getchar();
    }
    void get_moto_engine()
    {
        cout<<"Объем двигателя - "<<motorbike_engine<<" л. ";
    }
    void set_power()         ///МОЩНОСТЬ МОТОЦИКЛА
    {
        cout<<"Введите мощность двигателя мотоцикла: ";
        cin>>motorbike_power;
        getchar();
    }
    void get_power()
    {
        cout<<"Мощность - "<<motorbike_power<<" л.с. ";
    }
    void set_terrain()         ///МЕСТНОСТЬ ДЛЯ МОТОЦИКЛА
    {
        cout<<"Введите для какой местности мотоцикл: ";
        gets(motorbike_terrain);
    }
    void get_terrain()
    {
        cout<<"Для ";
        for(int i=0; i<strlen(motorbike_terrain); i++)
            cout<<motorbike_terrain[i];
        cout<<" местности.";
    }

    ~motorbike() override{};
};

class bus : public garage
{
private:
    char bus_mark[20];
    char bus_model[20];
    int bus_seats;
    int bus_all_passengers;
    char final_destination[20];
public:
	bus(){}
    void set_mark()         ///МАРКА АВТОБУСА
    {
        cout<<"Введите марку автобуса: ";       gets(bus_mark);
    }
    void get_mark()
    {
        for(int i=0; i<strlen(bus_mark); i++)
            cout<<bus_mark[i];
        cout<<" ";
    }
    void set_model()         ///МОДЕЛЬ АВТОБУСА
    {
        cout<<"Введите модель автобуса: ";      gets(bus_model);
    }
    void get_model()
    {
        for(int i=0; i<strlen(bus_model); i++)
            cout<<bus_model[i];
        cout<<". ";
    }
    void set_seats()         ///СИДЯЧИЕ МЕСТА В АВТОБУСЕ
    {
        cout<<"Введите количество сидячих мест в автобусе: ";   cin>>bus_seats;     getchar();
    }
    void get_seats()
    {
        cout<<"Сидячих мест - "<<bus_seats<<". ";
    }
    void set_all_passengers()         ///ОБЩЕЕ КОЛ-ВО МЕСТ В АВТОБУСЕ
    {
        cout<<"Введите общее кол-во мест в автобусе: ";     cin>>bus_all_passengers;    getchar();
    }
    void get_all_passengers()
    {
        cout<<"Всего мест - "<<bus_all_passengers<<". ";
    }
    void set_destination()         ///КОНЕЧНЫЙ ПУНКТ
    {
        cout<<"Введите название конечного пункта: ";    gets(final_destination);
    }
    void get_destination()
    {
        cout<<"Конечная остановка - ";
        for(int i=0; i<strlen(final_destination); i++)
            cout<<final_destination[i];
        cout<<". ";
    }


    ~bus() override{};
};

int main()
{
    setlocale(LC_ALL, "Rus");
    car car_mas[20];
    motorbike moto_mas[20];
    bus bus_mas[20];
    int choise1, choise2;
    int car_count=0, moto_count=0, bus_count=0;
    while(1)
    {
        cout<<"Вы в гараже, выберите транспорт:\n1)Машина\t"<<car_count<<"\n2)Мотоцикл\t"<<moto_count<<"\n3)Автобус\t"<<bus_count<<"\n0)Выйти\n>";
        cin>>choise1;
        switch(choise1)
        {
        case 1:         ///МАШИНЫ
            {
                cout<<"1)Записать в базу\n2)Вывести на экран\n>";
                cin>>choise2;
                getchar();
                switch(choise2)
                {
                case 1:
                    car_mas[car_count].set_mark();
                    car_mas[car_count].set_model();
                    car_mas[car_count].set_car_engine();
                    car_mas[car_count].set_color();
                    car_mas[car_count].set_kpp();
                    car_count++;
                    break;
                case 2:
                    for(int j=0; j<car_count; j++)
                    {
                        car_mas[j].get_mark();
                        car_mas[j].get_model();
                        car_mas[j].get_car_engine();
                        car_mas[j].get_color();
                        car_mas[j].get_kpp();
                        cout<<endl;
                    }
                    system("pause");
                    break;
                }
            }
            break;
        case 2:         ///МОТОЦИКЛЫ
            {
                cout<<"1)Записать в базу\n2)Вывести на экран\n>";
                cin>>choise2;
                getchar();
                switch(choise2)
                {
                case 1:
                    moto_mas[moto_count].set_mark();
                    moto_mas[moto_count].set_model();
                    moto_mas[moto_count].set_moto_engine();
                    moto_mas[moto_count].set_power();
                    moto_mas[moto_count].set_terrain();
                    moto_count++;
                    break;
                case 2:
                    for(int j=0; j<moto_count; j++)
                    {
                        moto_mas[j].get_mark();
                        moto_mas[j].get_model();
                        moto_mas[j].get_moto_engine();
                        moto_mas[j].get_power();
                        moto_mas[j].get_terrain();
                        cout<<endl;
                    }
                    system("pause");
                    break;
                }
            }
            break;
        case 3:         ///АВТОБУСЫ
            {
                cout<<"1)Записать в базу\n2)Вывести на экран\n>";
                cin>>choise2;
                getchar();
                switch(choise2)
                {
                case 1:
                    bus_mas[bus_count].set_mark();
                    bus_mas[bus_count].set_model();
                    bus_mas[bus_count].set_seats();
                    bus_mas[bus_count].set_all_passengers();
                    bus_mas[bus_count].set_destination();
                    bus_count++;
                    break;
                case 2:
                    for(int j=0; j<bus_count; j++)
                    {
                        bus_mas[j].get_mark();
                        bus_mas[j].get_model();
                        bus_mas[j].get_seats();
                        bus_mas[j].get_all_passengers();
                        bus_mas[j].get_destination();
                        cout<<endl;
                    }
                    system("pause");
                    break;
                }
            }
            break;
        case 0: exit(1);
        }
    system("cls");
    }
 }
