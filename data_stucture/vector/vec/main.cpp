#include "vec.h"
#include <iostream>

using namespace std;

int main()
{
    Vector <int>v(3);

    v.push_back(10);
    v.push_back(20);
    v.insert(1, 15);

    v.print();

    return 0;
}
