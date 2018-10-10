/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:33:16 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 19:39:37 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			dispatch(t_opt *o, t_content *content)
{
	if (o->specifier == 'S' || o->specifier == 's')
	{
		string(o, content);
	}
	else if (o->specifier == 'C' || o->specifier == 'c')
	{
		character(o, content);
	}
	else if (o->specifier == 'd' || o->specifier == 'i')
	{
		decimal(o, content);
	}
	else if (o->specifier == 'D')
	{
//		ft_strcpy(o->length, "l");
		decimal(o, content);
	}
	else if (o->specifier == 'u' || o->specifier == 'U')
	{
		unsigned_decimal(o, content);
	}
	else if (o->specifier == 'x' || o->specifier == 'X')
	{
		hexadecimal(o, content);
	}
	else if (o->specifier == 'o' || o->specifier == 'O')
	{
		octal(o, content);
	}
	else if (o->specifier == 'b')
	{
		binary(o, content);
	}
	else if (o->specifier == 'p')
	{
		pointer(o, content);
	}

}
