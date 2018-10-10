/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:41:50 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/10 16:55:35 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <locale.h>

int			main()
{
	wchar_t		c;

	setlocale(LC_ALL, "en_US.UTF-8");
	c = L'诶';
	ft_printf("%C\n", c);
	ft_printf("%S\n", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
	ft_printf("%S\n", L"Á±≥");
//	ft_printf("testing.....\n");
//	ft_printf("test %010.5lld\n", "Hello");
	return (0);
}
