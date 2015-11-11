#include <iostream>
#include <assert.h>

#include "base_function.h"

unsigned int str_len(const char *str)
{
    if(NULL == str) return 0;

    const char *ptr = str;

    while(*ptr++);

    return ptr - str - 1;
}

char *str_str(const char *src, const char *find)
{
    return src;
}

char *str_cat(char *dst, const char *src)
{
    return dst;
}

int str_cmp(const char *src, const char *dst)
{
    return 0;
}

char *str_ncat(char *dst, const char *src, unsigned int count)
{
    return dst;
}

char *str_cpy(char *dst, const char *src)
{
    return dst;
}

char *str_ncpy(char *dst, const char *src, unsigned int count)
{
    return dst;
}
