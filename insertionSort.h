#include "Array.h"

template<typename B>
void insertionSort(Array<B>& arrayPtr, size_t size) // сортировка вставками
{
	B temp; // временная переменная для хранения значения элемента сортируемого массива
	int item; // индекс предыдущего элемента

	for (size_t counter = 1; counter < size; counter++)
	{
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}
}