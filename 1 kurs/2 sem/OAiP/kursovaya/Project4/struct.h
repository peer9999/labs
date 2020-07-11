enum SORT {
    SORTSIZE = 1,
    SORTCOST
};

enum TYPE {
    TYPE_INT = 1,
    TYPE_CHAR
};

enum RESOLUTION {
    HIGHDEFENITION = 1,
    FULLHD,
    ULTRAHD4K,
    ULTRAHD8K
};

union MISC {
    int number;
    char note[25];
};

struct TV {
    char country[30]; // страна производитель
    char title[30];   // название телевизора
    unsigned int size : 10; // размер по диагонали
    float cost; // цена 
    RESOLUTION resolution; // разрешение экрана
    MISC misc;
    TYPE tag;
};

extern int index;
extern TV tv;

void Input      (TV*, int&); // функция ввода информации
void Output     (TV*, int&); // функция вывода информации
void Delete     (TV*, int&); // функция удаления записи в массиве структур
void Sort       (TV*, int&); // функция выбора по какому полю сортировать
void SortBySize (TV*, int&); // функция сортировки по размеру
void SortByCost (TV*, int&); // функция сортировки по цене
void Analyse    (TV*, int&); 
void Write      (TV*, int&); // функция записи в текстовый файл
void Read       (TV*, int&); // функция чтения из текстового файла
void Edit       (TV*);       // функция корректировки и замены элемента
void Find       (TV*, int&); // функция поиска максимума и минимума на заданном диапазоне

