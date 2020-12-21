#pragma once

#include "Iterator.h"
#include <utility>
#include <iostream>
namespace ds
{
	template<typename T>
	class Vector
	{
	public:
		using DataType = typename T;
		using Iterator = Iterator<Vector<T>>;
	private:
		T* m_Data;
		size_t m_Size;
		size_t m_Capacity;
	public:
		Vector()
			:m_Size(0), m_Capacity(1)
		{
			m_Data = new T[1];
		}

		Vector(size_t capacity)
			:m_Size(0), m_Capacity(capacity)
		{
			m_Data = new T[capacity];
		}

		~Vector()
		{
			delete[] m_Data;
		}

		void resize(size_t capacity)
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

		void pushback(const T& value)
		{
			if (m_Size >= m_Capacity)
				resize(m_Size * 2);

			m_Data[m_Size++] = value;
		}

		void pushback(T&& value)
		{
			if (m_Size >= m_Capacity)
				resize(m_Size * 2);
			std::cout << "temp\n";
			m_Data[m_Size++] = std::move(value);
		}

		template<typename... Args>
		T& emplaceback(Args&&... args)
		{
			if (m_Size >= m_Capacity)
				resize(m_Size + 1);

			m_Data[m_Size] = T(std::forward<Args>(args)...);
			return m_Data[m_Size++];
		}

		T popback() // Complete this later
		{
			if (m_Size > 0)
			{
				m_Size--;
			}
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