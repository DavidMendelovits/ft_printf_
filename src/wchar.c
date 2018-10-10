/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:45:04 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/10 16:10:38 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#define ASCII_MAX 0x7F
#define _6_BIT_MAX 0x3F
#define _16BIT_MASK 0xC080
#define _24BIT_MASK 0xE08080
#define _32BIT_MASK 0xF0808080
//void		print_wchar(wint_t);

//void		print_wstr(wchar_t);

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

int		get_mask(wint_t c, size_t *len)
{
	if (c <= 0x7FF)
	{
		*len = 2;
		printf("size = 2 bytes\n");
		return (_16BIT_MASK);
	}
	else if (c <= 0xFFFF)
	{
		*len = 3;
		printf("size = 3 bytes\n");
		return (_24BIT_MASK);
	}
	else
	{
		*len = 4;
		printf("size = 4 bytes\n");
		return (_32BIT_MASK);
	}
}

unsigned int		to_little_endian(int c)
{
	unsigned int			ret;

	ft_putnbr_base(c, 2);
	printf("\n");
	ret = (c >> 24) & 0xff;
	ft_putnbr_base(ret, 2);
	printf("\n");
	ret |= ((c << 8) & 0xff0000);
	ft_putnbr_base(ret, 2);
	printf("\n");
	ret |= ((c >> 8) & 0xff00);
	ft_putnbr_base(ret, 2);
	printf("\n");
	ret |= ((c << 24) & 0xff000000);
	ft_putnbr_base(ret, 2);
	printf("\n");
	return (ret);
//	return (((c >> 24) & 0xff) | ((c << 8) & 0xff0000) |
//		((c >> 8) & 0xff00) | ((c << 24) & 0xff000000));
}

size_t	ft_print_wchar(wint_t c)
{
	int		output;
	size_t	len;

	output = _32BIT_MASK;
	if (c <= 0x7F)
	{
		output = c & 127;
		len = 1;
	}
	else
	{
		output = get_mask(c, &len);
		output |= (((c >> 6) & 0x3F) << 8) | (c & 0x3F);
		if (c > 0x7FF)
			output |= (((c >> 12) & 0xF) << 16);
		if (c > 0xFFFF)
			output |= (((c >> 18) & 0x7) << 24);

	}
		ft_putnbr_base(output, 2);
		write(1, "\n", 1);
		output = to_little_endian(output);
		write(1, "\n", 1);
		ft_putnbr_base(output, 2);
		write(1, "\n", 1);
		ft_putnbr_base(output, 10);
		write(1, "\n", 1);
	write(1, &output, sizeof(wchar_t));
	return (len);
}

int			main(void)
{

	wchar_t		c;

	setlocale(LC_ALL, "en_US.UTF-8");
	c = L'诶';
//	printf("\%d\n", c);
//	ft_putnbr_base((int)(unsigned int)c, 2);
//	printf("\n");
	ft_print_wchar(c);
	printf("\n");
	return (0);
}
