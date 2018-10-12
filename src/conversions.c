/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:50:35 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/11 18:12:16 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_conversion(t_opt *o, t_content *content)
{
//	WOW();
	o->data->u_num = 0;
	if (o->length[0] == '\0')
		o->data->u_num = va_arg(*content->arg_list, unsigned int);
	else if (o->length[0] == 'h' && o->length[1] == 'h')
	{	
		o->data->u_num = 
			(unsigned char)va_arg(*content->arg_list, unsigned int);
	}
	else if (o->length[0] == 'h')
	{
		o->data->u_num =
			(unsigned short)va_arg(*content->arg_list, unsigned int);
	}
	else if (o->length[0] == 'l' && o->length[1] == 'l')
		o->data->u_num = va_arg(*content->arg_list, unsigned long long);
	else if (o->length[0] == 'l')
		o->data->u_num = va_arg(*content->arg_list, unsigned long);
	else if (o->length[0] == 'j')
		o->data->u_num = va_arg(*content->arg_list, uintmax_t);
	else if (o->length[0] == 'z')
		o->data->u_num = va_arg(*content->arg_list, size_t);
}

void	conversion(t_opt *o, t_content *content)
{
//	WOW();
	o->data->num = 0;
	if (o->length[0] == '\0')
	{
		o->data->num = va_arg(*content->arg_list, int);
//		printf("none\n");
	}
	else if (o->length[0] == 'h' && o->length[1] == 'h')
	{
//		printf("hh\n");
		o->data->num = (signed char)va_arg(*content->arg_list, int);
	}
	else if (o->length[0] == 'h')
		o->data->num = (short)va_arg(*content->arg_list, int);
	else if (o->length[0] == 'l' && o->length[1] == 'l')
		o->data->num = va_arg(*content->arg_list, long long);
	else if (o->length[0] == 'l')
		o->data->num = va_arg(*content->arg_list, long);
	else if (o->length[0] == 'j')
		o->data->num = va_arg(*content->arg_list, intmax_t);
	else if (o->length[0] == 'z')
	{
		o->data->num = va_arg(*content->arg_list, size_t);
	//	printf("\nz\n");
	}
}
