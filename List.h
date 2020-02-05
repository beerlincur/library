#pragma once
#include <iostream>
#include "Book.h"
#include <iomanip>
#include "DisciplineCount.h"

using std::endl;
using std::setw;

template<typename T>
class List
{
public:
	List() : size_(0), head_(nullptr) {};
	void clear();
	int getSize();
	void popBack();
	void popFront();
	void pushBack(const T& data);
	void pushFront(const T& data);
	void removeAt(const int index);
	T& operator[](const int index);
	void insertAmountSort(const T& dataOut);
	void insert(const T& data, const int index);
	
	friend class Book;
	~List();
private:

	template<typename T>
	class Node
	{
	public:
		Node *pNext_;
		T data_;

		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data_ = data;
			this->pNext_ = pNext;
		}

	};
	size_t size_;
	Node<T> *head_;
};

template<typename T>
void List<T>::pushBack(const T& data)
{
	if (head_ == nullptr)
	{
		head_ = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head_;
		while (current->pNext_ != nullptr)
		{
			current = current->pNext_;
		}
		current->pNext_ = new Node<T>(data);
	}
	size_++;
}

template<typename T>
void List<T>::pushFront(const T& data)
{
	head_ = new Node<T>(data, head_);
	size_++;
}

template<typename T>
void List<T>::popFront()
{
	Node<T>* temp = head_;

	head_ = head_->pNext_;

	delete temp;

	size_--;
}

template<typename T>
void List<T>::popBack() { removeAt(size_ - 1); }

template<typename T>
void List<T>::insert(const T& data, const int index)
{
	if (index == 0)
	{
		pushFront(data);
	}
	else
	{
		Node<T>* previous = this->head_;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext_;
		}
		previous->pNext_ = new Node<T>(data, previous->pNext_);
		size_++;
	}
}

template<typename T>
void List<T>::insertAmountSort(const T& dataOut)
{
	if (size_ == 0)
	{
		pushFront(dataOut);
		return;
	}
	else
	{
		Node<T>* current = this->head_;
		for (size_t i = 0; i < size_; i++)
		{
			if (dataOut < current->data_)
			{
				if (i == 0)
				{
					pushFront(dataOut);
					return;
				}
				else
				{
					insert(dataOut, i);
					return;
				}
			}
			current = current->pNext_;
		}
		pushBack(dataOut);
	}

}

template<typename T>
void List<T>::removeAt(const int index)
{
	if (index == 0)
	{
		popFront();
	}
	else
	{
		Node<T>* previous = this->head_;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext_;
		}
		Node<T>* toDelete = previous->pNext_;
		previous->pNext_ = toDelete->pNext_;
		delete toDelete;
		size_--;
	}
}

template<typename T>
void List<T>::clear()
{
	while (size_)
	{
		popFront();
	}
}

template<typename T>
int List<T>::getSize() { return size_; }

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head_;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data_;
		}
		current = current->pNext_;
		counter++;
	}
}

template<typename T>
List<T>::~List() { clear(); }

//==============================================================================================================================================
//==============================================================================================================================================
//==============================================================================================================================================
template<>
class List<Book>
{
public:
	List() : size_(0), head_(nullptr) {};
	void pushBack(const Book& data)
	{
		if (head_ == nullptr)
		{
			head_ = new Node(data);
		}
		else
		{
			Node* current = this->head_;
			while (current->pNext_ != nullptr)
			{
				current = current->pNext_;
			}
			current->pNext_ = new Node(data);
		}
		size_++;
	}

	void pushFront(const Book& data)
	{
		head_ = new Node(data, head_);
		size_++;
	}

	void popFront()
	{
		Node* temp = head_;

		head_ = head_->pNext_;

		delete temp;

		size_--;
	}

	void popBack() { removeAt(size_ - 1); }

