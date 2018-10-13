/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:41:50 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 10:17:00 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>

int			main()
{
//	wchar_t		c;

//	setlocale(LC_ALL, "en_US.UTF-8");
//	c = L'诶';
//	ft_printf("%C\n", c);
//	ft_printf("%S\n", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
//	ft_printf("%S\n", L"Á±≥");
//		printf("%ls\n", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");


	int		n = 10;
//	ft_printf("%c\n", 2134234);

	printf("|%-05d|\n", 42);
	printf("-----------signed----------\n");
	ft_printf("|%d|\n", 0);
	printf("|%d|\n", 0);
	ft_printf("|% d|\n", 42);
	printf("|% d|\n", 42);
  	ft_printf("|%+d|\n", 42);
  	printf("|%+d|\n", 42);
  	ft_printf("|%+d|\n", 0);
  	printf("|%+d|\n", 0);
  	ft_printf("|% +d|\n", 42);
  	printf("|% +d|\n", 42);
  	ft_printf("|%+ d|\n", 42);
  	printf("|%+ d|\n", 42);
  	ft_printf("|%  +d|\n", 42);
  	printf("|%  +d|\n", 42);
  	ft_printf("|%+  d|\n", 42);
  	printf("|%+  d|\n", 42);
	ft_printf("|%++ d|\n", 42);
	printf("|%++ d|\n", 42);
  	ft_printf("|%0+5d|\n", 42);
  	printf("|%0+5d|\n", 42); 
	ft_printf("|%-5d|\n", -42);
	printf("|%-5d|\n", -42); 
	ft_printf("|%-05d|\n", -42);
	printf("|%-05d|\n", -42);
	ft_printf("|% 10.5d|\n", 4242);
	printf("|% 10.5d|\n", 4242);
	ft_printf("|%+10.5d|\n", 4242);
	printf("|%+10.5d|\n", 4242);
	ft_printf("|%-+10.5d|\n", 4242);
	printf("|%-+10.5d|\n", 4242);
	ft_printf("|basic decimal| -> %d\n", 42);
	printf("|basic decimal| -> %d\n", 42);
	ft_printf("|precision| -> %.5d\n", 42);
	printf("|precision| -> %.5d\n", 42);
	ft_printf("|width| -> %5d\n", 42);
	printf("|width| -> %5d\n", 42);
	ft_printf("|width/precision| -> %10.5d\n", 42);
	printf("|width/precision| -> %10.5d\n", 42);
	ft_printf("|zero precision| -> %.d\n", 42);
	printf("|zero precision| -> %.d\n", 42);
	ft_printf("|zero precision| -> %.0d\n", 42);
	printf("|zero precision| -> %.0d\n", 42);
	ft_printf("|zero precision| -> %.0d\n", 0);
	printf("|zero precision| -> %.0d\n", 0);
	ft_printf("|negative number| -> %d\n", -42);
	printf("|negative number| -> %d\n", -42);
	ft_printf("|negative number| -> %10d\n", -42);
	printf("|negative number| -> %10d\n", -42);
	ft_printf("|negative number| -> %10.5d\n", -42);
	printf("|negative number| -> %10.5d\n", -42);
	ft_printf("|zero_pad| -> %010d\n", -42);
	printf("|zero_pad| -> %010d\n", -42);
	ft_printf("|zero_pad| -> %010.5d\n", -42);
	printf("|zero_pad| -> %010.5d\n", -42);
	ft_printf("|space| -> % d\n", -42);
	printf("|space| -> % d\n", -42);
	ft_printf("|sign| -> %+d\n", 42);
	printf("|sign| -> %+d\n", 42);
	ft_printf("|sign/space| -> % 05d\n", -42);
	printf("|sign/space| -> % 05d\n", -42);
	ft_printf("%zD, %zD\n", 0, USHRT_MAX);
	printf("%zD, %zD\n", 0, USHRT_MAX);
	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n", 0);
//	ft_printf("{%3*d}\n", 0, 0);
//	printf("{%3*d}\n", 0, 0);
	ft_printf("%.d, %.0d\n", 0, 0);
	printf("%.d, %.0d\n", 0, 0);
//	ft_printf("{%05.*d}\n", -15, 42);
//	printf("{%05.*d}\n", -15, 42);
	ft_printf("%d %s \n", NULL, NULL, NULL);
	printf("%d %s \n", NULL, NULL, NULL);
	ft_printf("'+' flag |%++d|\n", n);
	printf("'+' flag |%++d|\n", n);
	ft_printf("'+' flag |%++hd|\n", n);
	printf("'+' flag |%++hd|\n", n);
	ft_printf("padding with '-' flag |%--10d|\n", n);
	printf("padding with '-' flag |%--10d|\n", n);
	ft_printf("padding without '-' flag |%10d|\n", n);
	printf("padding without '-' flag |%10d|\n", n);
//	ft_printf("Double persent: |%10%|\n", n);
//	printf("Double persent: |%10%|\n", n);

	printf("----------s,c flags -----------\n");
	ft_printf("|%c|\n", 'A');
	printf("|%c|\n", 'A');
	ft_printf("|%10c|\n", 'A');
	printf("|%10c|\n", 'A');
	ft_printf("|%-10c|\n", 'A');
	printf("|%-10c|\n", 'A');
	ft_printf("|%-10.2c|\n", 'A');
	printf("|%-10.2c|\n", 'A');
	ft_printf("|%s|\n", "Hello, World");
	printf("|%s|\n", "Hello, World");
	ft_printf("|%20s|\n", "Hello, World");
	printf("|%20s|\n", "Hello, World");
	ft_printf("|%-20s|\n", "Hello, World");
	printf("|%-20s|\n", "Hello, World");
	ft_printf("|%20.5s|\n", "Hello, World");
	printf("|%20.5s|\n", "Hello, World");
	ft_printf("|%-20.6s|\n", "Hello, World");
	printf("|%-20.6s|\n", "Hello, World");
	ft_printf("|%-20.s|\n", "Hello, World");
	printf("|%-20.s|\n", "Hello, World");
	ft_printf("|%-20.s|\n", "Hello, World");
	printf("|%-20.s|\n", "Hello, World");
	ft_printf("|%0010s|\n", "string");
	printf("|%0010s|\n", "string");
	ft_printf("|%-0010s|\n", "string");
	printf("|%-0010s|\n", "string");
	ft_printf("|%-20.-6s|\n", "Hello, World");
	printf("|%-20.-6s|\n", "Hello, World");
//	ft_printf("testing.....\n");
//	ft_printf("test %010.5lld\n", "Hello");
	return (0);
}
