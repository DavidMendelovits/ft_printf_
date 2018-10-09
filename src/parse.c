/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:15:31 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 11:22:23 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_opt(t_opt **o)
{
	(*o) = (t_opt *)malloc(sizeof(t_opt));
	(*o)->flags = NULL;
	(*o)->width = 0;
	(*o)->_width = 0;
	(*o)->precision = 0;
	(*o)->precision = 0;
	ft_bzero((*o)->length);
	(*o)->spec = '\0';
}

void			free_opt(t_opt **o)
{
	if ((*o)->flags)
		free((*o)->flags);
	free(*o);
}

int				parse(const char *format, va_list arg_list)
{
	t_opt				*o;
	t_content			content;

	init_opt(&o);
	free_opt(&o);
}