	void insert(const Book& data, const int index)
	{
		if (index == 0)
		{
			pushFront(data);
		}
		else
		{
			Node* previous = this->head_;
			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->pNext_;
			}
			previous->pNext_ = new Node(data, previous->pNext_);
			size_++;
		}
	}

	void insertAmountSort(const Book& dataOut)
	{
		if (size_ == 0)
		{
			pushFront(dataOut);
			return;
		}
		else
		{
			Node* current = this->head_;
			for (size_t i = 0; i < size_; i++)
			{
				if (dataOut < current->data_)
				{
					if (i == 0)
					{
						pushFront(dataOut);
						return;
					}
					else
					{
						insert(dataOut, i);
						return;
					}
				}
				current = current->pNext_;
			}
			pushBack(dataOut);
		}
	}

	void insertDisSort(const Book& dataout)
	{
		if (size_ == 0)
		{
			pushFront(dataout);
			return;
		}
		else
		{
			Node* current = this->head_;
			for (size_t i = 0; i < size_; i++)
			{
				if (dataout.getDiscipline() < current->data_.getDiscipline())
				{
					if (i == 0)
					{
						pushFront(dataout);
						return;
					}
					else
					{
						insert(dataout, i);
						return;
					}
				}
				current = current->pNext_;
			}
			pushBack(dataout);
		}
	}

	void showDisCountTable(ostream& out)
	{
		Node* current = this->head_;
		Node* next = current->pNext_;

		String currentDis = current->data_.getDiscipline();
		String nextDis = next->data_.getDiscipline();

		out << "Disciplines and amount of books for them: " << endl;
		out << "#"  << setw(4) << "|| " <<  "Discipline"   << setw(10) << "|| " << "Amount of books recommended" << endl;
		 
		int counter = 1;
		int i = 0;
		while (next != nullptr)
		{
			while (currentDis == nextDis)
			{
				counter++;
				current = current->pNext_;
				next = next->pNext_;
				currentDis = current->data_.getDiscipline();
				if (next == nullptr)
				{
					break;
				}
				nextDis = next->data_.getDiscipline();
			}
			int disLen = currentDis.len();
			out << "====================================================" << endl;
			out << i << setw(5) << "||  " << currentDis << setw(20 - disLen) << "  ||  " << counter << endl;
			counter = 1;
			i++;
			if (next == nullptr)
			{
				return;
			}
			current = current->pNext_;
			next = next->pNext_;
			currentDis = current->data_.getDiscipline();
			int disLen1 = currentDis.len();
			if (next == nullptr)
			{
				out << "====================================================" << endl;
				out << i << setw(5) << "||  " << currentDis << setw(20 - disLen1) << "  ||  " << counter << endl;
				return;
			}
			
			nextDis = next->data_.getDiscipline();
		}

	}


	void removeAt(const int index)
	{
		if (index == 0)
		{
			popFront();
		}
		else
		{
			Node* previous = this->head_;
			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->pNext_;
			}
			Node* toDelete = previous->pNext_;
			previous->pNext_ = toDelete->pNext_;
			delete toDelete;
			size_--;
		}
	}

	void clear()
	{
		while (size_)
		{
			popFront();
		}
	}

	int getSize() { return size_; }

	Book& operator[](const int index)
	{
		int counter = 0;
		Node* current = this->head_;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data_;
			}
			current = current->pNext_;
			counter++;
		}
	}

	friend class Book;
	~List() { clear(); }

private:

	class Node
	{
	public:
		Node* pNext_;
		Book data_;

		Node(Book data = Book(), Node* pNext = nullptr)
		{
			this->data_ = data;
			this->pNext_ = pNext;
		}

	};
	size_t size_;
	Node* head_;
};

//==========================================================================================
//==========================================================================================
//==========================================================================================
template<>
class List<DisciplineCount>
{
public:
	List() : size_(0), head_(nullptr) {};
	void pushBack(const DisciplineCount& data)
	{
		if (head_ == nullptr)
		{
			head_ = new Node(data);
		}
		else
		{
			Node* current = this->head_;
			while (current->pNext_ != nullptr)
			{
				current = current->pNext_;
			}
			current->pNext_ = new Node(data);
		}
		size_++;
	}

	void pushFront(const DisciplineCount& data)
	{
		head_ = new Node(data, head_);
		size_++;
	}

	void popFront()
	{
		Node* temp = head_;

		head_ = head_->pNext_;

		delete temp;

		size_--;
	}

	void popBack() { removeAt(size_ - 1); }

	void insert(const DisciplineCount& data, const int index)
	{
		if (index == 0)
		{
			pushFront(data);
		}
		else
		{
			Node* previous = this->head_;
			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->pNext_;
			}
			previous->pNext_ = new Node(data, previous->pNext_);
			size_++;
		}
	}

	void insertDisCountSort(const Book& dataout)
	{
		DisciplineCount temp;
		temp.setDiscipline(dataout.getDiscipline());

		if (size_ == 0)
		{
			pushFront(temp);
			return;
		}
		else
		{
			Node* current = this->head_;
			
			for (size_t i = 0; i < size_; i++)
			{
				if (temp.getDiscipline() == current->data_.getDiscipline())
				{
					++current->data_;
					return;
				}
				else if (temp.getDiscipline() < current->data_.getDiscipline())
				{
					
					if (i == 0)
					{
						pushFront(temp);
						return;
					}
					else
					{
						insert(temp, i);
						return;
					}
				}
				current = current->pNext_;
			}
			pushBack(temp);
		}
	}

	void showTable(ostream& out)
	{
		out << "Disciplines and amount of books for them: " << endl;
		out << "#" << setw(4) << "|| " << "Discipline" << setw(10) << "|| " << "Amount of books recommended" << endl;

		Node* current = this->head_;

		for (size_t i = 0; i < size_; i++)
		{
			String currentDis = current->data_.getDiscipline();
			int currentCount = current->data_.getCount();

			out << "====================================================" << endl;
			out << i << setw(5) << "||  " << currentDis << setw(20 - currentDis.len()) << "  ||  " << currentCount << endl;
			current = current->pNext_;
		}
	}

	void removeAt(const int index)
	{
		if (index == 0)
		{
			popFront();
		}
		else
		{
			Node* previous = this->head_;
			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->pNext_;
			}
			Node* toDelete = previous->pNext_;
			previous->pNext_ = toDelete->pNext_;
			delete toDelete;
			size_--;
		}
	}

	void clear()
	{
		while (size_)
		{
			popFront();
		}
	}

	int getSize() { return size_; }

	DisciplineCount& operator[](const int index)
	{
		int counter = 0;
		Node* current = this->head_;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data_;
			}
			current = current->pNext_;
			counter++;
		}
	}

	friend class DisciplineCount;
	friend class Book;
	~List() { clear(); }

private:

	class Node
	{
	public:
		Node* pNext_;
		DisciplineCount data_;

		Node(DisciplineCount data = DisciplineCount(), Node* pNext = nullptr)
		{
			this->data_ = data;
			this->pNext_ = pNext;
		}

	};
	size_t size_;
	Node* head_;
};