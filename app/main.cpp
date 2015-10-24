#include <iostream>

#include "find_2_appear_once_number.h"
#include "find_max_commonfactor.h"
#include "list.h"

#include "interview.h"

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
}

static void DeleteRepeatNum(void)
{
    static int array[] = {2, 3, 4, 4, 5, 6, 8, 8, 9};
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

int main()
{
    cout << "The Art of Programming!" << endl;

    test_find_once_number();
    test_find_commfactor();
    list_test();

    DeleteRepeatNum();

    test_interview();

    return 0;
}

