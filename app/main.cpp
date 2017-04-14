#include <iostream>
#include <algorithm>
#include <string.h>

#include "find_2_appear_once_number.h"
#include "find_max_commonfactor.h"
#include "list.h"

#include "interview.h"
#include "base_function.h"

using namespace std;

typedef struct _ll
{
    char id;
    struct slist_node node;
}ll;

static void list_test(void)
{
    struct slist_head head = {0};
    struct slist_node *pList = NULL;
    ll *pp = NULL;

    ll t1, t2, t3;

    cout << "****************test hash list start******************" << endl;

    t1.id = 0x31;
    t2.id = 0x32;
    t3.id = 0x33;
    INIT_SLIST_NODE(&t1.node);
    INIT_SLIST_NODE(&t2.node);
    INIT_SLIST_NODE(&t3.node);

    slist_add_head(&t1.node, &head);
    slist_add_head(&t2.node, &head);
    slist_add_head(&t3.node, &head);

    slist_for_each(pList, &head)
    {
        pp = slist_entry(pList, ll, node);
    }
    cout << "id = " << pp->id << endl;

    slist_del(&t2.node);

    slist_for_each(pList, &head)
    {
        pp = slist_entry(pList, ll, node);
        cout << "id = " << pp->id << endl;
    }

    cout << "****************test hash list end******************" << endl;
}

//=============================================================================
//test routine
static void test_interview()
{
    cTestInterView view;

    cout << "****************test interview start******************" << endl;

    view.equation_transfer(5);
    view.delete_repeat_num();


    char sRep[] = {" 89 789aw dr t"};

    view.delete_appoint_character(sRep, '8');

    string dst = "aaabc", src = "aab";

    cout << "end " << view.bruteforce_str(dst, src) << endl;

    cout << "end " << view.bruteforce1_str(dst, src) << endl;

    cout << "****************test interview end******************" << endl;
}

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(NULL == str || length == 0)
            return;

        int len = 0;
        int n = 0;
        while(str[len]) {
            if(str[len] == ' ')
                n++;
            len++;
        }

        //空间不够或者不需要替换,退出
        if(n == 0 || len + n*2 > length) return;

        char *back  = str + len;
        char *nback = str + len + n*2;

        while(back != str) {
            if(*back == ' ') {
                *nback--  = '0';
                *nback--  = '2';
                *nback--  = '%';
            }
            else {
                *nback-- = *back;
            }
            back--;
        }
        if(*back == ' ') {
            *nback--  = '0';
            *nback--  = '2';
            *nback--  = '%';
        }
    }
};

int main()
{
    cout << "The Art of Programming!" << endl;

    test_find_once_number();
    test_find_commfactor();
    list_test();
    test_interview();

    cout << "str_len: " << str_len("NULL") << endl;

    return 0;
}

