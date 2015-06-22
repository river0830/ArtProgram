#include <iostream>

#include "find_2_appear_once_number.h"
#include "find_max_commonfactor.h"
#include "list.h"

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

int main()
{
    cout << "The Art of Programming!" << endl;

    test_find_once_number();
    test_find_commfactor();
    list_test();

    return 0;
}

