#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int Max(int* a, const int size, int i, int max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;
}

template <typename T>
T Max(T* a, const int size, int i, T max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max<T>(a, size, i + 1, max);
	else
		return max;
}


int main()
{
	srand((unsigned)time(NULL));

	const int n = 10;
	const int Low = -10;
	const int High = 10;

	int a[n];
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "Max(a, n)= " << Max(a, n, 1, a[0]) << endl;
	cout << "Max<int>(a, n) = " << Max<int>(a, n, 1, a[0]) << endl;

	return 0;
}