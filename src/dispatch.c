/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:33:16 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/10 21:52:30 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			dispatch(t_opt *o, t_content *content)
{
//	WOW();
	if (o->spec == 'S' || o->spec == 's')
	{
		string(o, content);
	}
	else if (o->spec == 'C' || o->spec == 'c')
	{
		character(o, content);
	}
	else if (o->spec == 'd' || o->spec == 'i')
	{
//		decimal(o, content);
	}
	else if (o->spec == 'D')
	{
//		ft_strcpy(o->length, "l");
//		decimal(o, content);
	}
	else if (o->spec == 'u' || o->spec == 'U')
	{
//		unsigned_decimal(o, content);
	}
	else if (o->spec == 'x' || o->spec == 'X')
	{
//		hexadecimal(o, content);
	}
	else if (o->spec == 'o' || o->spec == 'O')
	{
//		octal(o, content);
	}
	else if (o->spec == 'b')
	{
//		binary(o, content);
	}
	else if (o->spec == 'p')
	{
//		pointer(o, content);
	}
}
