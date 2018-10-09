/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:15:31 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 15:04:41 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_opt(t_opt **o)
{
	WOW();
	(*o) = (t_opt *)malloc(sizeof(t_opt));
	(*o)->flags = NULL;
	(*o)->width = 0;
	(*o)->_width = 0;
	(*o)->precision = 0;
	(*o)->precision = 0;
	ft_bzero((*o)->length, 3);
	(*o)->spec = '\0';
}

void			print_options(t_opt *o)
{
	WOW();
	b_printf("-----------opt struct-----------\n");
	if (o->flags)
	{
		b_printf("->present flags:\n");
		if (o->flags->left_align)
			b_printf("left_align '-'\n");
		if (o->flags->prepend_space)
			b_printf("prepend_space ' '\n");
		if (o->flags->prepend_sign)
			b_printf("prepend_sign '+'\n");
		if (o->flags->prefix)
			b_printf("prefix '#'\n");
		if (o->flags->prepend_zero)
			b_printf("prepend_zero '0'\n");
	}
	b_printf("width = %d\n", o->width);
	b_printf("_width = %d\n", o->_width);
	b_printf("precision = %d\n", o->precision);
	b_printf("_precision = %d\n", o->_precision);
	b_printf("length = %s\n", o->length);
	b_printf("specifier = %c\n", o->spec);
}


void			free_opt(t_opt **o)
{
	WOW();
	if ((*o)->flags)
		free((*o)->flags);
	free(*o);
}

void			init_content(t_content *content, char *format, va_list *args)
{
	WOW();
	content->format = format;
	content->arg_list = args;
	content->r_val = 0;
}

void			parse_specifier(t_content *content, t_opt *o, int *ptr)
{
	WOW();
	int					tmp;

	tmp = *ptr;
	while (content->format[tmp] && !(spec_check(content->format[tmp])))
	{
		b_printf("\n----content->format[%d] = %c\n", tmp, content->format[tmp]);
		if (flag_check(content->format[tmp]))
			tmp += read_flags(&o, content, tmp);
		else if (ft_is_digit(content->format[tmp]) || content->format[tmp] == '*')
			tmp += read_width(&o, content, tmp);
		else if (content->format[tmp] == '.')
			tmp += read_precision(&o, content, tmp);
		else if (is_length_char(content->format[tmp]))
			tmp += read_length(&o, content, tmp);
	}
	b_printf("\n----content->format[%d] = %c\n", tmp, content->format[tmp]);
	if (spec_check(content->format[tmp]))
	{
		o->spec = content->format[tmp];
		*ptr = tmp;
	}
	print_options(o);
//	dispatch(o, content);
}

int				parse_format(const char *format, va_list arg_list)
{
	WOW();
	t_opt				*o;
	t_content			content;
	int					ptr;
	char				*print;
	int					begin;

	init_opt(&o);
	free_opt(&o);
	init_content(&content, (char *)format, (va_list *)arg_list);
	ptr = 0;
	while (format[ptr])
	{
		b_printf("----------format[%d] = %c\n", ptr, format[ptr]);
		if (format[ptr] == '%')
		{
			parse_specifier(&content, o, &ptr);
		}
		else
		{
			begin = ptr;
			while (format[ptr] && format[ptr] != '%')
			{
				ptr += 1;
			}
			print = ft_strdup_range((char *)format, begin, ptr - 1);
			write(1, print, ptr - begin);
			content.r_val += (ptr - begin);
			free(print);
		}
	}
	return (content.r_val);
}
