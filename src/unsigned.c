/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:38:46 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 20:48:48 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prepend_prefix(t_opt *o)
{
	char			*prefix;
	char			*tmp;

	if (o->spec == 'x')
	{
		prefix = ft_strdup("0x");
	}
	else if (o->spec == 'X')
	{
		prefix = ft_strdup("0X");
	}
	else if (o->spec == 'o' || o->spec == 'O')
	{
		prefix = ft_strdup("0");
	}
	tmp = ft_strjoin(prefix, o->data->str);
	o->data->str = ft_strdup(tmp);
	free(tmp);
}	

void			pad_unsigned(t_opt *o)
{
	char			*tmp;

	if (o->precision && o->_precision > ft_strlen(o->data->str))
	{
		tmp = pad_num_zero(o, o->_precision - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	else if (o->precision && !o->_precision && !ft_strcmp(o->data->str, "0"))
	{
		free(o->data->str);
		o->data->str = NULL;
	}
	if (o->flags)
	{
		if (o->flags->prefix && (o->spec == 'x' || o->spec == 'X' || o->spec == 'o' || o->spec == 'O'))
		{
			prepend_prefix(o);
		}
	}
}

void			appropriate_flags_unsigned(t_opt *o)
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
		if (o->flags->prefix)
		{
			if (!o->data->u_num && !(o->precision && !o->_precision))
			{
				o->flags->prefix = 0;
			}
			else if (!o->data->u_num && o->precision && !o->_precision && (o->spec == 'x' || o->spec == 'X'))
			{
				o->flags->prefix = 0;
			}
	//		if (o->width && o->_width > ft_strlen(o->data->str))
	//		{
	//			if (o->spec == 'o' || o->spec == 'O')
	//				o->_width -= 1;
	//			else if (o->spec == 'x' || o->spec == 'X')
	//				o->_width -= 2;
	//		}
//			else if (o->precision && o->_precision > ft_strlen(o->data->str))
//			{
//				if (o->spec == 'o' || o->spec == 'O')
//					o->_width -= 1;
//				else if (o->spec == 'x' || o->spec == 'X')
//					o->_width -= 2;
//			}
		}
	}
}

void			print_unsigned(t_opt *o, t_content *content, char *base, int radix)
{
	char			*tmp;

	unsigned_conversion(o, content);
//	printf("o->data->unum = %lu\n", o->data->u_num);
	appropriate_flags_unsigned(o);
	tmp = ft_utoa_base(o->data->u_num, base, radix);
//	printf("o->data->unum = %s\n", tmp);
	o->data->str = ft_strdup(tmp);
	free(tmp);
//	print_options(o);
	pad_unsigned(o);
	if (o->width && o->_width > ft_strlen(o->data->str))
	{
		tmp = pad_string(o, o->_width - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	if (o->data->str)
		write(1, o->data->str, ft_strlen(o->data->str));
	content->r_val += ft_strlen(o->data->str);
}
