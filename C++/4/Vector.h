#pragma once

#include <iostream>

template <typename T> class Vector
{
private:

	T* V;
	int sz;

public:

	Vector(int s) // constructor with size
	{
		if (s < 0)
			throw "Incorrect vector size";
		sz = s;
		V = new T[sz];
	}

	Vector() // default size = 0
	{
		sz = 0;
		V = new T[sz];
	}

	Vector(const Vector& other) : Vector(other.sz) // copy constructor, original is alive
	{
		for (int i = 0; i < sz; i++)
		{
			V[i] = other.V[i];
		}
	}

	Vector(Vector&& other) // displacement constructor, data was taken from a temporary object
	{
		V = other.V;
		sz = other.sz;
		other.V = nullptr;
		other.sz = 0;
	}

	~Vector()
	{
		delete[] V;
	}

	Vector& operator=(const Vector& other) // assignment by copying
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

	Vector& operator=(Vector&& other) // assignment by displacement
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

	T& operator[](int i) // index access
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
	friend void equalize(Vector<U>& a, Vector<U>& b);

	template <typename U>
	friend Vector<U> operator+(const Vector<U>& a, const Vector<U>& b);

	template <typename U>
	friend Vector<U> operator-(const Vector<U>& a, const Vector<U>& b);
};

template <typename T>
void equalize(Vector<T>& a, Vector<T>& b)
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
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
	Vector<T> first = a;
	Vector<T> second = b;

	if (a.sz != b.sz) // comparing sizes
	{
		equalize(first, second);
	}

	Vector<T> sum(first.sz);

	for (int i = 0; i < first.sz; i++)
	{
		sum.V[i] = first.V[i] + second.V[i];
	}

	return sum;
}

template <typename T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b)
{
	Vector<T> first = a;
	Vector<T> second = b;

	if (a.sz != b.sz) // comparing sizes
	{
		equalize(first, second);
	}

	Vector<T> sub(first.sz);

	for (int i = 0; i < first.sz; i++)
	{
		sub.V[i] = first.V[i] - second.V[i];
	}

	return sub;
}

template <typename T>
void Vector<T>::print()
{
	for (int i = 0; i < sz; i++)
	{
		V[i].print();
	}
}

template <>
void Vector<double>::print()
{
	std::cout << "[ ";
	for (int i = 0; i < sz; i++)
	{
		std::cout << V[i] << " ";
	}
	std::cout << "]\n";
}

template <>
void Vector<int>::print()
{
	std::cout << "[ ";
	for (int i = 0; i < sz; i++)
	{
		std::cout << V[i] << " ";
	}
	std::cout << "]\n";
}
