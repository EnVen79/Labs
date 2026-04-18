#pragma once

#include <iostream>
#include "Satur.h"
#include "E10.h"
#include "Vector.h"

template <typename T> class VectorT
{
private:

	T* V;
	int sz;

public:

	VectorT(int rows, int cols = -1);
	VectorT();
	VectorT(const VectorT& other);
	VectorT(VectorT&& other);
	~VectorT();

	VectorT& operator=(const VectorT& other);
	VectorT& operator=(VectorT&& other);

	inline int size() const { return sz; }

	inline T& elem(int i)
	{
		if (i < 0 || i >= sz)
			throw "Invalid index";
		return V[i];
	}
	inline const T& elem(int i) const
	{
		if (i < 0 || i >= sz)
			throw "Invalid index";
		return V[i];
	}

	T& operator[](int i);
	const T& operator[](int i) const;

	void print() const;

	void resize(int newsz);

	template <typename U>
	friend void equalize(VectorT<U>& a, VectorT<U>& b);

	template <typename U>
	friend VectorT<U> operator+(const VectorT<U>& a, const VectorT<U>& b);

	template <typename U>
	friend VectorT<U> operator-(const VectorT<U>& a, const VectorT<U>& b);
};

template <typename T>
VectorT<T>::VectorT(int rows, int cols)
{
	if (rows < 0)
		throw "Incorrect vector size";

	sz = rows;
	V = new T[sz]();

	if (cols != -1)
	{
		for (int i = 0; i < sz; i++)
			V[i] = T(cols);
	}
}

template <typename T>
VectorT<T>::VectorT()
{
	sz = 0;
	V = new T[sz];
}

template <typename T>
VectorT<T>::VectorT(const VectorT& other) : VectorT(other.sz)
{
	for (int i = 0; i < sz; i++)
	{
		V[i] = other.V[i];
	}
}

template <typename T>
VectorT<T>::VectorT(VectorT&& other)
{
	V = other.V;
	sz = other.sz;
	other.V = nullptr;
	other.sz = 0;
}

template <typename T>
VectorT<T>::~VectorT()
{
	delete[] V;
}

template <typename T>
VectorT<T>& VectorT<T>::operator=(const VectorT& other)
{
	if (this == &other) return *this;

	if (sz != other.sz)
	{
		delete[] V;
		sz = other.sz;
		V = new T[sz];
	}

	for (int i = 0; i < sz; i++)
	{
		V[i] = other.V[i];
	}
	return *this;
}

template <typename T>
VectorT<T>& VectorT<T>::operator=(VectorT&& other)
{
	if (this == &other) return *this;

	delete[] V;
	V = other.V;
	sz = other.sz;
	other.V = nullptr;
	other.sz = 0;
	return *this;
}

template <typename T>
T& VectorT<T>::operator[](int i)
{
	if (i < 0 || i >= sz)
		throw "Invalid index";
	return V[i];
}

template <typename T>
const T& VectorT<T>::operator[](int i) const
{
	if (i < 0 || i >= sz)
		throw "Invalid index";
	return V[i];
}

template <typename T>
void VectorT<T>::resize(int newsz)
{
	if (newsz < 0)
		throw "Invalid vector size";

	if (newsz == sz)
		return;

	T* temp = new T[newsz];

	int minsz;
	if (sz < newsz)
		minsz = sz;
	else
		minsz = newsz;

	for (int i = 0; i < minsz; i++)
		temp[i] = V[i];

	for (int i = minsz; i < newsz; i++)
		temp[i] = T();

	delete[] V;
	V = temp;
	sz = newsz;
}

template <typename T>
void equalize(VectorT<T>& a, VectorT<T>& b)
{
	int maxsz;

	if (a.sz > b.sz)
		maxsz = a.sz;
	else
		maxsz = b.sz;

	a.resize(maxsz);
	b.resize(maxsz);
}

template <typename T>
VectorT<T> operator+(const VectorT<T>& a, const VectorT<T>& b)
{
	VectorT<T> first = a;
	VectorT<T> second = b;

	if (a.sz != b.sz)
	{
		equalize(first, second);
	}

	VectorT<T> sum(first.sz);

	for (int i = 0; i < first.sz; i++)
	{
		sum.V[i] = first.V[i] + second.V[i];
	}

	return sum;
}

template <typename T>
VectorT<T> operator-(const VectorT<T>& a, const VectorT<T>& b)
{
	VectorT<T> first = a;
	VectorT<T> second = b;

	if (a.sz != b.sz)
	{
		equalize(first, second);
	}

	VectorT<T> sub(first.sz);

	for (int i = 0; i < first.sz; i++)
	{
		sub.V[i] = first.V[i] - second.V[i];
	}

	return sub;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const VectorT<T>& V)
{
	for (int i = 0; i < V.size(); i++)
	{
		os << V[i] << " ";
	}
	return os;
}

template <typename T>
void VectorT<T>::print() const
{
	std::cout << "[ ";
	for (int i = 0; i < sz; i++)
	{
		std::cout << V[i] << " ";
	}
	std::cout << "]\n";
}

template <>
void VectorT<E10>::print() const
{
	std::cout << "[ ";
	for (int i = 0; i < sz; i++)
	{
		V[i].print();
		std::cout << " ";
	}
	std::cout << "]\n";
}

template <>
void VectorT<Satur>::print() const
{
	std::cout << "[ ";
	for (int i = 0; i < sz; i++)
	{
		V[i].print();
		std::cout << " ";
	}
	std::cout << "]\n";
}