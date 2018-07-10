#include "atomict1.h"

int atomicT1::num = 0;
spin_mutex atomicT1::m_mutex;

atomicT1::atomicT1()
{

}

void atomicT1::t_thread_proc()
{
    for(int i = 0; i < 100000; ++i)
    {
        std::lock_guard<spin_mutex> lock(atomicT1::m_mutex);
        ++atomicT1::num;
    }
}

void atomicT1::spin_mutex_test()
{
    std::thread td1(atomicT1::t_thread_proc), td2(atomicT1::t_thread_proc);

    td1.join();
    td2.join();

    std::cout << "c11 spin_mutex num is " << num << std::endl;
}
