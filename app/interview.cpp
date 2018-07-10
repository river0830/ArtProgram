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

    size_t count = 0;
    size_t i = 0, j = 0;
    for(; i <= len_dst - len_src; i++)
    {
        for(j = 0; j < len_src; j++)
        {
            if(dst[i + j] != src[j]) break;
        }

        count++;
        if(j == len_src)
        {
            cout << "brute force pattern is " << i << endl;
            break;
        }
    }
    cout << "brute force count is " << count * j << endl;

    return i;
}

int cTestInterView::bruteforce1_str(const char *dst, const char *src)
{
    show_tips();
    cout << "brute force1 search: " << endl;

    if(dst == NULL || src == NULL) return -1;

    int i = 0, j = 0, z;

    while(dst[i++]);
    while(src[j++]);
    if(i < j) return -1;

    i = j = z = 0;
    while(dst[i+j])
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

        if(src[j] == 0)
        {
            z++;
            cout << "brute force1 pattern is " << i++ << endl;
            j = 0;
        }
    }

    return (z > 0 ? z : -1);
}

static void buildNext(const char *pattern, int length, unsigned int* next)
{

}

void cTestInterView::kmp_get_next(const string &src, vector<int> &next)
{
    int len = src.length();

    int j = 0, k = -1;
    next[0] = -1;
    while(j < len - 1)
    {
        if(k == -1 || src[j] == src[k])
        {
            next[++j] = ++k;
        }
        else
            k = next[k];
    }

    cout << "kmp next array:" << endl;
    for(vector<int>::iterator iter = next.begin(); iter != next.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int cTestInterView::kmp_str(string &dst, string &src)
{
    int dlen = dst.length(), slen = src.length();

    if(dlen < slen) return -1;

    show_tips();
    cout << "kmp search: " << endl;

    vector<int> kmp_next(slen);
    kmp_get_next(src, kmp_next);

    int d_len=0, s_len=0, count = 0;
    while(d_len < dlen && s_len < slen)
    {
        if(s_len == -1 || src[s_len] == dst[d_len])
        {
            d_len++;
            s_len++;
        }
        else
        {
            s_len = kmp_next[s_len];
        }

        count++;
    }

    if(s_len == slen)
    {
        cout << "kmp pattern is " << d_len - s_len << endl;
    }

    cout << "kmp count " << count << endl;

    return d_len - s_len;
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

void cTestInterView::fast_mod(unsigned int x, unsigned int n, unsigned int m)
{
    show_tips();

    cout << "fast mod by 2^ " << endl;

    int a = 1, b = x, t = n, count = 0;
    while(1)
    {
        if(n == 0) break;
        if(n & 0x01)
        {
            a = a * b % m;
        }
        b = b * b % m;
        n >>= 1;
        count++;
    }
    cout << "fast mod count " << count << endl;
    cout << x << "^" << t << " mod " << m << " is " << a << endl;
}

void cTestInterView::show_tips()
{
    cout << "---.---.---.---.---.---.---" << endl;
}
