#ifndef ATOMICT1_H
#define ATOMICT1_H

#include <atomic>
#include <thread>
#include <mutex>
#include <iostream>

class spin_mutex
{
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
    spin_mutex() = default;
    spin_mutex(const spin_mutex&) = delete;
    spin_mutex& operator = (const spin_mutex&) = delete;

    void lock()
    {
        while(flag.test_and_set(std::memory_order_acquire));
    }
    void unlock()
    {
        flag.clear(std::memory_order_release);
    }
};

class atomicT1
{
public:
    atomicT1() = default;
    atomicT1(const atomicT1&) = delete;
    atomicT1& operator = (const atomicT1&) = delete;

public:
    void spin_mutex_test();

    static void t_thread_proc();
    static spin_mutex m_mutex;
    static int num;
};

#endif // ATOMICT1_H
