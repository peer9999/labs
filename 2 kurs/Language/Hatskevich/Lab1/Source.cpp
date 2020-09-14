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
	cout << "Название: " << title << "\n" 
		 << "Водоизмещение: " << displacement << "\n" 
		 << "Тип: " << type;
}

Ship::Ship() {
	cout << "\nКонструктор без параметров работал здесь! \n";
}

Ship::Ship(char* str_title, int value, char* str_type) {
	title = str_title;
	displacement = value;
	type = str_type;
	cout << "\nКонструктор с параметрами работал здесь! \n";
}

Ship::Ship(const Ship& ship) : title(ship.title), displacement(ship.displacement), type(ship.type) {
	cout << "\nКопирующий конструктор работал здесь! \n";
}

Ship::~Ship() {
	cout << "\nДеструктор работал здесь! \n";
}

