#include <iostream>

#include "menu.h"

using namespace std;

void MenuView()
{
    //system("cls");
    cout << endl << "����" << endl;
    cout << "1.����  " << "2.����������  " << "3.��������  " << "4.������ " << "5.������  " << "6.��������������  " <<"7.�����  " << "0.�����";
    cout << endl << endl;
}

int MenuSelect()
{
    int k = 0;
    cout << endl << endl << "������� ����� ��������, ������� ���������� ���������: ";
    cin >> k;
    cin.get();
    return k;
}
