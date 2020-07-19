#include <iostream>
#include <stdlib.h>
using namespace std;

int* ff(int, int);
int j = 0;

int main()
{
	int n;
	cout << "Vvedite n = ";
	cin >> n;

	int x;
	cout << "Vvedite x = ";
	cin >> x;

	cout << "Array: ";
	int* p = ff(n,x);

	cout << "Result: ";
	for (int i = 0; i < j; i++) {
		cout << " " << p[i] << " ";
	} 
	delete[] p;

	//for (int i = 0; i < n; i++)
		//cout << p[i];
	system("pause");
	return 0;
}

int* ff(int n,int x)
{
	int* a = new int[n];	
	int *p = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		if (p[i] != 0 && p[i] != x) {
			a[j] = p[i];
			j++;
		}
	} 
	delete[] p;
	return a;
}
