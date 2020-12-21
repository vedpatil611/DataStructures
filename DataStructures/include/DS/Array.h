#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include "Iterator.h"

namespace ds
{
	template<typename T, unsigned int S>
	class Array
	{
	public:
		using DataType = typename T;
		using Iterator = Iterator<Array<T, S>>;
	private:
		T m_Array[S];
	public:
		Array() = default;

		Array(const T* other)
		{
			memcpy(m_Array, other, S * sizeof(T));
		}

		Array(const Array& other)
		{
			m_Array = other.data();
		}

		T* data()
		{
			return begin();
		}
		
		const T* data() const 
		{
			return begin();
		}
		
		T& operator[](int index)
		{
			return m_Array[index];
		}
		
		const T& operator[](int index) const
		{
			return m_Array[index];
		}

		constexpr unsigned int getSize() const
		{
			return S;
		}

		Iterator begin()
		{
			return Iterator(&m_Array[0]);
		}

		Iterator end()
		{
			return Iterator(&m_Array[0] + S);
		}
	};
}

#endif