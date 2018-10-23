#include <iostream>
#include <algorithm>
#include <string.h>

#include "find_2_appear_once_number.h"
#include "find_max_commonfactor.h"
#include "list.h"

#include "interview.h"
#include "base_function.h"
#include "ring_queue.h"
#include "dp_bag.h"

#include "dt3106_ini.h"
#include "atomict1.h"

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

    view.find_prime(5);
    view.find_prime(1009);

    view.equation_transfer(5);
    view.delete_repeat_num();


    char sRep[] = {" 89 789aw dr t"};

    view.delete_appoint_character(sRep, '8');

    string dst = "ababaaabababababaaabababababaaababaa", src = "ababaaababaa"; //"abaabcaba";

    cout << "end " << view.bruteforce_str(dst, src) << endl;

    cout << "end " << view.bruteforce1_str("src.c_str()c_str()c_str()..c_str()", "c_str()") << endl;

    cout << "end " << view.kmp_str(dst, src) << endl;

    view.fast_mod(5, 0, 5);
    view.fast_mod(0, 2, 5);
    view.fast_mod(2, 1000000000, 77);
    view.fast_mod(12996, 227, 37909);

    vector<int> ss = {0, 4, 3, 2, 0, -3, -1, -3, 1, 0, 0, 5, -2, -1, 5};
    view.twoSums(ss, 1);
    view.twoSums(ss, 0);
    view.twoSums(ss, 6);

    view.threeSumsZero(ss);
    view.threeSumsZero(ss, 0);

    vector<int> ss1 = {1, 1, 1, 0};
    view.threeSumClosest(ss1, -100);

    vector<int> ss2 = {-1, 2, 1, -4};
    view.threeSumClosest(ss2, 1);

    view.iterEraseDeleteTest();
    view.continueSum(72316829);
    view.continueSum1(333764327);
    view.continueSum1(5);
    view.continueSum1(15);
    view.continueSum2(333764327);
    view.continueSum2(5);
    view.continueSum2(15);
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

static unsigned int upper_power_of_2(unsigned int val)
{
    cout << "****************test upper_power_of_2 s******************" << endl;

    cout << "firset move val: " << val << endl;

    unsigned int v = val;

    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;

    cout << "firset move v: " << v << endl;

    #define jimi_b2(x)              (        (x) | (        (x) >>  1))
    #define jimi_b4(x)              ( jimi_b2(x) | ( jimi_b2(x) >>  2))
    #define jimi_b8(x)              ( jimi_b4(x) | ( jimi_b4(x) >>  4))
    #define jimi_b16(x)             ( jimi_b8(x) | ( jimi_b8(x) >>  8))
    #define jimi_b32(x)             (jimi_b16(x) | (jimi_b16(x) >> 16))
    #define jimi_b64(x)             (jimi_b32(x) | (jimi_b32(x) >> 32))

    cout << "second macro move val: " << val << endl;

    unsigned int v1 = val;

    v1 = (jimi_b32(v1 - 1) + 1);

    cout << "second macro move v1: " << v1 << endl;

    cout << "third move val: " << val << endl;

    unsigned int v2 = 2;

    while(v2 < val) v2 <<= 1;

    cout << "third move v2: " << v2 << endl;

    cout << "fourth move val: " << val << endl;

    unsigned int v3 = val >= 2 ? val : 2;

    if(v3 & (v3 - 1))
    {
        unsigned int maxulong = (unsigned int)((unsigned int)~0);
        unsigned int andv = ~(maxulong & (maxulong>>1));

        while((andv & v3) == 0) andv = andv>>1;

        andv <<= 1;

        cout << "fourth move v3: " << andv << endl;
    }

    cout << "****************test upper_power_of_2 e******************" << endl;

    return v2;
}

void test_ringqueue(void)
{
    cout << "****************test RingQueue s******************" << endl;

    RingQueue tq;
    struct tt
    {
        int id;
        int cc;
        short kk;
        char  ss;
    };

    tq.data_size  = sizeof(struct tt);
    tq.queue_size = 10;
    tq.buf        = new unsigned char[10 * sizeof(struct tt)];

    tq.front = tq.size = 0;
    RingQueue_Init(&tq);

    int i = 0;
    struct tt tk;
    for(; i < 11; i++)
    {
        tk.id = i;
        RingQueue_EnQueue(tq, &tk);
    }

    cout << "RingQueue size " << RingQueue_Get_Size(tq) << endl;

    struct tt *ptk;
    for(i = 1; i <= 10; i++)
    {
        ptk = (struct tt *)RingQueue_Get_Index(tq, i);
        if(ptk)
            cout << "RingQueue item " << i << " id " << ptk->id << endl;
    }

    cout << "RingQueue remove head" << endl;
    RingQueue_Remove_Head(tq);
    RingQueue_Remove_Head(tq);

    cout << "RingQueue size " << RingQueue_Get_Size(tq) << endl;

    for(i = 1; i <= 10; i++)
    {
        ptk = (struct tt *)RingQueue_Get_Index(tq, i);
        if(ptk)
            cout << "RingQueue item " << i << " id " << ptk->id << endl;
    }

    tk.id = 100;
    RingQueue_EnQueue(tq, &tk);
    tk.id = 101;
    RingQueue_EnQueue(tq, &tk);

    for(i = 1; i <= 10; i++)
    {
        ptk = (struct tt *)RingQueue_Get_Head(tq);
        if(ptk)
            cout << "RingQueue item " << i << " id " << ptk->id << endl;

        RingQueue_Remove_Head(tq);
    }

    cout << "****************test RingQueue e******************" << endl;

}


int main()
{
    cout << "The Art of Programming!" << endl;

    test_find_once_number();
    test_find_commfactor();
    list_test();
    test_interview();

    upper_power_of_2(4);
    upper_power_of_2(513);
    upper_power_of_2(1782);

    //test_ringqueue();
    //dp_bag_test();

    cout << "str_len: " << str_len("NULL") << endl;

    CIniDt3106 inifile;

    inifile.test();

    //
    // Hello World server in C++
    // Binds REP socket to tcp://*:5555
    // Expects "Hello" from client, replies with "World"
    //
#if 0
    #include "zmq.h"
    #include <string>
    #include <windows.h>

    // Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;

        // Wait for next request from client
        socket.recv (&request);
        std::cout << "Received Hello" << std::endl;

        Sleep(1);

        // Send reply back to client
        zmq::message_t reply (5);
        memcpy ((void *) reply.data (), "World", 5);
        socket.send (reply);
    }
#endif

    atomicT1 at;

    at.spin_mutex_test();

    return 0;
}

