#include <bits/stdc++.h>

using namespace std;

int n = 3;
const int m = 5;
int a[m];
int p[m];

void print() {
    int i,j,imax;
    imax = 1;
    for (i = 2; i <= n; i++) {
        if (p[i] > imax) {
            imax = p[i];
        }
    }
    for (i = 1; i <= imax; i++) {
        cout << "{";
        for (j = 1; j <= n; j++) {
            if (p[j] == i) {
                cout << a[j];
            }
        }
        cout << "} ";
    }
    cout << endl;
}

void part(int i = 1,int j = 1) {
    int l;
    if (i > n) {
        print();
    } else {
        for (l = 1; l <= j; l++) {
            p[i] = l;
            if (l == j) {
                part(i + 1,j + 1);
            } else {
                part(i + 1,j);
            }
        }
    }
}

int main() {
    for (int j = 1; j <= n; j++) {
        a[j] = j;
    }
    part();
    return 0;
}
