/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:28:02 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/19 16:56:16 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

/*
static void	ft_printheader(char *arg)
{
    printf("\n\n---------------------------------------\n");
    printf("\t\t %s\n", arg);
    printf("---------------------------------------\n\n");
}

void	test_c(void)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	
	ft_printheader("Test %c");
	printf("Testing: \t(\"%%c\", 'a')\n");
	x +=    printf("  Ft\t:\t%c", 'x');
	y += ft_printf("  Ft\t:\t%c", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"%%c\", '0')\n");
	x +=    printf("%c", '0'); printf("\n");
	y += ft_printf("%c", '0'); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: \t(\"The character %%c is visible.\", 'x')\n");
	x += printf("  Or\t:\tThe character %c is visible.\n", 'x');
	y += ft_printf("  Ft\t:\tThe character %c is visible.\n", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void    test_s(void)
{
    int	x;
	int	y;

	x = 0;
	y = 0;
    ft_printheader("Test %s");
    printf("Testing: \t(\"%%s\n\", 'TEST')\n");
	x +=    printf("  Ft\t:\t%s\n", "TEST");
	y += ft_printf("  Ft\t:\t%s\n", "TEST");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\" NULL %%s NULL %%s\", Test , Test)\n");
	x +=    printf(" NULL %s NULL %s", "Test", "Test"); printf("\n");
	y += ft_printf(" NULL %s NULL %s", "Test", "Test"); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_p(void)
{
	int		x;
	int		y;
	void	*ptr;

	ptr = "Test";
	x = 0;
	y = 0;
	ft_printheader("Test %p");
	printf("Testing: \t(\"%%p\", ptr)\n");
	x +=    printf("  Ft\t:\t%p\n", ptr);
	y += ft_printf("  Ft\t:\t%p\n", ptr);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_i(void)
{
    int	x, y;
	x = 0;
	y = 0;
    ft_printheader("Test %i");
    printf("Testing: \t(\"%%i\", 9)\n");
	x +=    printf(" %i ", 9); printf("\n");
	y += ft_printf(" %i ", 9); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: \t(\"%%i\", 10)\n");
	x +=    printf(" %i ", 10); printf("\n");
	y += ft_printf(" %i ", 10); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
    x = 0;
	y = 0;
	printf("Testing: \t(\"%%i\", 100)\n");
	x +=    printf(" %i ", 100); printf("\n");
	y += ft_printf(" %i ", 100); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
    x = 0;
	y = 0;
	printf("Testing: \t(\"%%i\", 1001)\n");
	x +=    printf(" %i ", 1001); printf("\n");
	y += ft_printf(" %i ", 1001); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void    test_u(void)
{
    int	x, y;
	x = 0;
	y = 0;
    ft_printheader("Test %u");
    printf("Testing: \t(\"%%u\", 9)\n");
	x +=    printf(" %u ", 9); printf("\n");
	y += ft_printf(" %u ", 9); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: \t(\"%%u\", -1)\n");
	x +=    printf(" %u ", -1); printf("\n");
	y += ft_printf(" %u ", -1); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
    x = 0;
	y = 0;
	printf("Testing: \t(\"%%u\", 100)\n");
	x +=    printf(" %u ", 100); printf("\n");
	y += ft_printf(" %u ", 100); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
    x = 0;
	y = 0;
	printf("Testing: \t(\"%%u\", 1001)\n");
	x +=    printf(" %u ", 1001); printf("\n");
	y += ft_printf(" %u ", 1001); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void    test_percent(void)
{
    int	x, y;
	x = 0;
	y = 0;
    ft_printheader("Test %%");
    printf("Testing: \t(\"%%%%\")\n");
	x +=    printf(" %%%% "); printf("\n");
	y += ft_printf(" %%%% "); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
    printf("Testing: \t(\"%%%%%%%%\")\n");
	x +=    printf(" %%%%%%%% "); printf("\n");
	y += ft_printf(" %%%%%%%% "); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	//
    printf("Testing: \t(\"%@\")\n");
	x +=    printf("Test %@"); printf("\n");
	y += ft_printf("Test %@"); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	//
}


void    test_NULL(void)
{
    int	x, y;
	x = 0;
	y = 0;
    ft_printheader("Test NULL");
    printf("Testing: \t(NULL)\n");
	x +=    printf(NULL); printf("\n");
	y += ft_printf(NULL); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
    printf("Testing: \t(0)\n");
	x +=    printf(0); printf("\n");
	y += ft_printf(0); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void    test_MIX(void)
{
    int	x, y;
	x = 0;
	y = 0;
    ft_printheader("Test MIX");
    printf("Testing: (\"%% %%i %% %%s %%c\",12, \"Test\", 'r')\n");
	x +=    printf("%i %% %s %c",12, "Test", 'r'); printf("\n");
	y += ft_printf("%i %% %s %c",12, "Test", 'r'); printf("\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

int main(void)
{
	test_c();
	test_s();
	test_p();
	test_i();
	test_u();
	test_percent();
	test_NULL();
	test_MIX();
	return (0);
}
*/
