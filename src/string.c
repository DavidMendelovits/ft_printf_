/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:50:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/10 16:53:29 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			character(t_opt *o, t_content *content)
{
	WOW();
	wchar_t			wc;

	if (o->spec == 'c')
	{
//		print_string(o, content);
	}
	else if (o->spec == 'C')
	{
		wc = va_arg(*content->arg_list, wchar_t);
		ft_print_wchar(wc);
	}
}

void			string(t_opt *o, t_content *content)
{
	WOW();
	if (o->spec == 's')
	{
//		print_string(o, content);
	}
	else if (o->spec == 'S')
	{
		print_wide_string(o, content);
	}
}
