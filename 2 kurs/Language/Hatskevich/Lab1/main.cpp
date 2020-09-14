#include <iomanip>
#include "ship.h"

void View_temp(Ship&, char*, int, char*);
void View(Ship);

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int max1;
	cout << "Max = ";
	cin >> max1;
	cin.get();

	char* title = new char[max1], 
		* type = new char[max1];
	int value;

	cout << "��������: ";
	cin.get(title, max1);

	cout << "�������������: ";
	cin >> value;
	cin.get();

	cout << "��� �������: ";
	cin.get(type, max1);

	cout << setfill('-') << setw(84);

	//����������� � �����������
	Ship object(title, value, type);
	object.getInfo();
	cout << "\n";

	cout << setfill('-') << setw(81);

	//����������� �����������
	Ship objcopy = object;
	objcopy.getInfo();
	cout << "\n";

	cout << setfill('-') << setw(81);

	// ������ ������ ������ ����������� ������������
	View_temp(objcopy, title, value, type);

	cout << setfill('-') << setw(81);

	//������ ������ ������ ����������� ������������
	View(objcopy);

	cout << setfill('-') << setw(85);

	//����������� ��� ����������
	Ship obj;
	obj.setTitle(title);
	obj.setValue(value);
	obj.setType(type);
	obj.getInfo();
	cout << "\n";

	cout << setfill('-') << setw(84);

	//����������
	Ship* objptr = new Ship(title, value, type);
	obj.getInfo();
	cout << "\n";
	delete objptr;

	//������������� ����������� � ������������ ��������
	cout << setfill('-') << setw(84);

	int max;

	cout << "\n������������ �����: ";
	cin >> max;
	cin.get();

	cout << "�������� 1: ";
	cin.get(title, max);
	cin.get();

	cout << "��� �������: ";
	cin.get(type, max);
	cin.get();


	Ship object1[2];
	object1[0].setTitle(title);
	object1[0].setValue(value);
	object1[0].setType(type);
	object1->getInfo();
	
	cout << "\n\n�������� 2: ";
	cin.get(title, max);
	cin.get();

	cout << "\n";

	object1[1].setTitle(title);
	object1[1].setValue(value);
	object1[1].setType(type);
	object1->getInfo();

	cout << "\n";

	cout << setfill('-') << setw(84);

	cout << "\n��������: ";
	cin.get(title, max);
	cin.get();

	cout << "��� �������: ";
	cin.get(type, max);
	cin.get();
	cout << "\n";

	Ship* p;

	p = new Ship[2];

	p->setTitle(title);
	p->setValue(value);
	p->setType(type);
	p->getInfo();

	cout << "\n\n������ �������: " << "\n";

	p->setTitle(title);
	p->setValue(4000);
	p->setTitle(type);
	p->getInfo();

	cout << "\n";

	return 0;
}

void View_temp(Ship& obj, char* str_title, int value, char* str_type) {
	Ship temp(obj);
	temp.setTitle(str_title);
	temp.setValue(value);
	temp.setType(str_type);
	obj.getInfo();
}

void View(Ship obj) {
	obj.getInfo();
}