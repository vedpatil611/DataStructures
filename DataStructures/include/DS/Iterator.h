#pragma once

#ifndef ITERATOR_H
#define ITERATOR_H

namespace ds
{
	template<typename T>
	class Iterator
	{
	public:
		using DataType = typename T::DataType;
	private:
		DataType* m_Ptr;
	public:
		Iterator(DataType* ptr)
			: m_Ptr(ptr) {}

		Iterator& operator++()
		{
			++m_Ptr;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator iterator = *this;
			++m_Ptr;
			return iterator;
		}

		Iterator& operator--()
		{
			--m_Ptr;
			return *this;
		}

		Iterator operator--(int)
		{
			Iterator iterator = *this;
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

		bool operator==(const Iterator& other)
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return m_Ptr != other.m_Ptr;
		}
	};
}

#endif // !ITERATOR_H
