/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:53:20 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/10 21:53:26 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags 	*init_flags_struct(void)
{
//	WOW();
	t_flags		*flags;

	flags = malloc(sizeof(t_flags));
	flags->left_align = 0;
	flags->prepend_sign = 0;
	flags->prepend_space = 0;
	flags->prefix = 0;
	flags->prepend_zero = 0;
	return (flags);
}

int			read_flags(t_opt **o, t_content *content, int ptr)
{
//	WOW();
	(*o)->flags = init_flags_struct();
	while (content->format[ptr] && flag_check(content->format[ptr]))
	{
		if (content->format[ptr] == '#')
		{
			(*o)->flags->prefix = 1;
		}
		else if (content->format[ptr] == '0')
		{
			(*o)->flags->prepend_zero = 1;
		}
		else if (content->format[ptr] == ' ' && !(*o)->flags->prepend_sign)
		{
			(*o)->flags->prepend_space = 1;
		}
		else if (content->format[ptr] == '-')
		{
			(*o)->flags->left_align = 1;
		}
		else if (content->format[ptr] == '+')
		{
			(*o)->flags->prepend_sign = 1;
			(*o)->flags->prepend_space = 0;
		}
		ptr += 1;
	}
	return (ptr);
}

int			read_width(t_opt **o, t_content *content, int ptr)
{
//	WOW();
	char		*width;
	int			begin;

	begin = ptr;
	(*o)->width = 1;
	while (ft_is_digit(content->format[ptr]) && content->format[ptr])
	{
		ptr += 1;
	}
	if (ptr == begin && content->format[ptr] == '*')
	{
		(*o)->_width = va_arg(*content->arg_list, int);
	}
	else
	{
		width = ft_strdup_range(content->format, begin, ptr - 1);
		(*o)->_width = ft_atoi(width);
		free(width);
	}
//	printf("-----\no->width = %d\no->_width = %d\n", (*o)->width, (*o)->_width);
//	b_printf("returns %d\n", ptr);
	return (ptr);
}

int			read_precision(t_opt **o, t_content *content, int ptr)
{
//	WOW();
	char		*precision;
	int			begin;

	(*o)->precision = 1;
	begin = ++ptr;
	while (ft_is_digit(content->format[ptr]) && content->format[ptr])
	{
		ptr += 1;
	}
	if (ptr == begin && content->format[ptr] == '*')
	{
		(*o)->precision = va_arg(*content->arg_list, int);
	}
	else
	{
		precision = ft_strdup_range(content->format, begin, ptr - 1);
		(*o)->_precision = ft_atoi(precision);
		free(precision);
	}
//	printf("-----\no->precision = %d\no->_precision = %d\n", (*o)->precision, (*o)->_precision);
//	printf("returns %d\n", ptr);
	return (ptr);
}

int			read_length(t_opt **o, t_content *content, int ptr)
{
//	WOW();
	if (content->format[ptr] == 'l' && content->format[ptr + 1] == 'l'
		&& spec_check(content->format[ptr + 2]))
		ft_strcpy((*o)->length, "ll");
	else if (content->format[ptr] == 'l' && spec_check(content->format[ptr + 1]))
		ft_strcpy((*o)->length, "l");
	else if (content->format[ptr] == 'h' && content->format[ptr + 1] == 'h'
		&& spec_check(content->format[ptr + 2]))
		ft_strcpy((*o)->length, "hh");
	else if (content->format[ptr] == 'h' && spec_check(content->format[ptr + 1]))
		ft_strcpy((*o)->length, "h");
	else if (content->format[ptr] == 'z' && spec_check(content->format[ptr + 1]))
		ft_strcpy((*o)->length, "z");
	else if (content->format[ptr] == 'j' && spec_check(content->format[ptr + 1]))
		ft_strcpy((*o)->length, "z");
//	printf("returns %d\n", ptr + ft_strlen((*o)->length));
	return (ptr + ft_strlen((*o)->length));
}

int			spec_check(char c)
{
//	WOW();
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p'
	|| c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'o'
	|| c == 'O' || c == 'x' || c == 'X' || c == 'b' || c == '%'
	|| c == 'U')
		return (1);
//	b_printf("return 0\n");
	return (0);
}

int			flag_check(char c)
{
//	WOW();
	if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')
		return (1);
	return (0);
}

int			is_length_char(char c)
{
//	WOW();
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	return (0);
}
