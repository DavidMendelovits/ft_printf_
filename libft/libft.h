#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

void            ft_putchar(char c);
void            ft_putstr(char *str);
void            ft_putnbr_base(unsigned long long, int base);
void            *ft_memset(void *s, int c, size_t n);
void            *ft_memalloc(size_t size);
void            ft_bzero(void *s, size_t n);
int             ft_atoi(const char *str);
int             ft_strlen(char *str);
int             b_printf(const char *format, ...);
char            *ft_strdup(char *str);
char            *ft_strdup_range(char *str, int begin, int end);
char			*ft_strrev(char *str);
void			ft_swap(int *a, int *b);
int				ft_atoi_base(char *_int, char *base);
int				ft_strcmp(char *s1, char *s2);
#endif
