//=============================================================================
//hash
//http://blog.csdn.net/wuzhekai1985/article/details/6626228
//二叉树
//http://blog.csdn.net/zhaojinjia/article/details/9314989
//http://blog.chinaunix.net/uid-26548237-id-3476141.html
//art program blog
//http://blog.csdn.net/zlei2013141/article/details/7007389
//http://www.cppblog.com/ant/archive/2007/10/12/32886.html
//http://kb.cnblogs.com/page/176818/
//=============================================================================

#include <iostream>
#include <algorithm>
#include <string>

#include <stdio.h>
#include <string.h>

#include "interview.h"

using namespace std;

//=============================================================================
//KMP 串匹配
int cTestInterView::bruteforce_str(string &dst, string &src)
{
    size_t len_dst = dst.length(), len_src = src.length();

    show_tips();
    cout << "brute force search: " << endl;

    if(len_dst < 1 || len_src < 1 || len_src > len_dst) return -1;


    for(size_t i = 0; i <= len_dst - len_src; i++)
    {
        size_t j = 0;

        for(j = 0; j < len_src; j++)
        {
            if(dst[i + j] != src[j]) break;
        }

        if(j == len_src) return i;
    }

    return -1;
}

int cTestInterView::bruteforce1_str(const char *dst, const char *src)
{
    show_tips();
    cout << "brute force1 search: " << endl;

    if(dst == NULL || src == NULL) return -1;

    int i = 0, j = 0;

    while(dst[i+j] && src[j])
    {
        if(dst[i+j] == src[j])
        {
            j++;
        }
        else
        {
            j = 0;
            i++;
        }
    }

    return (src[j] == 0 ? i : -1);
}

void cTestInterView::kmp_get_next(const string &src, vector<int> &next)
{

}

int cTestInterView::kmp_str(string &dst, string &src)
{
    if(dst.length() < 1 || src.length() < 1) return -1;

    return 0;
}

//=============================================================================
//华为等式变换
//1 2 3 4 5 6 7 8 9 = x
//'0' == '+', '1' == "-", '2' == " "
void cTestInterView::get_3symbol(int num, string &str)
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

void cTestInterView::equation_transfer(int number)
{
    const int n3power8 = 6561; //3 ^ 8
    string symbol;
    int transfer_count = 0;

    show_tips();
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
void cTestInterView::delete_repeat_num(void)
{
    static int array[] = {2, 3, 8, 4, 5, 5, 9, 8, 9};
    int i, j;

    show_tips();

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

void cTestInterView::delete_appoint_character(char *str, char c)
{
    char *pre, *end;

    if(NULL == str) return;

    show_tips();

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

void cTestInterView::show_tips()
{
    cout << "---.---.---.---.---.---.---" << endl;
}
