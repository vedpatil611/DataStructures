#include "../DataStructures/include/DS/Array.h"
#include "../DataStructures/include/DS/Vector.h"
#include <iostream>
#include <vector>

struct Data 
{
    int x, y, z;

    Data()
        :x(0), y(0), z(0)
    {
        printf("Created\n");
    }

    Data(int x, int y, int z)
        :x(x), y(y), z(z)
    {
        printf("Created\n");
    }

    Data(const Data& other)
        :x(other.x), y(other.y), z(other.z)
    {
        printf("Copy\n");
    }

    Data(Data&& other)
        :x(other.x), y(other.y), z(other.z)
    {
        printf("Move\n");
    }

    Data& operator=(const Data& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        printf("Copy\n");
        return *this;
    }

    Data& operator=(Data&& other)
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
        printf("----- DS -----\n");
        ds::Vector<Data> a;
        a.emplace();
        a.emplace(3, 5, 6);
        a.emplace(7, 1, 4);
        a.emplace(1, 2, 3);
        a.emplace(9, 8, 7);
    }

    {
        printf("----- STD -----\n");
        std::vector<Data> a;
        a.emplace_back();
        a.emplace_back(3, 5, 6);
        a.emplace_back(7, 1, 4);
        a.emplace_back(1, 2, 3);
        a.emplace_back(9, 8, 7);
    }
}
