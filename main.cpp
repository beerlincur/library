#include <iostream>
#include <fstream>
#include "List.h"
#include "DisciplineCount.h"
#include "insertionSort.h"
#include "maxAndMin.h"


const String FILE_NOT_OPEN = "Main: file not open.";

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;

Book split(String& str);
char *getline(istream& in);
struct maxAndMin maxMin(const Array<Book>& myArray, size_t size);


int main()
{
	try
	{

		ifstream in;                              
		in.open("in.txt");
		
		if (!in)
		{
			throw FILE_NOT_OPEN;
		}
		String arraySizeStr = getline(in);

		int arraySizeInt = arraySizeStr.to_int();

		Array<Book> libArray(arraySizeInt);

		bool isLessThanArraySize = false;

		for (int i = 0; i < arraySizeInt; i++)
		{
			String readedLine = getline(in);
			if (readedLine == nullptr)
			{
				cout
					<< "There are " << arraySizeInt - i
					<< " unused fields, do you want to calculate above "
					<< i << " objects? [Type anything, if yes. Type 'N', if not.]" << endl;
				char answer;
				cin >> answer;
				if (answer == 'N')
				{
					return -1;
				}
				isLessThanArraySize = true;
				arraySizeInt = i;
				break;
			}

			libArray[i] = split(readedLine);
		}

		String readedLine = getline(in);
		in.close();

		if ((isLessThanArraySize == false) && (readedLine != nullptr))
		{
			cout
				<< "The maximum possible number of objects for processing has been reached, the remaining data may not be taken into count, do you want to calculate above "
				<< arraySizeInt << " objects? [Type anything, if yes. Type 'N', if not.]" << endl;
			char answer;
			cin >> answer;
			if (answer == 'N')
			{
				return -1;
			}
		}


		cout << "Array has been filled!" << endl;

		struct maxAndMin mM = maxMin(libArray, arraySizeInt);//нахождение максимума и минимума (кол-во экземпляров в биб-ке)

		insertionSort<Book>(libArray, arraySizeInt);//сортировка массива объектов (кол-во экземпляров в биб-ке)
												   //вставками по возрастанию

		ofstream outForArray;
		outForArray.open("outForArray.txt");
		if (!outForArray)
		{
			throw FILE_NOT_OPEN;
		}

		if (mM.maxBook == mM.minBook)
		{
			outForArray << "Equal number of all books in the library is: " << endl << mM.maxBook.getAmount() << endl;
		}
		else
		{
			outForArray << "Amount of the most popular book is: " << endl << endl
				<< mM.maxBook << endl
				<< "Less popular is: " << endl << endl << mM.minBook << endl;
		}

		outForArray << "Sorted library (by amount of books in library): " << endl << endl;

		for (size_t i = 0; i < arraySizeInt; i++)
		{
			outForArray << libArray[i] << endl;
		}

		cout << "Array is done!" << endl;
		outForArray.close();

		List<DisciplineCount> libListDis;
		for (size_t i = 0; i < arraySizeInt; i++)
		{
			libListDis.insertDisCountSort(libArray[i]);
		}
		ofstream outForList;
		outForList.open("outForList.txt");
		if (!outForList)
		{
			throw FILE_NOT_OPEN;
		}
		libListDis.showTable(outForList);
		outForList.close();
		cout << "List is done!" << endl;
		
		cout << "Everything is DONE. Checkout the output files!" << endl << endl;

		system("pause");
		return 0;
	}
	catch (const String err)
	{
		cerr << err << endl;
		system("pause");
		return -1;
	}

}