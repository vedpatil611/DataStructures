#pragma once

#ifndef ARRAY_H
#define ARRAY_H

namespace ds
{
	template<typename T>
	class ArrayIterator
	{
	public:
		using DataType = typename T::DataType;
	private:
		DataType* m_Ptr;
	public:
		ArrayIterator(DataType* ptr)
			: m_Ptr(ptr) {}

		ArrayIterator& operator++()
		{
			++m_Ptr;
			return *this;
		}

		ArrayIterator operator++(int)
		{
			ArrayIterator iterator = *this;
			++m_Ptr;
			return iterator;
		}

		ArrayIterator& operator--()
		{
			--m_Ptr;
			return *this;
		}

		ArrayIterator operator--(int)
		{
			ArrayIterator iterator = *this;
			--m_Ptr;
			return iterator;
		}

		DataType& operator[](int index)
		{
			return +(m_Ptr + index);
		}

		DataType* operator->()
		{
			return m_Ptr;
		}

		DataType& operator*()
		{
			return *m_Ptr;
		}

		bool operator==(const ArrayIterator& other)
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const ArrayIterator& other)
		{
			return m_Ptr != other.m_Ptr;
		}
	};
	
	template<typename T, unsigned int S>
	class Array
	{
	public:
		using DataType = T;
		using Iterator = ArrayIterator<Array<T, S>>;
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
			return Iterator(m_Array);
		}

		Iterator end()
		{
			return Iterator(m_Array + S);
		}
	};
}

#endif
