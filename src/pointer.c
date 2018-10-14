/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:21:31 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 19:26:05 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_pointer_address(t_opt *o, t_content *content)
{
	char			*tmp;

	unsigned_conversion(o, content);
	tmp = ft_utoa_base(o->data->u_num, "0123456789abcdef", 16);
	o->data->str = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin("0x", o->data->str);
	o->data->str = ft_strdup(tmp);
	free(tmp);
	write(1, o->data->str, ft_strlen(o->data->str));
	content->r_val += ft_strlen(o->data->str);
}
