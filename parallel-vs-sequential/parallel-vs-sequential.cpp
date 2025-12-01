#include <iostream>
using namespace std;

void generateArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
		
	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 100000;
	int arr[N];

	generateArray(arr, N);


}

