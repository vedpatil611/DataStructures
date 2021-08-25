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
        a.pushback(5);
        a.pushback(2);
        a.pushback(6);
        a.pushback(7);
        a.pushback(4);

        for(int i : a)
            printf("%d ", i);
        printf("\n");
    }
}
