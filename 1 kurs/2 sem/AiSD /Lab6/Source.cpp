#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#define SIZE 20

struct heap {
    int* arr;
    int count;
    int capacity;
};

heap* heap_create(int capacity);
void heapify_bottom_top(heap* h, int index);
void heap_insert(heap* h, int key);
void read(int graph[][SIZE]);
void print(int graph[][SIZE]);
void dijkstra(int graph[][SIZE]);

int main() {
    setlocale(0, "");
    int graph[SIZE][SIZE]; // матрица связей

    read(graph);     // чтение матрицы
    print(graph);    // вывод матрицы
    dijkstra(graph); // реализация алгоритма

    return 0;
}

heap* heap_create(int capacity) {
    heap* h = new heap[sizeof(heap)];
    h->count = 0;
    h->capacity = capacity;
    h->arr = new int[capacity * sizeof(int)];
    return h;
}

void heapify_bottom_top(heap* h, int index) {
    int temp;
    int parent_node = (index - 1) / 2;
    if (h->arr[parent_node] > h->arr[index]) { // swap and recursive call
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top(h, parent_node);
    }
}

void heap_insert(heap* h, int key) {
    if (h->count < h->capacity) {
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

void read(int graph[][SIZE]) {
    ifstream matrix;
    matrix.open("matrix 3.txt");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix >> graph[i][j];
        }
    }
    matrix.close();
}

void print(int graph[][SIZE]) {
    cout << "Матрица смежности графа: " << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(4) << graph[i][j];
        }
        cout << endl;
    }
}

void dijkstra(int graph[][SIZE]) {
    heap* h;
    h = heap_create(400);

    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp, minindex, min, begin_index = 0;

    // Инициализация вершин и расстояний
    for (int i = 0; i < SIZE; i++) {
        d[i] = INT_MAX;
        v[i] = 1;
        heap_insert(h, d[i]);
    }
    d[begin_index] = 0;

    do {
        minindex = INT_MAX;
        min = INT_MAX;
        for (int i = 0; i < SIZE; i++) {
            if (v[i] == 1 && d[i] < min) { // Если вершину ещё не обошли и вес меньше min переприсваиваем значения
                min = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != INT_MAX) {
            for (int i = 0; i < SIZE; i++) {
                if (graph[minindex][i] > 0) {
                    temp = min + graph[minindex][i];
                    if (temp < d[i]) {
                        d[i] = temp;
                        heap_insert(h, d[i]);
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < INT_MAX);

    minindex = 2;
    min = d[1];
    // Вывод кратчайших расстояний до вершин
    cout << endl << "Кратчайшие расстояния до вершин: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << 1 << " - " << i + 1 << " = " << d[i] << endl;
        if (d[i] < min && d[i] > 0) {
            minindex = i + 1;
            min = d[i];
        }
    }

    // Вывод кратчайшего пути (начальная вершина оказалась в конце массива из k элементов)
    cout << endl << "Вывод кратчайшего пути: " << endl;
    cout << 1 << "-" << minindex << " = " << min << endl;
    cout << endl;
}