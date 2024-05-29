#pragma once
#ifndef DARRAY_H_
#define DARRAY_H_

#include <stdio.h>
#include <new>

namespace ary
{
	template<class _Ty> // for more type a array
	class dynamic_array
	{
	private:
		_Ty* array; // Dynamic array
		size_t size_array; // size_t for size was never < 0;
	public:
		dynamic_array() noexcept : array(nullptr), size_array(0) {};
		explicit dynamic_array(size_t _size);
		dynamic_array(const dynamic_array& d) noexcept;
		~dynamic_array() noexcept;

		// methodes;
		bool is_empty() noexcept;
		bool is_full() noexcept;

		size_t size() noexcept;

		_Ty& at(size_t index); // return [index] with throw if exit from dioprobe

		_Ty* begin() noexcept; // return iterator for first element
		_Ty* end() noexcept; // return iterator for end + 1 element

		_Ty& operator[](size_t index) noexcept; // for give element [index]
		_Ty& operator[](size_t index) const noexcept; // for give element [index] const

		dynamic_array& operator=(const dynamic_array& d) noexcept;
	};
}
#endif //!DARRAY_H_

namespace ary
{
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
	inline dynamic_array<_Ty>::dynamic_array(const dynamic_array& d) noexcept
	{
		array	   = static_cast<_Ty>(d.array);
		size_array = static_cast<size_t>(d.size_array);
	}

	template<class _Ty>
	inline dynamic_array<_Ty>::~dynamic_array() noexcept {
		delete[] array;
	}

	template<class _Ty>
	inline bool dynamic_array<_Ty>::is_empty() noexcept {
		if (size_array == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	template<class _Ty>
	inline bool dynamic_array<_Ty>::is_full() noexcept {
		if (size_array > 0) { 
			return true; 
		}
		else { 
			return false; 
		}
	}

	template<class _Ty>
	inline size_t dynamic_array<_Ty>::size() noexcept {
		return static_cast<size_t>(size_array);
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
	inline _Ty* dynamic_array<_Ty>::begin() noexcept {
		return static_cast<_Ty>(array);
	}

	template<class _Ty>
	inline _Ty* dynamic_array<_Ty>::end() noexcept {
		return static_cast<_Ty>(&array[size_array]);
	}

	template<class _Ty>
	inline _Ty& dynamic_array<_Ty>::operator[](size_t index) noexcept {
		return static_cast<_Ty>(array[index]);
	}

	template<class _Ty>
	inline _Ty& dynamic_array<_Ty>::operator[](size_t index) const noexcept {
		return static_cast<_Ty>(array[index]);
	}

	template<class _Ty>
	inline dynamic_array<_Ty>& dynamic_array<_Ty>::operator=(const dynamic_array& d) noexcept
	{
		if (this == &d)
			return *this;
		delete[] array;
		size_array = d.size_array;
		array = new _Ty[size_array];
		array = d.array;
		return *this;
	}
}