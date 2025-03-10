#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

void create_arr(int**& arr, const int M, const int N)
 {
	arr = new int* [M];
	for (int i = 0; i < M; i++)
		 {
		arr[i] = new int[N];
		}
	 }

//Функция для заполнения и объявления массива
void input(int**& arr, const int M, const int N) {
	srand(time(0));
	cout << "Исходный массив\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 21 - 10;

			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	
}

void solution(int**& arr, const int M, const int N) {
	int t;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N/ 2; j++)
		{
			t = arr[i][j];
			arr[i][j] = arr[i][N - j - 1];
			arr[i][N - j - 1] = t;
		}
	
	}
}

//Функция для вывода матрицы
void output(int**& arr, const int M, const int N) {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(4) << arr[i][j];

		}
		cout << endl;
	}
}

//Основная функция
int main()
{
	setlocale(0, "");
	int m, n;
	cout << "Введите количество строк: ";
	cin >> m;
	cout << "Введите количество столбцов: ";
	cin >> n;
	int **p = 0;
	
	create_arr(p, m, n);
	input(p,m,n);
	cout << endl;
	cout << "Измененный массив\n";
	solution(p,m,n);
	output(p,m,n);
	system("pause");
	return 0;
}
