#include "ship.h"

void Ship::setTitle(char* string) {
	title = string;
}

void Ship::setValue(int value) {
	displacement = value;
}

void Ship::setType(char* string) {
	type = string;
}

void Ship::getInfo() {
	cout << "��������: " << title << "\n" 
		 << "�������������: " << displacement << "\n" 
		 << "���: " << type;
}

Ship::Ship() {
	cout << "\n����������� ��� ���������� ������� �����! \n";
}

Ship::Ship(char* str_title, int value, char* str_type) {
	title = str_title;
	displacement = value;
	type = str_type;
	cout << "\n����������� � ����������� ������� �����! \n";
}

Ship::Ship(const Ship& ship) : title(ship.title), displacement(ship.displacement), type(ship.type) {
	cout << "\n���������� ����������� ������� �����! \n";
}

Ship::~Ship() {
	cout << "\n���������� ������� �����! \n";
}

