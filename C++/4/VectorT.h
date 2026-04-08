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

	VectorT(int rows, int cols = -1) // constructor with size
	{
		if (rows < 0)
			throw "Incorrect vector size";

		sz = rows;
		V = new T[sz](); // initializing elements with the default value

		if (cols != -1)
		{
			for (int i = 0; i < sz; i++)
				V[i] = T(cols);
		}
	}

	VectorT() // default size = 0
	{
		sz = 0;
		V = new T[sz];
	}

	VectorT(const VectorT& other) : VectorT(other.sz) // copy constructor, original is alive
	{
		for (int i = 0; i < sz; i++)
		{
			V[i] = other.V[i];
		}
	}

	VectorT(VectorT&& other) // displacement constructor, data was taken from a temporary object
	{
		V = other.V;
		sz = other.sz;
		other.V = nullptr;
		other.sz = 0;
	}

	~VectorT()
	{
		delete[] V;
	}

	VectorT& operator=(const VectorT& other) // assignment by copying
	{
		if (this == &other) return *this;

		if (sz != other.sz)
		{
			delete[] V;
			sz = other.sz;
			V = new T[sz];
		}

		for (int i = 0; i < sz; i++) // coping every element, original is alive
		{
			V[i] = other.V[i];
		}
		return *this;
	}

	VectorT& operator=(VectorT&& other) // assignment by displacement
	{
		if (this == &other) return *this;

		delete[] V; // deleting old
		V = other.V;
		sz = other.sz;
		other.V = nullptr; // reseting to zero (pointer)
		other.sz = 0;
		return *this;
	}

	inline int size() const { return sz; } // size getter

	inline T& elem(int i) // element getter
	{
		if (i < 0 || i >= sz)
			throw "Invalid index";
		return V[i];
	}

	const inline T& elem(int i) const // element getter
	{
		if (i < 0 || i >= sz)
			throw "Invalid index";
		return V[i];
	}

	T& operator[](int i) // index access
	{
		if (i < 0 || i >= sz)
			throw "Invalid index";
		return V[i];
	}

	const T& operator[](int i) const // index access
	{
		if (i < 0 || i >= sz)
			throw "Invalid index";
		return V[i];
	}

	void print();

	void resize(int newsz) // changing the size of vector
	{
		if (newsz <= 0)
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

	template <typename U>
	friend void equalize(VectorT<U>& a, VectorT<U>& b);

	template <typename U>
	friend VectorT<U> operator+(const VectorT<U>& a, const VectorT<U>& b);

	template <typename U>
	friend VectorT<U> operator-(const VectorT<U>& a, const VectorT<U>& b);
};

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

	if (a.sz != b.sz) // comparing sizes
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

	if (a.sz != b.sz) // comparing sizes
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
std::ostream& operator<<(std::ostream& os, VectorT<T>& V)
{
	for (int i = 0; i < V.size(); i++)
	{
		os << V[i] << " ";
	}
	return os;
}

template <typename T>
void VectorT<T>::print()
{
	std::cout << "[ ";
	for (int i = 0; i < sz; i++)
	{
		std::cout << V[i] << " " ;
	}
	std::cout << "]\n";
}

template <>
void VectorT<E10>::print()
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
void VectorT<Satur>::print()
{
	std::cout << "[ ";
	for (int i = 0; i < sz; i++)
	{
		V[i].print();
		std::cout << " ";
	}
	std::cout << "]\n";
}