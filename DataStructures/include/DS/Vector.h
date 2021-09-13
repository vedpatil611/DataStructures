#pragma once

#include <utility>
#include <iostream>

namespace ds
{
	template<typename T>
	class VectorIterator
	{
	public:
		using DataType = typename T::DataType;
	private:
		DataType* m_Ptr;
	public:
		VectorIterator(DataType* ptr)
			: m_Ptr(ptr) {}

		VectorIterator& operator++()
		{
			++m_Ptr;
			return *this;
		}

		VectorIterator operator++(int)
		{
			VectorIterator iterator = *this;
			++m_Ptr;
			return iterator;
		}

		VectorIterator& operator--()
		{
			--m_Ptr;
			return *this;
		}

		VectorIterator operator--(int)
		{
			VectorIterator iterator = *this;
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

		bool operator==(const VectorIterator& other)
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const VectorIterator& other)
		{
			return m_Ptr != other.m_Ptr;
		}
	};

	template<typename T>
	class Vector
	{
	public:
		using DataType = T;
		using Iterator = VectorIterator<Vector<T>>;
	private:
		T* m_Data;
		size_t m_Size;
		size_t m_Capacity;
	public:
		Vector(size_t capacity = 2)
			:m_Size(0), m_Capacity(capacity)
		{
			m_Data = new T[capacity];
		}

		~Vector()
		{
			delete[] m_Data;
		}

		void reserve(size_t capacity)
		{
			T* newData = new T[capacity];

			if (m_Size > capacity)
				m_Size = capacity;

			for (size_t i = 0; i < m_Size; ++i)
				newData[i] = std::move(m_Data[i]);

			delete[] m_Data;
			m_Data = newData;
			m_Capacity = capacity;
		}

		void push(const T& value)
		{
			if (m_Size >= m_Capacity)
				reserve(m_Size * 2);

			m_Data[m_Size++] = value;
		}

		void push(T&& value)
		{
			if (m_Size >= m_Capacity)
				reserve(m_Size * 2);
			m_Data[m_Size++] = std::move(value);
		}

		template<typename... Args>
		T& emplace(Args&&... args)
		{
			if (m_Size >= m_Capacity)
				reserve(m_Size + 1);

			m_Data[m_Size] = T(std::forward<Args>(args)...);
			return m_Data[m_Size++];
		}

		T popback()
		{
			if (m_Size > 0)
			{
				m_Size--;
				m_Data[m_Size].~T();
			}
		}

		void clear() 
		{
			for(size_t i = 0; i < m_Size; ++i)
				m_Data[i].~T();

			m_Size = 0;
		}

		size_t size() const
		{
			return m_Size;
		}

		size_t capacity() const
		{
			return m_Capacity;
		}

		T& operator[](int index)
		{
			return m_Data[index];
		}

		const T& operator[](int index) const
		{
			return m_Data[index];
		}

		Iterator begin()
		{
			return Iterator(m_Data);
		}

		Iterator end()
		{
			return Iterator(m_Data + m_Size);
		}
	};
}
