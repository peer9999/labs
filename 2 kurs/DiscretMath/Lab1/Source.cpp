#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Прямое произведение множеств
void multiplication(int* a, int* b, int size_a, int size_b) {
    typedef vector <pair<int, int>> Union;
    vector <int> res;
    Union result;
    vector <int> part1;
    vector <int> part2;
    cout << "Multiplication: \n";

    for (int i = 0; i < size_a; i++) {
        for (int j = 0; j < size_b; j++) {
            part1.push_back(a[i]);
            part2.push_back(b[j]);
        }
    }
    
    for (int i = 0; i < part1.size(); i++) {
       result.push_back(make_pair(part1[i], part2[i]));
    }
    
    int length = result.size();
    
    cout << "{ ";
    for (vector<pair<int, int>>::iterator it = result.begin(); it != result.end(); it++) {
        cout << "( " <<  it->first << ", " << it->second << " )" << ",";
    }
    cout << " }" << "\n";
    
    cout << "Power: " << length << "\n";
}

// Пересечение множеств используя битовую маску
vector <int> bitmask(int* a, int* u, int size_a, int size_u) {
    vector <int> bitmasks;

    for (int i = 0; i < size_u; i++) {
        bool flag = false;
        for (int j = 0; j < size_a; j++) {
            if (a[j] == u[i]) {
                flag = true;
                break;
            }
        }
        if (flag == true) {
            bitmasks.push_back(1);
        }
        else {
            bitmasks.push_back(0);
        }
    }
    /*
    cout << "Bitmask: " << "{ ";
    for (int i = 0; i < m; i++) {
        cout << bitmasks[i] << ", ";
    }
    cout << " }";
    */
    return bitmasks;
}

void sets_union(int* a, int* b, int* U, int size_a, int size_b, int size_u) {
    vector <int> bitmask_a, bitmask_b;
    int i;
    bitmask_a = bitmask(a, U, size_a, size_u);
    bitmask_b = bitmask(b, U, size_b, size_u);

    cout << "Bitmask A: " << "{ ";
    for (i = 0; i < size_u; i++) {
        cout << bitmask_a[i] << ", " ;
    }
    cout << " }";

    cout << "\n";
    cout << "Bitmask B: " << "{ ";
    for (i = 0; i < size_u; i++) {
        cout << bitmask_b[i] << "," << " ";
    }
    cout << " }";
    cout << "\n";

    cout << "Sets union \n" << "{ ";
    for (i = 0; i < size_u; i++) {
        if (bitmask_a[i] && bitmask_b[i]) {
            cout << U[i] << " ";
        }
    }
    cout << "}";
}

void Merge(int* A, int first, int last)
{
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final])))
        {
            mas[j] = A[start];
            start++;
        }
        else
        {
            mas[j] = A[final];
            final++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++) A[j] = mas[j];
    delete[]mas;
};

//Рекурсивная процедура сортировки
void MergeSort(int* A, int first, int last)
{
    {
        if (first < last)
        {
            MergeSort(A, first, (first + last) / 2); //сортировка левой части
            MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
            Merge(A, first, last); //слияние двух частей
        }
    }
};

//Булеан
void boolean(int *a, int size_a) {
    int i, j, n;
    int range = 1 << size_a;
    cout << "{";
    for (i = 0; i < range; i++) {
        cout << "{";
        for (j = 0; j < size_a; j++) {
            n = i >> j;
            if (n & 1) {
                cout << a[j];
                if (n >= j && n > 1) {
                    cout << ",";
                }
            }
        }
        cout << "}";
        if (i < range - 1) {
            cout << ",";
        }
    }
    cout << "}" << endl;
}

void printbin(int value) {
    for (int i = 4; i >= 0; i--) {
        cout << ((value >> i) & 1);
    }
/*
    string str;
    int k = 0;
    while (value >= 1) {
        if (value % 2 == 0) {
            str[k] = '0';
            //cout << "1";
        }
        else {
            str[k] = '1';
            //cout << "0";
        }
        value /= 2;
        k++;
    }
    for (int i = 0, j = k; i < k, j > 0; i++, j--) {
        swap(str[i], str[j]);
        cout << str[i];
    }
*/
    cout << "\n";
}
void Grey_code(int* a, int size_a) {
    cout << "Код грея: \n";
    for (int i = 0; i < size_a; i++) {
        int x = a[i];
        int y = x >> 1;
        int z = x ^ y;
        cout << x << " " << z << " ";
        printbin(z);
    }
    cout << "\n";
}



void Task1(int *am, int *bm, int *U,int *dm , int size_a, int size_b, int size_u, int size_d) {
    multiplication(am, bm, size_a, size_b);
    cout << "\n";
    sets_union(am, bm, U, size_a, size_b, size_u);
    cout << "\n";
    //cout << "Sort: \n";
    //MergeSort(dm, 0, size_d);
    cout << "\n";
    cout << "Boolean: \n";
    boolean(am, size_a);
    cout << "\n";
    Grey_code(am, size_a);
}

int main() {
    setlocale(0, "");
    int size_am, size_bm, size_cm, i;

    int U[100] =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int am[100] = { 1, 3, 4, 6, 7 };
    int bm[100] = { 1, 2, 3, 4 };
    int cm[100] = { 4, 5, 6 };
    int dm[100] = { 4, 2, 3, 6, 1, 5, 7, 10 , 9, 11};

    // cin >> n >> m >> k;
   
    // int *am = new int [size_am];
    // int *bm = new int [size_bm];
    // int *cm = new int [size_cm]
  
    // Ввод множеств с клавиатуры
    // for (i = 0; i < size_; i++) {
    //     cin >> am[i];
    // }
    // for (i = 0; i < m; i++) {
    //     cin >> bm[i];
    // }
    // for (i = 0; i < k; i++) {
    //     cin >> cm[i];
    // }

    //Пересечение с исп. битовой маски
    //bitmask_union(am, bm, U, 5, 3, 11);

    //Прямое произведение множеств
    //multiplication(am, bm, 5, 4);

    /*
    MergeSort(dm, 0, 10);
    for (i = 1; i <= 10; i++) {
        cout << dm[i] << " ";
    }
    */
    //Булеан
    //boolean(am, 5);
    
    Grey_code(am, 5);
    /*
    int select_task;
    do {
        cout << "Number of task (1 or 2): ";
        cin >> select_task;
        switch (select_task) {
        case 1:
            cout << "Task 1: \n\n";
            Task1(am, bm, U, dm, 5, 3, 11, 10);
            break;
        case 2:
            cout << "Task 2 \n";
            break;
        case 0:
            cout << "Exit \n";
            return 0;
        }

    } while (1);
    */
}