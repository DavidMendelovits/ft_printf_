/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:07:44 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/10 21:53:36 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
//	WOW();
	va_list			arg_list;
	int				r_val;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);
	r_val = parse_format(format, arg_list);
	va_end(arg_list);
	return (r_val);
}
