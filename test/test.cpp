#include "../DataStructures/include/DS/Array.h"
#include "../DataStructures/include/DS/Vector.h"
#include <iostream>

int main()
{
    {
        ds::Array<int, 5> a;
        a[0] = 1;
        a[1] = 9;
        a[2] = 3;
        a[3] = 6;
        a[4] = 7;

        for(int i : a) 
            printf("%d ", i);
        printf("\n");
    }

    {
        ds::Vector<int> a;
        a.push(5);
        a.push(2);
        a.push(6);
        a.push(7);
        a.push(4);

        for(int i : a)
            printf("%d ", i);
        printf("\n");
    }
}
