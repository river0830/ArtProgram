//=============================================================================
//hash
//http://blog.csdn.net/wuzhekai1985/article/details/6626228
//二叉树
//http://blog.csdn.net/zhaojinjia/article/details/9314989
//http://blog.chinaunix.net/uid-26548237-id-3476141.html
//=============================================================================

#include <iostream>

#include "interview.h"

using namespace std;

//=============================================================================
//华为等式变换
//1 2 3 4 5 6 7 8 9 = x
//'0' == '+', '1' == "-", '2' == " "
static string get_3symbol(int num)
{
    string symbol = "";
    int r = 0;

    while(num)
    {
        r    = num % 3;
        num /= 3;

        symbol += (r + '0');
    }

    int n = 9 - symbol.size();
    for(int i = 0; i < n; i++) symbol += '0';

    return symbol;
}

void equation_transfer(int number)
{
    const int n3power8 = 6561; //3 ^ 8
    int transfer_count = 0;

    cout << "equation_transfer: " << number << endl;

    for(int i = 0; i < n3power8; i++)
    {
        int x = 0, y = 0;
        string symbol = get_3symbol(i);

        for(int j = 8; j >= 0; j--)
        {
            switch(symbol[j])
            {
            case '0':
                x += y;
                y = 9 - j;
                break;

            case '1':
                x += y;
                y = -(9 - j);
                break;

            case '2':
                if(y < 0)
                    y = y * 10 - (9 - j);
                else
                    y = y * 10 + (9 - j);
                break;

            default: break;
            }
        }

        if((x + y) == number)
        {
            transfer_count++;
            cout << symbol << endl;
        }
    }

    cout << "transfer count " << transfer_count << endl;
}

//=============================================================================
//test routine
void test_interview()
{
    equation_transfer(5);
}
