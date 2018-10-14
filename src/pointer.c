/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:21:31 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 19:44:19 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_pointer_address(t_opt *o, t_content *content)
{
	char			*tmp;

	o->data->ptr = va_arg(*content->arg_list, void *);
	tmp = ft_utoa_base((uintmax_t)o->data->ptr, "0123456789abcdef", 16);
	o->data->str = ft_strdup(tmp);
	free(tmp);
	if (o->precision && o->_precision > ft_strlen(o->data->str))
	{
		tmp = pad_num_zero(o, o->_precision - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	tmp = ft_strjoin("0x", o->data->str);
	o->data->str = ft_strdup(tmp);
	free(tmp);
	if (o->width && o->_width > ft_strlen(o->data->str))
	{
		tmp = pad_string(o, o->_width - ft_strlen(o->data->str));
		o->data->str = ft_strdup(tmp);
		free(tmp);
	}
	write(1, o->data->str, ft_strlen(o->data->str));
	content->r_val += ft_strlen(o->data->str);
}
