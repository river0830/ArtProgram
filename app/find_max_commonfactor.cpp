#include <iostream>
#include <utility>
#include "assert.h"

using namespace std;

void find_max_commonfactor(unsigned int a, unsigned int b)
{
    //欧几里德算法
    unsigned int r = 0;

    cout << "a(" << a << ") and b(" << b << ") common factor is: ";

    if(a < b) swap(a, b);
    while(b > 0)
    {
       r = a % b;

       a = b;
       b = r;
    }

    cout << a << endl;
}

void test_find_commfactor(void)
{
    cout << "****************test gcd start******************" << endl;

    find_max_commonfactor(3, 7);
    find_max_commonfactor(544, 119);
    find_max_commonfactor(124, 1024);

    cout << "****************test gcd start******************" << endl;
}
