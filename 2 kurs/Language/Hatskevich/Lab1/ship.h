#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Ship {
private:
	char* title = new char[20]; 
	long long displacement;
	char* type = new char[20];
public:
	Ship(); //Конструктор без параметров
	Ship(char* str_title, int value, char* str_type); //Коструктор с параметрами
	Ship(const Ship& ship); //Конструктор копирования
	~Ship();				//Деструктор

	void* getType();
	void getInfo();	
	void setTitle(char* string);
	void setValue(int value);
	void setType(char* string);
};