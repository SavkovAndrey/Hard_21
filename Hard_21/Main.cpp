#include <iostream>
#include <iomanip>

using namespace std;

int arrayUnique(int*& array, int size);

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	cout << "Введите размер массива: ";
	int size;
	cin >> size;

	int* array = new int[size];
	cout << "Случайный массив:\n";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 11;
		cout << setw(4) << array[i];
	}

	int new_size = arrayUnique(array, size);

	cout << "\n\nНовый размер массива: " << new_size << "\nсам массив:\n";
	for (int i = 0; i < new_size; i++)
	{
		cout << setw(4) << array[i];
	}
	cout << endl;

	delete[] array;
	system("pause");
	return 0;
}

int arrayUnique(int* &array, int size)
{
	int* buff_arr = new int[size];
	int k = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] != -1)
		{
			buff_arr[k] = array[i];
			k++;
			for (int j = i + 1; j < size; j++)
			{
				if (array[i] == array[j])
				{
					array[j] = -1;
				}
			}
		}
	}
	int new_size = k;

	/*
	for (int i = 0; i < new_size; i++)
	{
		array[i] = buff_arr[i];
	}
	
	*/
	
	int* new_array = new int[new_size];


	cout << "\n\n ОТЛАДКА\n";
	for (int i = 0; i < new_size; i++)
	{
		new_array[i] = buff_arr[i];
		cout << setw(4) << new_array[i];
	}
	cout << "\nОТЛАДКА\n";

	delete[] array;
	array = new_array;
	delete[] buff_arr;
	return new_size;
}