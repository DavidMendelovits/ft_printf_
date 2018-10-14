/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:33:16 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 21:42:25 by dmendelo         ###   ########.fr       */
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
		decimal(o, content);
	}
	else if (o->spec == '%')
	{
		character(o, content);
	}
	else if (o->spec == 'D')
	{
		ft_strcpy(o->length, "l");
		decimal(o, content);
	}
	else if (o->spec == 'u' || o->spec == 'U')
	{
		if (o->spec == 'U')
			ft_strcpy(o->length, "l");
		print_unsigned(o, content, "0123456789", 10);
	}
	else if (o->spec == 'x' || o->spec == 'X')
	{
		if (o->spec == 'x')
		{
			print_unsigned(o, content, "0123456789abcdef", 16);
		}
		else if (o->spec == 'X')
		{
			print_unsigned(o, content, "0123456789ABCDEF", 16);
		}
	}
	else if (o->spec == 'o' || o->spec == 'O')
	{
		if (o->spec == 'O')
		{
			ft_strcpy(o->length, "l");
		}
		print_unsigned(o, content, "01234567", 8);
	}
	else if (o->spec == 'b')
	{
		print_unsigned(o, content, "01", 2); 
	}
	else if (o->spec == 'p')
	{
		print_pointer_address(o, content);
	}
}
