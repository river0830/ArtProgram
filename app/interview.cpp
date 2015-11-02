//=============================================================================
//hash
//http://blog.csdn.net/wuzhekai1985/article/details/6626228
//二叉树
//http://blog.csdn.net/zhaojinjia/article/details/9314989
//http://blog.chinaunix.net/uid-26548237-id-3476141.html
//=============================================================================

#include <iostream>
#include <algorithm>
#include <string>

#include <stdio.h>
#include <string.h>

#include "interview.h"

using namespace std;

//=============================================================================
//华为等式变换
//1 2 3 4 5 6 7 8 9 = x
//'0' == '+', '1' == "-", '2' == " "
static void get_3symbol(int num, string &str)
{
    int r = 0;

    str.clear();

    while(num)
    {
        r    = num % 3;
        num /= 3;

        str += (r + '0');
    }

    int m = 9 - str.size();

    for(int i = 0; i < m; i++) str += '0';
}

static void equation_transfer(int number)
{
    const int n3power8 = 6561; //3 ^ 8
    string symbol;
    int transfer_count = 0;

    cout << "equation_transfer: " << number << endl;

    for(int i = 0; i < n3power8; i++)
    {
        int x = 0, y = 0;

        get_3symbol(i, symbol);

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
//DeleteRepeatNum
static void DeleteRepeatNum(void)
{
    static int array[] = {2, 3, 8, 4, 5, 5, 9, 8, 9};
    int i, j;

    cout << "DeleteRepeatNum e.g." << endl;

    for(i = 0, j = 0; i < sizeof(array) / sizeof(int); i++)
    {
        if(array[i] == array[j]) continue;

        j++;
        if(i != j) swap(array[i], array[j]);
    }

    for(i = 0; i < j+1; i++) cout << array[i] << " ";
    cout << endl;

    cout << endl;
}

static void DeleteAppointChar(char *str, char c)
{
    if(NULL == str) return;

    char *pre, *end;

    pre = end = str;
    while(*pre)
    {
        if(*pre == c)
        {
            pre++;
            continue;
        }

        if(*pre != *end) swap(*pre, *end);

        pre++;
        end++;
    }

    cout << "delete char '" << c << "' count:" << pre - end << endl;
}

//=============================================================================
//test routine
void test_interview()
{
    cout << "**********************************" << endl;
    cout << "test interview start" << endl;

    equation_transfer(5);
    cout << "==================================" << endl;
    DeleteRepeatNum();

    cout << "==================================" << endl;
    char sRep[] = {" 89 789aw dr t"};

    DeleteAppointChar(sRep, '8');

    cout << "test interview end" << endl;
    cout << "**********************************" << endl;
}
