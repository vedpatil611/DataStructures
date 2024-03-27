#pragma once

#include <functional>
#include <iostream>
#include <utility>

#include "Iterator.h"

namespace ds
{
	template <typename T>
	class Vector
	{
	public:
		using DataType = T;
		using VectorIterator = Iterator<Vector<T>>;

	private:
		T *m_Data;
		size_t m_Size;
		size_t m_Capacity;

	public:
		Vector(size_t capacity = 2)
			: m_Size(0), m_Capacity(capacity)
		{
			m_Data = (T *)::operator new(2 * sizeof(T));
		}

		~Vector()
		{
			for (size_t i = 0; i < m_Capacity; ++i)
				m_Data[i].~T();

			::operator delete(m_Data, m_Capacity * sizeof(T));
		}

		const T *data()
		{
			return m_Data;
		}

		void reserve(size_t capacity)
		{
			T *newData = (T *)::operator new(capacity * sizeof(T));

			if (m_Size > capacity)
				m_Size = capacity;

			for (size_t i = 0; i < m_Size; ++i)
				newData[i] = std::move(m_Data[i]);

			::operator delete(m_Data, m_Capacity * sizeof(T));

			m_Data = newData;
			m_Capacity = capacity;
		}

		void push(const T &value)
		{
			if (m_Size >= m_Capacity)
				reserve(m_Size * 2);

			m_Data[m_Size++] = value;
		}

		void push(T &&value)
		{
			if (m_Size >= m_Capacity)
				reserve(m_Size * 2);
			m_Data[m_Size++] = std::move(value);
		}

		template <typename... Args>
		T &emplace(Args &&...args)
		{
			if (m_Size >= m_Capacity)
				reserve(m_Size * 2);

			new (&m_Data[m_Size]) T(std::forward<Args>(args)...);
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
			for (size_t i = 0; i < m_Size; ++i)
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

		// Functional
		void forEach(std::function<void(T &)> &func)
		{
			for (int i = 0; i < m_Size; ++i)
				func(m_Data[i]);
		}

		void forEach(std::function<void(T &)> const &func)
		{
			for (int i = 0; i < m_Size; ++i)
				func(m_Data[i]);
		}

		template <typename ReturnDataType>
		Vector<ReturnDataType> map(std::function<ReturnDataType(T &)> &func)
		{
			Vector<ReturnDataType> returnData;
			returnData.reserve(m_Size);

			for (int i = 0; i < m_Size; ++i)
				returnData.emplace(func(m_Data[i]));

			return returnData;
		}

		template <typename ReturnDataType>
		Vector<ReturnDataType> map(std::function<ReturnDataType(T &)> const &func)
		{
			Vector<ReturnDataType> returnData;
			returnData.reserve(m_Size);

			for (int i = 0; i < m_Size; ++i)
				returnData.emplace(func(m_Data[i]));

			return returnData;
		}

		// Overloads
		T &operator[](int index)
		{
			return m_Data[index];
		}

		const T &operator[](int index) const
		{
			return m_Data[index];
		}

		// Iterator functions
		VectorIterator begin()
		{
			return VectorIterator(m_Data);
		}

		VectorIterator end()
		{
			return VectorIterator(m_Data + m_Size);
		}
	};
};
