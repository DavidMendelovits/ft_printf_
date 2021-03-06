/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:50:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 21:37:49 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <assert.h>

void			character(t_opt *o, t_content *content)
{
//	WOW();
	wchar_t			wc;
	int				c;
	char			*str;

	if (o->spec == 'c')
	{
		c = va_arg(*content->arg_list, int);
	//	o->data->str = ft_strdup_range(&c, 0, 0);
	//	print_string(o, content);
		ft_putchar(c);
		content->r_val += 1;
	}
	else if (o->spec == 'C')
	{
		wc = va_arg(*content->arg_list, wchar_t);
		str = ft_strnew(sizeof(wchar_t) + 1);
		*((wchar_t *)str) = wc;
		write(1, str, ft_strlen(str));
	//	ft_print_wchar(wc);
		content->r_val += ft_strlen(str);
	}
	else if (o->spec == '%')
	{
		o->data->str = ft_strdup("%");
		print_string(o, content);
	}
}

char			*pad_string(t_opt *o, int _pad)
{
//	WOW();
	char			*pad;
	char			*new;

//	print_options(o);
//	if (o->flags && o->flags->prepend_space && o->width)
//		_pad -= 1;
	pad = (char *)ft_memalloc(sizeof(char) * (_pad + 1));
	if (o->flags && o->flags->append_zero && o->spec == 's' && !o->flags->left_align)
	{
//		printf("%d\n", o->flags->prepend_zero);
		ft_memset(pad, '0', _pad);
	}
	else
	{
//		printf("1\n");	
		ft_memset(pad, ' ', _pad);
	}
	if (o->flags && o->flags->left_align && pad[0] != '0')
	{
		new = ft_strjoin(o->data->str, pad);
	}
	else
	{
		new = ft_strjoin(pad, o->data->str);
	}
	free(o->data->str);
	free(pad);
	return (new);
}

void			string_options(t_opt *o)
{
//	WOW();
	char			*tmp;

	if (o->precision && o->_precision < ft_strlen(o->data->str) && o->_precision)
	{
		tmp = ft_strdup_range(o->data->str, 0, o->_precision - 1);
		free(o->data->str);
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	else if (o->precision && !o->_precision && !(o->spec == '%'))
	{
		free(o->data->str);
		o->data->str = NULL;
	}
	if (o->width && o->_width > ft_strlen(o->data->str))
	{
		tmp = pad_string(o, o->_width - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
}

void			print_string(t_opt *o, t_content *content)
{
//	WOW();
	int			len;

	if (o->width || o->precision)
	{
		string_options(o);
	}
	len = ft_strlen(o->data->str);
	content->r_val += len;
	write(1, o->data->str, len);	
}

void			string(t_opt *o, t_content *content)
{
//	WOW();
	char			*tmp;

	if (o->spec == 's')
	{
		tmp = va_arg(*content->arg_list, char *);
		if (!tmp)
		{
			write(1, "(null)", 6);
			content->r_val += 6;
			return ;
		}
		o->data->str = ft_strdup(tmp);
		print_string(o, content);
	}
	else if (o->spec == 'S' || (o->spec == 's' && !ft_strcmp(o->length, "l")))
	{
		print_wide_string(o, content);
	}
}
