/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:41:50 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/13 19:39:07 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>

int			main()
{
	wchar_t		c;

	setlocale(LC_ALL, "en_US.UTF-8");
	c = L'诶';
	ft_printf("%C\n", c);
	ft_printf("%S\n", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
	ft_printf("%S\n", L"Á±≥");
		printf("%ls\n", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");


	int		n = 10;
//	ft_printf("%c\n", 2134234);

/*	printf("|%-05d|\n", 42);
	printf("-----------signed----------\n");
	ft_printf("|% 4.5i|\n", 42);
	printf("|% 4.5i|\n", 42);
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
	ft_printf("|sign/space| -> |% 05d|\n", -42);
	printf("|sign/space| -> |% 05d|\n", -42);
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
	ft_printf("Double persent: |%10%|\n", n);
	printf("Double persent: |%10%|\n", n);

	printf("----------s,c flags -----------\n");
	ft_printf("%d\n", ft_printf("|%c|\n", 'A'));
	printf("%d\n", printf("|%c|\n", 'A'));
	ft_printf("%d\n", ft_printf("|%c|\n", 12345));
	printf("%d\n", printf("|%c|\n", 12345));
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
//	ft_printf("test %010.5lld\n", "Hello"); */
	printf("--------------unsigned------------\n");
	printf("--------------octal---------------\n");
	ft_printf("|basic octal| -> %o\n", 42);
	printf("|basic octal| -> %o\n", 42);
	ft_printf("|precision| -> %.5o\n", 42);
	printf("|precision| -> %.5o\n", 42);
	ft_printf("|width| -> %5o\n", 42);
	printf("|width| -> %5o\n", 42);
	ft_printf("|width/precision| -> %10.5o\n", 42);
	printf("|width/precision| -> %10.5o\n", 42);
	ft_printf("|zero precision| -> %.o\n", 42);
	printf("|zero precision| -> %.o\n", 42);
	ft_printf("|zero precision| -> %.0o\n", 42);
	printf("|zero precision| -> %.0o\n", 42);
	ft_printf("|zero precision| -> %.0o\n", 0);
	printf("|zero precision| -> %.0o\n", 0);
	ft_printf("-> %o\n", 42);
	printf("-> %o\n", 42);
	ft_printf("-> %10o\n", 42);
	printf("-> %10o\n", 42);
	ft_printf("-> %10.5o\n", 42);
	printf("-> %10.5o\n", 42);
	ft_printf("|zero_pad| -> %010o\n", 42);
	printf("|zero_pad| -> %010o\n", 42);
	ft_printf("|zero_pad| -> %010.5o\n", 42);
	printf("|zero_pad| -> %010.5o\n", 42);
	ft_printf("|space| -> % o\n", 42);
	printf("|space| -> % o\n", 42);
	ft_printf("|sign| -> %+o\n", 42);
	printf("|sign| -> %+o\n", 42);
	ft_printf("|sign/space| -> % 05o\n", 42);
	printf("|sign/space| -> % 05o\n", 42);
	ft_printf("%zo, %zo\n", 0, USHRT_MAX);
	printf("%zo, %zo\n", 0, USHRT_MAX);
	ft_printf("{% 03o}\n", 0);
	printf("{% 03o}\n", 0);
//	ft_printf("{%3*o}\n", 0, 0);
//	printf("{%3*o}\n", 0, 0);
	ft_printf("{% 010o}\n", 0);
	printf("{% 010o}\n", 0);
	ft_printf("{% 010o}\n", 42);
	printf("{% 010o}\n", 42);
	ft_printf("{% .10o}\n", 1);
	printf("{% .10o}\n", 1);
	ft_printf("%.o, %.0d\n", 0, 0);
	printf("%.o, %.0d\n", 0, 0);
//	ft_printf("{%05.*o}\n", -15, 42);
//	printf("{%05.*o}\n", -15, 42);
	ft_printf("%o %s \n", NULL, NULL, NULL);
	printf("%o %s \n", NULL, NULL, NULL);
	ft_printf("'+' flag |%++o|\n", n);
	printf("'+' flag |%++o|\n", n);
	ft_printf("'+' flag |%++ho|\n", n);
	printf("'+' flag |%++ho|\n", n);
	ft_printf("padding with '-' flag |%--10o|\n", n);
	printf("padding with '-' flag |%--10o|\n", n);
	ft_printf("padding without '-' flag |%10o|\n", n);
	printf("padding without '-' flag |%10o|\n", n);
	ft_printf("%#.o\n", 42);
	printf("%#.o\n", 42);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	ft_printf("%O\n", LONG_MAX);
	printf("%O\n", LONG_MAX);
	ft_printf("%zO, %zO\n", 0, USHRT_MAX);
	printf("%zO, %zO\n", 0, USHRT_MAX);
	ft_printf("%jO, %jO\n", 0, USHRT_MAX);
	printf("%jO, %jO\n", 0, USHRT_MAX);
	ft_printf("%#O\n", 1);
	printf("%#O\n", 1);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	ft_printf("|%#o\n", 0);
	printf("|%#o\n", 0);
	ft_printf("|%#.o\n", 0);
	printf("|%#.o\n", 0);
	ft_printf("%O\n", LONG_MAX);
	printf("%O\n", LONG_MAX);
	printf("--------------------hex--------------\n");
	ft_printf("%lx\n", 4294967296);
	printf("%lx\n", 4294967296);
	ft_printf("%hhX\n", 4294967296);
	printf("%hhX\n", 4294967296);
	ft_printf("%jx\n", 4294967296);
	printf("%jx\n", 4294967296);
	ft_printf("%jx\n", -4294967296);
	printf("%jx\n", -4294967296);
	int tmp = ft_printf("#x: %#x\n", 42);
	int tmp2 = printf("#x: %#x\n", 42);
	ft_printf("Adding length for #x with nl case: 9==%d\n", tmp);
	printf("Adding length for #x with nl case: 9==%d\n", tmp2);
	ft_printf("|    0x2a| == |%#8x|\n", 42);
	printf("|    0x2a| == |%#8x|\n", 42);
	ft_printf("|0| = |%#x|\n", 0);
	printf("|0| = |%#x|\n", 0);
	ft_printf("|0x2a    | = |%#-08x|\n", 42);
	printf("|0x2a    | = |%#-08x|\n", 42);
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("@moulitest: |%.x %.0x|\n", 0, 0);
	printf("@moulitest: |%.x %.0x|\n", 0, 0);
	ft_printf("@moulitest: |%5.x %5.0x|\n", 0, 0);
	printf("@moulitest: |%5.x %5.0x|\n", 0, 0);	
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("' ' flag |% x|\n", n);
	printf("' ' flag |% x|\n", n);
	ft_printf("'0' flag |%0010x|\n", n);
	printf("'0' flag |%0010x|\n", n);
	ft_printf("'#' flag |%##x|\n", n);
	printf("'#' flag |%##x|\n", n);
	ft_printf("%.x, %.0x\n", 0, 0);
	printf("%.x, %.0x\n", 0, 0);
	ft_printf("|#.x, #.0x| %#.x, %#.0x\n", 0, 0);
	printf("|#.x, #.0x| %#.x, %#.0x\n", 0, 0);
	ft_printf("%#.x\n", 0);
	printf("%#.x\n", 0);
	ft_printf("%#.x\n", 42);
	printf("%#.x\n", 42);
	ft_printf("%#.X\n", 42);
	printf("%#.X\n", 42);
	ft_printf("%#.3x\n", 1);
	printf("%#.3x\n", 1);
	ft_printf("%#-10.5x\n", 42);
	printf("%#-10.5x\n", 42);
	ft_printf("%#10.5x\n", 42);
	printf("%#10.5x\n", 42);
	ft_printf("%#010x\n", 42);
	printf("%#010x\n", 42);
	ft_printf("%-#010.5x\n", 42);
	printf("%-#010.5x\n", 42);
	ft_printf("%#010.5x\n", 42);
	printf("%#010.5x\n", 42);
	ft_printf("%5.2x\n", 5427);
	printf("%5.2x\n", 5427);
	ft_printf("@moulitest: |%5.x %5.0x|\n", 0, 0);
	printf("@moulitest: |%5.x %5.0x|\n", 0, 0);
//	ft_printf("{%10R}\n");
//	printf("{%10R}\n");
//	ft_printf("%\n");
//	printf("%\n");
	ft_printf("%.5p\n", 0);
	printf("%.5p\n", 0);
	ft_printf("%10.5p\n", 0);
	printf("%10.5p\n", 0);
	int a = 42;
	ft_printf("%p\n", (void *) &a);
	printf("%p\n", (void *) &a);
	return (0);
}
