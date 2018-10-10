/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:50:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 19:19:16 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			string(t_opt *o, t_content *o)
{
	if (o->specifier == 's')
	{
		print_string(list, content);
	}
	else if (o->specifier == 'S')
	{
		print_wide_string(list, content);
	}
}
