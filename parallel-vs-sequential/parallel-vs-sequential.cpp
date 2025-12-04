#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

//функция подсчёта для каждого потока
void count_segment(const vector<int>& arr, int value, size_t begin, size_t end, long long& out_count) {
	long long c = 0;
	for (size_t i = begin; i < end; ++i) 
		if (arr[i] == value)
			++c;
	out_count = c;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 100000000;
	vector<int> arr(N);
	int count = 0;

	//заполняем массив случайными числами от 0 до 100
	for (int i = 0; i < N; i++)
		arr[i] = rand() % 101;

	int value = rand() % N; //присваиваем случайный индекс
	int temp = arr[value];
	
	//начинаем отсчёт
	auto start = chrono::steady_clock::now();

	//ищем повторяющиеся значения в массиве
	for (int i = 0; i < N; i++)
	{
		if(arr[i] == temp)
			count++;
	}

	//заканчиваем отсчёт
	auto end = chrono::steady_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "\nвремя выполнения: " << elapsed.count() << " секунд";
	cout << "\nповторяющихся чисел: " << count;

	cout << "\n";
	int num_threads = thread::hardware_concurrency();
	cout << num_threads;



}

