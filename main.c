/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:41:50 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 14:55:51 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			main()
{
	ft_printf("testing.....\n");
	ft_printf("test %10.5s\n", "Hello");
	return (0);
}
