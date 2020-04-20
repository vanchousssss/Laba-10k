#include<iostream>
#include<fstream>
#include<Windows.h>
#include"Money.h"
#include"File.h"

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Money p, p1, p2, p3;
    int k, c;
    char file_name[30];
    do
    {	//Меню
        cout << "\n1. Создать файл";
        cout << "\n2. Печать файла";
        cout << "\n3. Удалить все записи из интервала от k1 до k2";
        cout << "\n4. Добавление K записей в начало файла";
        cout << "\n5. Увеличить все записи с заданным значением в два раза";
        cout << "\n6. Сравнение и сумма 2 элементов";
        cout << "\n0. Выход\n";
        cin >> c;
        switch (c)
        {
        case 1: cout << "Имя файла\n";
            cout << "> ";
            cin >> file_name;
            k = create_file(file_name);
            if (k < 0)
                cout << "Ошибка!";
            break;
        case 2: cout << "Имя файла\n";
            cout << "> ";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0)
                cout << "Пустой файл\n";
            if (k < 0)
                cout << "Ошибка!\n";
            break;
        case 3: cout << "Имя файла\n";
            cout << "> ";
            cin >> file_name;
            k = delete_file(file_name);
            if (k < 0)
                cout << "Ошибка!";
            break;
        case 4: cout << "Имя файла\n";
            cout << "> ";
            cin >> file_name;
            cout << "Сколько записей добавить?";
            cout << "> ";
            int K;
            cin >> K;
            k = add_file(file_name, K);
            if (k < 0)
                cout << "Ошибка!";
            break;
        case 5: cout << "Имя файла\n";
            cout << "> ";
            cin >> file_name;
            cout << "Введите значение\n";
            cout << "> ";
            cin >> p3;
            k = element_x2(file_name, p3);
            if (k < 0)
                cout << "\nОшибка!";
            break;
        case 6: cout << "Имя файла\n";
            cout << "> ";
            cin >> file_name;
            k = srav(file_name);
            if (k < 0)
                cout << "Ошибка!";
            break;
        }
    } while (c != 0);
}
