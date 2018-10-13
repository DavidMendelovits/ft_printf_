/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:11:33 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 16:56:52 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ASCII_MAX 0x7F
#define _6BIT_MAX 0x3F
#define _11BIT_MAX 0x7FF
#define _16BIT_MAX 0xFFFF
#define _8BIT_MASK 0x80
#define UTF16_MASK 0xC080
#define UTF24_MASK 0xE08080
#define UTF32_MASK 0xF08080

int			get_wchar_length(wint_t s)
{
//	WOW();
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

wint_t		extract_wchar(int len, wchar_t s)
{
//	WOW();
	unsigned char		*wide_char;
	wint_t				ret;

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
//		ft_putnbr_base(wide_char[0], 2);
		wide_char[1] = (((s >> 6) & _6BIT_MAX) | _8BIT_MASK);
//		ft_putnbr_base(wide_char[1], 2);
		wide_char[2] = ((s & _6BIT_MAX) | _8BIT_MASK);
//		ft_putnbr_base(wide_char[2], 2);
	}
	else
	{
		wide_char[0] = ((s >> 18) | (UTF32_MASK >> 24));
		wide_char[1] = (((s >> 12) & _6BIT_MAX) | _8BIT_MASK);
		wide_char[2] = (((s >> 6) & _6BIT_MAX) | _8BIT_MASK);
		wide_char[3] = ((s & _6BIT_MAX) | _8BIT_MASK);
	}
	ret = wchar_to_i(wide_char, len);
	free(wide_char);
	return (ret);
}

wint_t		wchar_to_i(unsigned char *wchar, int len)
{
//	WOW();
	wint_t			wide_char;
	int				i;

	i = 0;
	wide_char = 0;
	while (len--)
	{
		wide_char |= wchar[i];
		i += 1;
		if (len)
			wide_char <<= 8;
	}
	return (wide_char);
}

int		to_little_endian(int c)
{
	return (((c >> 24) & 0xff) | ((c << 8) & 0xff0000) |
		((c >> 8) & 0xff00) | ((c << 24) & 0xff000000));
}

int			ft_print_wchar(wchar_t s)
{
//	WOW();
	int						len;
	wint_t					wide_char;

	len = get_wchar_length((wint_t)s);
	wide_char = extract_wchar(len, s);
//	printf("\n");
//	ft_putnbr_base(print, 2);
//	printf("\n");
//	wide_char = to_little_endian(wide_char);
	write(1, &wide_char, len);
//	printf("huh\n");
	return (len);
}

void			print_wide_string(t_opt *o, t_content *content)
{
//	WOW();
	int				len;
	wchar_t			*wstr;
	int				i;

	i = 0;
	o->spec = 'S';
	len = 0;
//	printf("1\n");
	wstr = va_arg(*content->arg_list, wchar_t*);
//	printf("2\n");
	while (wstr[i])
	{
//		printf("loop\n");
		len += ft_print_wchar(wstr[i]);
		content->r_val += sizeof(wstr[i]);
//		printf("huh\n");
		i += 1;
//		printf("huh\n");
	}
	content->r_val += len;
}
