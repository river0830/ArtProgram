#ifndef INTERVIEW_H
#define INTERVIEW_H

#include <string>

class cTestInterView
{
public:
    void equation_transfer(int num);
    void delete_repeat_num(void);
    void delete_appoint_character(char *str, char c);

    int bruteforce_str(std::string &dst, std::string &src);
    int bruteforce1_str(std::string &dst, std::string &src);
    int kmp_str(std::string &dst, std::string &src);

private:
    void show_tips(void);
    void get_3symbol(int num, std::string &str);
};

#endif // INTERVIEW_H
