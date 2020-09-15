#include <iostream>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::array;

array<int,256> next,prev,block,arr;
 
void print(int n) {
    int i,j = 1;
    do {
        cout << "{ ";
        for (i = j; i <= n; i++) {
            if (block[i] == j) {
                cout << arr[i] << " ";
            }
        }
        j = next[j]; 
        cout << "} ";
    } while (!(j == 0));
    cout << endl;
}
 
int main() {
    int i,j,k,n;
    array<bool,256> wper;
    cout << "intput n:";
    cin >> n; 
    for (i = 1; i <= n; i++) {
        arr[i]   = i;
        block[i] = 1;
        wper[i]  = true;
    }
    next[1] = 0;
    print(n); 
    j = n;
    while (j > 1) {
        k = block[j]; 
        if (wper[j])  {
            if (next[k] == 0)  {
                next[k] = j; 
                prev[j] = k;
                next[j] = 0;
            }
            if (next[k] > j)  {
                prev[j] = k; 
                next[j] = next[k];
                prev[next[j]] = j;
                next[k] = j;
            }
            block[j] = next[k];
        } else {
            block[j] = prev[k]; 
            if (k == j) {
                if (next[k] == 0) {
                    next[prev[k]] = 0;
                } else {
                    next[prev[k]] = next[k];
                    prev[next[k]] = prev[k];
                }
            }
        }
        print(n);
        j = n;
        while (j > 1 && ((wper[j] && block[j] == j) || (!wper[j] && block[j] == 1))) {
            wper[j] = !wper[j];
            j -= 1;
        }
    }
}
