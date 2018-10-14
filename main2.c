#include "includes/ft_printf.h"
#define PUT(a) write(1, a "\n", sizeof a)

int    main(void)
{
 	ft_printf("%jd\n", -9223372036854775808);
 	printf("%jd\n", -9223372036854775808);
	ft_printf("|%10.0%|\n");
	printf("|%10.0%|\n");
    return (0);
}
