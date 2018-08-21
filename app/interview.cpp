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
#include <map>
#include <hash_map>
#include <unordered_map>

#include "interview.h"

using namespace std;
//using namespace __gnu_cxx;
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

void cTestInterView::twoSums(vector<int> &dst, int target)
{
    show_tips();

    cout << "towSums" << endl;

    cout << "dst vector: ";
    for_each(dst.cbegin(), dst.cend(), [](const int& val){cout << val << " ";});
    cout << endl;
    for(auto val:dst) cout << val << " ";
    cout << endl;

    __gnu_cxx::hash_map<int,int> tmp;

    size_t len = dst.size();
    for(size_t i = 0; i < len; i++)
    {
        int value = target - dst[i];
        if(tmp.find(value) != tmp.end()) {
            cout << "hash_map -> " << target << endl;
            cout << tmp[value] << ":" << i << " is find" << endl;
            break;
        }
        tmp[dst[i]] = i;
    }

    map<int, int> tm;
    vector<int> ret;
    for(size_t i = 0; i < len; i++)
    {
        int value = target - dst[i];
        if(tm.find(value) != tm.end()) {
            cout << "map -> " << target << endl;
            cout << tm[value] << ":" << i << " is find" << endl;
            ret.push_back(tm[value]);
            ret.push_back(i);
            break;
        }
        //tm.insert(make_pair(dst[i], i));
        tm[dst[i]] = i;
    }

    unordered_map<int, int> tmo;
    vector<int> reto;
    for(size_t i = 0; i < len; i++)
    {
        int value = target - dst[i];
        if(tmo.find(value) != tmo.end()) {
            cout << "unordered map -> " << target << endl;
            cout << tmo[value] << ":" << i << " is find" << endl;
            reto.push_back(tm[value]);
            reto.push_back(i);
            break;
        }
        //tm.insert(make_pair(dst[i], i));
        tmo[dst[i]] = i;
    }
}

void cTestInterView::threeSumsZero(vector<int> &dst, int flag)
{
    show_tips();

    cout << "threeSumsZero" << endl;

    int len = dst.size();
    if(len < 3) return;

    vector<vector<int> > ivv;

    cout << "source dst" << endl;
    for_each(dst.cbegin(), dst.cend(), [](const int& val){cout << val << " ";});
    cout << endl;

    sort(dst.begin(), dst.end());
#if 0
    if(flag == 0) {
        dst.erase(unique(dst.begin(), dst.end()), dst.end());
        len = dst.size();
    }
#endif
    cout << "source sort dst" << endl;
    for_each(dst.cbegin(), dst.cend(), [](const int& val){cout << val << " ";});
    cout << endl;

    for(int i = 0; i < len - 2; i++)
    {
        //obvious break;
        if(dst[i] > 0) break;

        //skip head repeat item
        if(flag == 0) {
            if(i > 0 && dst[i-1] == dst[i]) continue;
        }

        int j = i+1;
        int k = len - 1;

        while(j < k)
        {
            if(dst[i] + dst[j] + dst[k] < 0) {
                j++;
            }
            else if(dst[i] + dst[j] + dst[k] > 0) {
                k--;
            }
            else {
                ivv.push_back({dst[i], dst[j], dst[k]});
                if(flag == 1) {
                    if(dst[i] + dst[j+1] + dst[k] == 0) {
                        j++;
                    }
                    else {
                        k--;
                    }
                }
                else {
                    //skip tail repeat item
                    while(j < k && dst[k - 1] == dst[k])
                        k--;
                    //skip middle repeat item
                    while(j < k && dst[j] == dst[j+1])
                        j++;
                    j++;
                    k--;
                }
            }
        }
    }

    cout << "find the zero items:" << endl;
    for(auto v1 = ivv.cbegin(); v1 != ivv.cend(); v1++)
    {
        for(auto v2 = v1->cbegin(); v2 != v1->cend(); v2++)
        {
            cout << *v2 << " ";
        }
        cout << endl;
    }
}

void cTestInterView::iterEraseDeleteTest()
{
    show_tips();

    vector<int> tmv  = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    map<int, int> tmp;

    for(size_t i = 0; i < 10; i++)
    {
        tmp[i] = i + 2;
    }

    cout << "vector operation" << endl;
    for_each(tmv.cbegin(), tmv.cend(), [](const int& val){cout << val << " ";});
    cout << endl;

    for(auto iter = tmv.begin(); iter != tmv.end();)
    {
        if(0 == *iter % 3)
        {
            tmv.erase(iter);
        }
        else
        {
            iter++;
        }
    }
    for_each(tmv.cbegin(), tmv.cend(), [](const int& val){cout << val << " ";});
    cout << endl;

    cout << "map operation" << endl;
    //for_each(tmp.cbegin(), tmp.cend(), [](auto &v){cout << v.first << " ";}); //c++14
    for_each(tmp.cbegin(), tmp.cend(), [](const pair<int, int> &v){cout << v.first << " ";});
    cout << endl;

    for(auto iter = tmp.begin(); iter != tmp.end();)
    {
        if(0 == iter->first % 3)
        {
            tmp.erase(iter++);
        }
        else
        {
            iter++;
        }
    }
    for(auto &v : tmp)
        cout << v.first << " ";
    cout << endl;
}

void cTestInterView::show_tips()
{
    cout << "---.---.---.---.---.---.---" << endl;
}
