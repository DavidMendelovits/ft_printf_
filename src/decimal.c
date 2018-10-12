/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:55:44 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/11 22:39:38 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			apply_precision_number(t_opt *o)
{
	char				*tmp;
//	if ((o->width && o->_width > ft_strlen(tmp)) && o->flags && o->flags->prepend_zero && !o->precision)
//	{
//		tmp = pad_string(o, o->_width - ft_strlen(o->data->str));
//		o->data->str = ft_strdup(tmp);
//		free(tmp);
//	}
	if (o->precision && o->_precision > ft_strlen(tmp))	
	{
		o->flags->prepend_zero = 1;
		tmp = pad_string(o, o->_precision - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	if (o->flags && o->flags->prepend_sign)
	{
		tmp = ft_strjoin("+", o->data->str);
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
}

void			appropriate_flags(t_opt *o)
{
	if (o->flags && o->flags->append_zero && o->width && !o->precision)
	{
		o->precision = 1;
		o->_precision = o->_width;
		o->width = 0;
		o->_width = 0;
		if (o->flags && o->flags->prepend_sign)
			o->_precision -= 1;
	}
	if (o->flags && o->width && o->precision)
	{
		o->flags->append_zero = 0;
		o->flags->prepend_zero = 1;
	}
	if (o->flags && o->flags->append_zero )
	{
		o->flags->prepend_space = 0;
	}

	if (o->flags && o->flags->left_align && o->width)
	{
		o->flags->prepend_zero = 0;
	}
}

void			decimal(t_opt *o, t_content *content)
{
	char				*tmp;

	conversion(o, content);
	appropriate_flags(o);
	tmp = ft_itoa_base(o->data->num, "0123456789", 10);
	o->data->str = ft_strdup(tmp);
	free(tmp);
//	printf("o->precision = %d -> %d\n", o->precision, o->_precision);
//	printf("o->data->str (len) = %d\n", ft_strlen(o->data->str));
	if (o->flags && o->flags->prepend_space && o->data->str[0] != '-' && !o->precision)
	{
	//	printf("1\n");
		tmp = pad_string(o, 1);
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}

	else if (((o->precision && o->_precision > ft_strlen(o->data->str)) 
	|| (o->flags && o->flags->prepend_sign) || (o->width && !o->precision && o->flags->prepend_zero)))
	{
	//	printf("2\n");
		apply_precision_number(o);
	}
	if (o->width && o->_width > ft_strlen(o->data->str))
	{
		if (o->precision && o->_width > o->_precision)
		{
			o->flags->prepend_zero = 0;
	//		printf("\n1\n");	
		}
//		else if (o->width && !o->precision)
//			o->flags->prepend_zero = 1;
		tmp = pad_string(o, o->_width - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	write(1, o->data->str, ft_strlen(o->data->str));
}
