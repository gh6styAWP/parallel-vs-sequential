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
	setlocale(LC_ALL, "Ru");
	int count = 0;
	const size_t N = 900000000;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) //заполняем массив случайными числами от 0 до 100
		arr[i] = rand() % 101;

	int value = rand() % N; //присваиваем случайный индекс
	int temp = arr[value];
	
	auto start = chrono::steady_clock::now(); //начинаем отсчёт

	for (int i = 0; i < N; i++) //ищем повторяющиеся значения в массиве	
		if(arr[i] == temp)
			count++;	

	auto end = chrono::steady_clock::now(); //заканчиваем отсчёт
	chrono::duration<double> elapsed = end - start;

	cout << "-- последовательный вариант --";
	cout << "\n\n\tвремя выполнения алгоритма: " << elapsed.count() << " секунд";
	cout << "\n\tповторяющихся чисел: " << count;

	int num_threads = thread::hardware_concurrency();
	if (num_threads == 0) num_threads = 4; //на всякий случай
	cout << "\n\nкол-во потоков: " << num_threads;

	vector<thread> threads;
	vector<long long> partial_counts(num_threads);

	start = chrono::steady_clock::now(); //начинаем отсчёт

	size_t block = N / num_threads;
	size_t begin = 0;

	for (unsigned int t = 0; t < num_threads; ++t) {
		size_t end_index = (t == num_threads - 1)
			? N                //последний до конца массива
			: begin + block;   //обычный кусок

		threads.emplace_back(
			count_segment,
			cref(arr), //массив по константной ссылке
			temp,
			begin,
			end_index,
			ref(partial_counts[t]) //результат этого потока
		);

		begin = end_index;
	}

	for (auto& th : threads) //ждём окончания всех потоков
		th.join();

	
	long long count_par = 0; //суммируем результаты
	for (auto c : partial_counts)
		count_par += c;

	end = chrono::steady_clock::now();
	chrono::duration<double> elapsed_par = end - start;

	cout << "\n\n-- параллельный вариант --\n";
	cout << "\n\tвремя выполнения алгоритма: " << elapsed_par.count();
	cout << "\n\tповторяющихся чисел: " << count_par << "\n";

}

