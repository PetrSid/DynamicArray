#pragma once
#ifndef DARRAY_H_
#define DARRAY_H_

#include <stdio.h>
#include <new>

template<class _Ty> // for more type a array
class dynamic_array
{
private:
	_Ty* array; // Dynamic array
	size_t size_array; // size_t for size was never < 0;
public:
	dynamic_array() noexcept : array(nullptr), size_array(0) {};
	explicit dynamic_array(size_t _size);
	dynamic_array(const dynamic_array& d);
	~dynamic_array() noexcept;

	// methodes;

	_Ty& at(size_t index); // return [index] with throw if exit from dioprobe

	_Ty* begin(); // return iterator for first element
	_Ty* end(); // return iterator for end + 1 element

	_Ty& operator[](size_t index); // for give element [index]
	_Ty& operator[](size_t index) const; // for give element [index] const

	dynamic_array& operator=(const dynamic_array& d);
};
#endif //!DARRAY_H_


template<class _Ty>
inline dynamic_array<_Ty>::dynamic_array(size_t _size)
{
	try {
		size_array = _size;
		array = new _Ty[size_array]; // Memory allocation for Array
	}
	catch (const std::bad_alloc& ex) {
		printf("%s ", ex.what());
	}
}

template<class _Ty>
inline dynamic_array<_Ty>::dynamic_array(const dynamic_array& d)
{
	array = d.array;
	size_array = d.size_array;
}

template<class _Ty>
inline dynamic_array<_Ty>::~dynamic_array() noexcept {
	delete[] array;
}

template<class _Ty>
inline _Ty& dynamic_array<_Ty>::at(size_t index)
{
	try {
		if (index < 0 || index >= size_array)
			throw "Bad index array at call throw";
		return array[index];
	}
	catch (const char* ex) {
		printf("%s ", ex);
	}
}

template<class _Ty>
inline _Ty* dynamic_array<_Ty>::begin() {
	return array;
}

template<class _Ty>
inline _Ty* dynamic_array<_Ty>::end() {
	return &array[size_array];
}

template<class _Ty>
inline _Ty& dynamic_array<_Ty>::operator[](size_t index) {
	return array[index];
}

template<class _Ty>
inline _Ty& dynamic_array<_Ty>::operator[](size_t index) const {
	return array[index];
}

template<class _Ty>
inline dynamic_array<_Ty>& dynamic_array<_Ty>::operator=(const dynamic_array& d)
{
	if (this == &d)
		return *this;
	delete[] array;
	size_array = d.size_array;
	array = new _Ty[size_array];
	array = d.array;
	return *this;
}