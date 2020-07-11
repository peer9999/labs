#include <iostream>

#include "menu.h"

using namespace std;

void MenuView()
{
    //system("cls");
    cout << endl << "Меню" << endl;
    cout << "1.Ввод  " << "2.Сортировка  " << "3.Удаление  " << "4.Запись " << "5.Чтение  " << "6.Редактирование  " <<"7.Поиск  " << "0.Выход";
    cout << endl << endl;
}

int MenuSelect()
{
    int k = 0;
    cout << endl << endl << "Введите номер операции, которую необходимо выполнить: ";
    cin >> k;
    cin.get();
    return k;
}
