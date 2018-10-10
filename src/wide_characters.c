/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:20:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/10 16:03:36 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

#define ASCII_MAX 0x7F
#define _6BIT_MAX 0x3F
#define _11BIT_MAX 0x7FF
#define _16BIT_MAX 0xFFFF
#define _8BIT_MASK 0x80
#define UTF16_MASK 0xC080
#define UTF24_MASK 0xE08080
#define UTF32_MASK 0xF08080

void        ft_bzero(void *s, size_t n)
{
        memset(s, '\0', n);
}

char		*ft_strnew(size_t size)
{
	char		*str;

	if (!(str = (char *)malloc(size + 1)))
	{
		return (NULL);
	}
	ft_bzero(str, size + 1);
	return (str);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int n, int base)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'A');
	}
}

int		to_little_endian(int c)
{
	return (((c >> 24) & 0xff) | ((c << 8) & 0xff0000) |
		((c >> 8) & 0xff00) | ((c << 24) & 0xff000000));
}

int			get_wchar_length(wint_t s)
{
	if (s <= ASCII_MAX)
	{
		return (1);
	}
	else if (s <= _11BIT_MAX)
	{
		return (2);
	}
	else if (s <= _16BIT_MAX)
	{
		return (3);
	}
	else
	{
		return (4);
	}
}

void		ft_print_wchar(wchar_t s)
{
	unsigned char			*wide_char;
	int						len;
	wint_t					print;

	print = 0;
	len = get_wchar_length((wint_t)s);
	wide_char = (unsigned char *)ft_strnew(len);
	if (len == 1)
	{
		wide_char[0] = (char)s;
	}
	else if (len == 2)
	{
		wide_char[0] = ((s >> 6) | (UTF16_MASK >> 8));
		wide_char[1] = ((s & _6BIT_MAX) | _8BIT_MASK);
	}
	else if (len == 3)
	{
		wide_char[0] = ((s >> 12) | (UTF24_MASK >> 16));
		ft_putnbr_base(wide_char[0], 2);
		wide_char[1] = (((s >> 6) & _6BIT_MAX) | _8BIT_MASK);
		ft_putnbr_base(wide_char[1], 2);
		wide_char[2] = ((s & _6BIT_MAX) | _8BIT_MASK);
		ft_putnbr_base(wide_char[2], 2);
	}
	else
	{
		wide_char[0] = ((s >> 18) | (UTF32_MASK >> 24));
		wide_char[1] = (((s >> 12) & _6BIT_MAX) | _8BIT_MASK);
		wide_char[2] = (((s >> 6) & _6BIT_MAX) | _8BIT_MASK);
		wide_char[3] = ((s & _6BIT_MAX) | _8BIT_MASK);
	}
	int	i = 0;
	int tmp = len;
	while (len--)
	{
		print |= wide_char[i];
		i += 1;
		if (len)
			print <<= 8;
	}
	printf("\n");
	ft_putnbr_base(print, 2);
	printf("\n");
	write(1, &print, tmp);
}

int			main()
{
	wchar_t		c;

	setlocale(LC_ALL, "en_US.UTF-8");
	c = 0x1f984;
	//	c = L'诶';
	ft_print_wchar(c);
	printf("\n\n");
	ft_putnbr_base(0xf0, 2);
	printf("\n");
	ft_putnbr_base(UTF16_MASK >> 8, 2);
	printf("\n");
	ft_putnbr_base(0xc0, 2);
	printf("\n");
	ft_putnbr_base(0x3f, 2);
	printf("\n");
	ft_putnbr_base(0x80, 2);
	printf("\n");
	ft_putnbr_base(UTF24_MASK, 2);
	printf("\n");
	ft_putnbr_base(0xe0, 2);

	return (0);

}
