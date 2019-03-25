#pragma once

#include "libs.h"

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template <class T>
class ArrayList
{
private:
	int counter;
	T* items;

public:
	ArrayList() : counter{ 0 }, items{ nullptr } {}
	ArrayList(const ArrayList<T>& a);
	T get(int index) const;	
	void insert(int index, const T& element);
	int search(const T& element) const;
	void remove(int index);
	int count() const;
	void insert_list(int index, const ArrayList& list);
	auto operator+=(const T& number)->ArrayList&;
	auto operator-=(const T& elements)->ArrayList&;
	bool operator==(const ArrayList& l1);
	int frequency(T element);
	T operator[](const int index) const;
	ArrayList<T> operator>>(int n) const;
	ArrayList<T>& operator=(const ArrayList<T>& a);
	
	~ArrayList();
};

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& a) : counter{ a.counter }, items{ new T[a.counter] }
{
	for (auto i = 0; i < counter; ++i)
	{
		items[i] = a.items[i];
	}
}

template <class T>
int ArrayList<T>::count() const {
	return counter;
}

template <class T>
T ArrayList<T>::get(int index) const
{
	if (index < 0 || index > counter) {
		throw std::out_of_range("GET - INDEX OUT OF RANGE");
	}

	return items[index];
}

template <class T>
void ArrayList<T>::insert(int index, const T& element)
{
	if (index < 0 || index > counter) {
		throw std::out_of_range("INSERT - INDEX OUT OF RANGE");
	}

	T * items_copy = items;

	counter++;

	items = new T[counter];

	for (int i = 0, j = 0; i < counter; ++i)
	{
		if (index == i)
		{
			items[i] = element;
		}
		else
		{
			items[i] = items_copy[j];
			++j;
		}
	}

	delete[] items_copy;
}

template <class T>
int ArrayList<T>::search(const T& element) const
{
	for (int i = 0; i < counter; ++i)
	{
		if (items[i] == element)
		{
			return i;
		}
	}

	return -1;
}

template <class T>
void ArrayList<T>::remove(int index)
{
	if (index < 0 || index > counter) {
		throw std::out_of_range("REMOVE - INDEX OUT OF RANGE");
	}

	T* items_copy = items;

	counter--;

	items = new T[counter];

	for (int i = 0, j = 0; i < counter; ++i, ++j)
	{
		if (index == j)
		{
			++j;
		}

		items[i] = items_copy[j];
	}

	delete[] items_copy;
}

template <class T>
void ArrayList<T>::insert_list(int index, const ArrayList& list)
{
	if (index < 0 || index > counter)
	{
		throw std::out_of_range("INSERT - INDEX OUT OF RANGE");
	}

	if (list.counter == 0)
	{
		return;
	}

	T* copy = items;
	auto old_counter = counter;

	counter += list.counter;
	items = new T[counter];

	for (auto i = 0; i < index; ++i)
	{
		items[i] = copy[i];
	}

	for (auto i = index, j = 0; i < index + list.counter; ++i)
	{
		
		items[i] = list.get(j);
		++j;
	}

	for (auto i = index + list.counter, j = index; i < counter; ++i)
	{
		items[i] = copy[j];
		++j;
	}
	delete[] copy;
}

template <class T>
bool ArrayList<T>::operator==(const ArrayList& l1)
{
	if(counter != l1.counter)
	{
		return false;
	}

	for (auto i = 0; i < counter; ++i)
	{
		if(!(items[i] == l1.items[i]))
		{
			return false;
		}
	}
	return true;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator+=(const T& number)
{
	T* copy = items;
	++counter;
	items = new T[counter];

	for (auto i = 0; i < counter - 1; ++i)
	{
		items[i] = copy[i];
	}
	items[counter - 1] = number;
	return *this;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator-=(const T& element)
{
	T* copy = items;
	auto old_counter = counter;

	auto count = frequency(element);
	counter -= count;

	items = new T[counter];

	int idx = 0;
	for (auto i = 0; i < old_counter; ++i)
	{
		if(!(copy[i] == element))
		{
			items[idx] = copy[i];
			++idx;
		}
	}
	return *this;
}

template <class T>
int ArrayList<T>::frequency(T element)
{
	auto count = 0;

	for (auto i = 0; i < counter - 1; ++i)
	{
		if (items[i] == element)
		{
			count++;
		}
	}
	return count;

}

template <class T> 
T ArrayList<T>::operator[](const int index) const
{
	return items[index];
}

template <class T>
ArrayList<T> ArrayList<T>::operator>>(int n) const
{
	if (n < 0)
	{
		throw std::out_of_range("COUNTER LESS THAN 0");
	}

	n = n % counter;

	ArrayList<T> al{};
	al.counter = counter;
	al.items = new T[counter];

	const auto idx_from_end = counter - n;

	for (auto i = 0, j = 0; i < n; ++i)
	{
		al.items[i] = items[idx_from_end + i];
	}

	for (auto i = n; i < counter; ++i)
	{
		al.items[i] = items[i - n];
	}

	return al;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& a)
{
	if (a.counter <= 0 || !a.items)
	{
		return *this;
	}

	delete[] items;

	counter = a.counter;
	items = new T[counter];
	for (auto i = 0; i < counter; ++i)
	{
		items[i] = a.items[i];
	}

	return *this;
}


template <class T>
ArrayList<T>::~ArrayList() {
	delete items;
}

#endif // !ARRAY_LIST_H
