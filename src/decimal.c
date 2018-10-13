/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:55:44 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/12 18:21:21 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*pad_num_zero(t_opt *o, int _pad)
{
	char				*pad;
	char				*new;

	pad = (char *)ft_memalloc(sizeof(char) * (_pad + 1));
	ft_memset(pad, '0', _pad);
	new = ft_strjoin(pad, o->data->str);
	free(o->data->str);
	free(pad);
	return (new);
}
void			pad_decimal(t_opt *o)
{
//	WOW();
	char				*tmp;

	if (o->_precision > ft_strlen(o->data->str) && o->data->str[0] == '-')
	{
		tmp = ft_strdup_range(o->data->str, 1, ft_strlen(o->data->str - 1));
		o->data->str = ft_strdup(tmp);
		free(tmp);
		tmp = pad_num_zero(o, o->_precision - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin("-", o->data->str);
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	else if (o->flags)
	{
		if (o->flags->prepend_space)
		{
			tmp = pad_string(o, 1);
			o->data->str = ft_strdup(tmp);
			free(tmp);
		}
		else if (o->_precision > ft_strlen(o->data->str))
		{
			tmp = pad_num_zero(o, o->_precision - ft_strlen(o->data->str));
//			printf("\n%s\n", tmp);
			o->data->str = ft_strdup(tmp);
			free(tmp);
		}
		if (o->flags->prepend_sign)
		{
			tmp = ft_strjoin("+", o->data->str);
			o->data->str = ft_strdup(tmp);
			free(tmp);
		}
	}
	
	else if (o->_precision > ft_strlen(o->data->str))
	{
		tmp = pad_num_zero(o, o->_precision - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	else if (o->precision && !o->_precision && !ft_strcmp(o->data->str, "0"))
	{
		free(o->data->str);
		o->data->str = ft_strnew(1);
	}
}

void			appropriate_flags(t_opt *o)
{
	if (o->flags)
	{
		if (o->flags->append_zero && o->width && !o->precision && !o->flags->left_align)
		{
			o->precision = 1;
			o->_precision = o->_width;
			o->width = 0;
			o->_width = 0;
			o->flags->append_zero = 0;
			o->flags->prepend_zero = 1;
		}
		if (o->flags->prepend_space && o->data->num < 0)
		{
			o->flags->prepend_space = 0;
		}
		if (o->flags->prepend_zero && o->flags->prepend_sign && !o->width)
		{
			o->_precision -= 1;
		}
		if (o->flags->prepend_zero || o->precision)
		{
			o->flags->prepend_space = 0;
		}
		if (!o->width && o->precision && o->data->num < 0)
		{
			o->_precision -= 1;
		}
	}
}

void			decimal(t_opt *o, t_content *content)
{
//	WOW();
	char				*tmp;

	conversion(o, content);
	appropriate_flags(o);
	tmp = ft_itoa_base(o->data->num, "0123456789", 10);
	o->data->str = ft_strdup(tmp);
	free(tmp);
	pad_decimal(o);
	if (o->width && o->_width > ft_strlen(o->data->str))
	{
		tmp = pad_string(o, o->_width - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	write(1, o->data->str, ft_strlen(o->data->str));
}
