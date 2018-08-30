#ifndef INTERVIEW_H
#define INTERVIEW_H

#include <string>
#include <vector>

class cTestInterView
{
public:
    void equation_transfer(int num);
    void delete_repeat_num(void);
    void delete_appoint_character(char *str, char c);

    int bruteforce_str(std::string &dst, std::string &src);
    int bruteforce1_str(const char *dst, const char *src);
    int kmp_str(std::string &dst, std::string &src);

    void fast_mod(unsigned int x, unsigned int n, unsigned int m);
    void twoSums(std::vector<int> &dst, int target);
    void threeSumsZero(std::vector<int> &dst, int  flag = 1);
    void threeSumClosest(std::vector<int> &dst, int target);
    void iterEraseDeleteTest();

    void continueSum(unsigned int num);
    void continueSum1(int num);
    void continueSum2(int num);

private:
    void kmp_get_next(const std::string &str, std::vector<int> &next);

    void show_tips(void);
    void get_3symbol(int num, std::string &str);
};

#endif // INTERVIEW_H
