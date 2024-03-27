#include "../DataStructures/include/DS/Array.h"
#include "../DataStructures/include/DS/Iterator.h"
#include "../DataStructures/include/DS/Vector.h"
#include <iostream>
#include <math.h>
#include <vector>

struct Data
{
	int x, y, z;

	Data()
		: x(0), y(0), z(0)
	{
		printf("Created\n");
	}

	Data(int x, int y, int z)
		: x(x), y(y), z(z)
	{
		printf("Created\n");
	}

	Data(const Data &other)
		: x(other.x), y(other.y), z(other.z)
	{
		printf("Copy\n");
	}

	Data(Data &&other)
		: x(other.x), y(other.y), z(other.z)
	{
		printf("Move\n");
	}

	void print()
	{
		printf("%d, %d, %d\n", x, y, z);
	}

	Data &operator=(const Data &other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		printf("Copy\n");
		return *this;
	}

	Data &operator=(Data &&other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		printf("Move\n");
		return *this;
	}

	~Data()
	{
		printf("Destroy\n");
	}
};

int main()
{
	{
		printf("----- DS memory allocation test start -----\n");
		ds::Vector<Data> a;
		a.emplace();
		a.emplace(3, 5, 6);
		a.emplace(7, 1, 4);
		a.emplace(1, 2, 3);
		a.emplace(9, 8, 7);
		printf("----- DS memory allocation test end -----\n");

		a.forEach([](Data &val)
				  { val.print(); });

		a.map<float>([](Data &val) -> float
					 {
				float squared = (float)(val.x * val.x + val.y * val.y + val.z * val.z);
				return sqrt(squared); })
			.forEach([](auto &val)
					 { printf("%f\n", val); });

		ds::Array<Data, 6> arr(a.data());
		arr.forEach([](Data &data)
					{ data.print(); });
	}

	{
		printf("----- STD memory allocation test start -----\n");

		std::vector<Data> a;
		a.emplace_back();
		a.emplace_back(3, 5, 6);
		a.emplace_back(7, 1, 4);
		a.emplace_back(1, 2, 3);
		a.emplace_back(9, 8, 7);

		printf("----- STD memory allocation test end -----\n");
	}
}
