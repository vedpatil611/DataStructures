#include "../DataStructures/include/DS/Array.h"
#include "../DataStructures/include/DS/Vector.h"
#include <iostream>

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
        ds::Vector<Data> a;
        a.push(Data());
        a.push(Data(3, 5, 6));
        a.push(Data(7, 1, 4));
        a.push(Data(1, 2, 3));
        a.push(Data(9, 8, 7));

        //for(int i : a)
            //printf("%d ", i);
        //printf("\n");
    }
}
