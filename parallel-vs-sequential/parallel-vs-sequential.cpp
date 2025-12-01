#include <iostream>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 100000;
	int arr[N];
	int count = 0;

	//заполняем массив случайными числами от 0 до 100
	for (int i = 0; i < N; i++)
		arr[i] = rand() % 101;

	int value = rand() % 100001; //присваиваем случайный индекс
	int temp = arr[value];

	//ищем поввторяющиеся значения в массиве
	for (int i = 0; i < N; i++)
	{
		if(arr[i] == temp)
			count++;
	}
	cout << count;

}

