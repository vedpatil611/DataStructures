#pragma once

#include "Iterator.h"
#include <cstring>
#include <functional>

namespace ds
{
	template <typename T, unsigned int S>
	class Array
	{
	public:
		using DataType = T;
		using ArrayIterator = Iterator<Array<T, S>>;

	private:
		T m_Array[S];

	public:
		Array() = default;

		Array(const T *other)
		{
			std::memcpy(m_Array, other, S * sizeof(T));
		}

		Array(const Array &other)
		{
			m_Array = other.data();
		}

		T *data()
		{
			return begin();
		}

		const T *data() const
		{
			return begin();
		}

		T &operator[](int index)
		{
			return m_Array[index];
		}

		const T &operator[](int index) const
		{
			return m_Array[index];
		}

		constexpr unsigned int size() const
		{
			return S;
		}

		// Functional
		void forEach(std::function<void(T &)> &func)
		{
			for (int i = 0; i < S; ++i)
				func(m_Array[i]);
		}

		void forEach(std::function<void(T &)> const &func)
		{
			for (int i = 0; i < S; ++i)
				func(m_Array[i]);
		}

		template <typename ReturnDataType>
		Array<ReturnDataType, S> map(std::function<ReturnDataType(T &)> &func)
		{
			Array<ReturnDataType, S> returnData;

			for (int i = 0; i < S; ++i)
				returnData[i] = func(m_Array[i]);

			return returnData;
		}

		template <typename ReturnDataType>
		Array<ReturnDataType, S> map(std::function<ReturnDataType(T &)> const &func)
		{
			Array<ReturnDataType, S> returnData;

			for (int i = 0; i < S; ++i)
				returnData[i] = func(m_Array[i]);

			return returnData;
		}

		ArrayIterator begin()
		{
			return ArrayIterator(m_Array);
		}

		ArrayIterator end()
		{
			return ArrayIterator(m_Array + S);
		}
	};
}
