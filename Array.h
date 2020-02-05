#include <algorithm>
#include <initializer_list>
#include <iostream>
#include "Book.h"


using std::initializer_list;
using std::fill;
using std::copy;
using std::swap;

template <typename T>
class Array
{
public:
	Array() : data_(nullptr), size_(0) {};
	Array(const initializer_list<T>&);
	Array(const size_t size);
	Array(const Array&);
	
	Array& operator=(const Array&);
	T* begin() const;
	T* end() const;
	T& operator [](const size_t);
	const T& operator [](const size_t) const;
	size_t size() const;
	friend class Book;
	~Array();

private:
	void swap(Array&, Array&);
	T* data_;
	size_t size_;
};

template <typename T>
Array<T>::Array(const size_t size) :
	data_(new T[size]),
	size_(size)
{
	// вызываем конструкторы для каждого элемента
	fill(data_, data_ + size_, T());
}

template<typename T>
Array<T>::Array(const initializer_list<T>& il) :
	data_(new T[il.size()]),
	size_(il.size())
{
	copy(il.begin(), il.end(), data_);
}

template <typename T>
Array<T>::Array(const Array& arr)
{
	size_ = arr.size_;
	if (arr.data_)
	{
		data_ = new T[size_];
		// копируем элементы в новый контейнер
		copy(arr.data_, arr.data_ + size_, data_);
	}
	else
		data_ = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& arr)
{
	// исключаем работу при присваивании самому себе
	if (this != &arr)
		Array(arr).swap(*this); 
	return *this;
}


template <typename T>
T* Array<T>::begin() const { return data_; }

template <typename T>
T* Array<T>::end() const { return data_ + size_; }

template <typename T>
T& Array<T>::operator [](const size_t index) { return data_[index]; }

template <typename T>
const T& Array<T>::operator [](const size_t index) const { return data_[index]; }

template <typename T>
size_t Array<T>::size() const { return size_; }

template <typename T>
void Array<T>::swap(Array& first, Array& second)
{
	swap(first.data_, second.data_);
	swap(first.size_, second.size_);
}

template <typename T>
Array<T>::~Array() { delete[] data_; }
