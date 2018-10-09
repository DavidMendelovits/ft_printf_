#include "libft.h"

char                *ft_strdup_range(char *str, int begin, int end)
{
    char            *duplicate;
    int             dp;
    int             sp;

    duplicate = (char*)malloc(sizeof(*duplicate) * (end - begin));
    sp = begin;
    dp = 0;
    while (sp <= end)
    {
        duplicate[dp] = str[sp];
        dp += 1;
        sp += 1;
    }
    duplicate[dp] = '\0';
    return (duplicate);
}
