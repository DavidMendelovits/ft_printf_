/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:07:44 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 11:15:28 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_arg			arg_list;
	int				r_val;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);
	r_val = parse(format, arg_list);
	va_end(arg_list);
	return (r_val);
}
