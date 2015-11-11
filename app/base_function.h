#ifndef BASE_FUNCTION_H
#define BASE_FUNCTION_H

unsigned int str_len(const char *str);

char *str_str(const char *src, const char *find);

char *str_cat(char *dst, const char *src);

int str_cmp(const char *src, const char *dst);

char *str_ncat(char *dst, const char *src, unsigned int count);

char *str_cpy(char *dst, const char *src);

char *str_ncpy(char *dst, const char *src, unsigned int count);

#endif // BASE_FUNCTION_H
