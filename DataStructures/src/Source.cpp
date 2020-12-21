#include "../include/DS/Vector.h"
#include "../include/DS/Array.h"
#include <iostream>
#include <vector>

struct Vec2
{
	int x,y;

	Vec2() = default;

	Vec2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2(const Vec2& other)
	{
		x = other.x;
		y = other.y;
		std::cout << "Copied\n";
	}

	Vec2(Vec2&& other)
	{
		x = other.x;
		y = other.y;
		std::cout << "Moved\n";
	}

	Vec2& operator=(Vec2 other)
	{
		x = other.x;
		y = other.y;
		std::cout << "Moved\n";
		return other;
	}
};

int main()
{
	/*int t[5] = { 1,2,3,4,5 };
	ds::Array<int, 5> a(t);
	for (int i : a) {
		std::cout << i << std::endl;
	}*/
	Vec2 a = { 3,4 };
	Vec2 b = a;
	std::cout << b.x << " " << b.y << std::endl;
	{
		ds::Vector<Vec2> a;
		a.emplaceback( 5, 5 );
		std::cout << a.capacity() << std::endl;
		a.emplaceback( 1, 1 );
		std::cout << a.capacity() << std::endl;
		a.emplaceback( 9, 6 );
		std::cout << a.capacity() << std::endl;
		a.emplaceback( 4, 1 );
		std::cout << a.capacity() << std::endl;
		a.emplaceback( 0, 1 );
		std::cout << a.capacity() << std::endl;

		for (auto& i : a)
			std::cout << i.x << " " << i.y << std::endl;
	}

	{
		std::vector<Vec2> a;
		a.emplace_back( 5, 5 );
		std::cout << a.capacity() << std::endl;
		a.emplace_back( 1, 1 );
		std::cout << a.capacity() << std::endl;
		a.emplace_back( 9, 6 );
		std::cout << a.capacity() << std::endl;
		a.emplace_back( 4, 1 );
		std::cout << a.capacity() << std::endl;
		a.emplace_back( 0, 1 );
		std::cout << a.capacity() << std::endl;

		for (auto& i : a)
			std::cout << i.x << " " << i.y << std::endl;
	}
	return 0;
}