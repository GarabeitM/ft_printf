/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:11:52 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/13 11:23:21 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *args)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (args[i] != '\0')
	{
		ft_char(args[i]);
		i++;
	}
	return (i);
}

/*
int	ft_nbr(int number)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (number < 0)
	{
		ft_char('-', count);
		ft_nbr(number * -1, count);
	}
	else
	{
		if (number > 9)
			ft_number(number / 10, count);
		ft_char(number % 10 + '0', count);
	}
	return ();
}

int	ft_unsigned_int(unsigned int u, int *count)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, count);
	count = ft_char(u % 10 + '0');
	return ();
}
*/
/*void	ft_ptr(size_t pointer, int *count)
{
	char	string[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*count) += 2;
	if (pointer == 0)
	{
		ft_char('0', count);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_char(string[i], count);
	}
}

void	ft_hex(unsigned int x, int *count, char x_or_x)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_char('0', count);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_char(string[i], count);
}*/




static int	ft_flag(char s, va_list *args, int *count)
{
	if (s == '%')
		*count += ft_char('%');
	else if (s == 'c')
		*count += ft_char(va_arg(*args, int));
	else if (s == 's')
		*count += ft_str(va_arg(*args, char *));
	/*else if (s == 'd' || s == 'i')
		*count += ft_nbr(va_arg(*args, int));
	else if (s == 'u')
		*count += ft_unsigned_int(va_arg(*args, unsigned int));
	else if (s == 'x')
		*count += ft_hex(va_arg(*args, unsigned int), count, 'x');
	else if (s == 'X')
		*count += ft_hex(va_arg(*args, unsigned int), count, 'X');
	else if (s == 'p')
		*count += ft_ptr(va_arg(*args, size_t), count);*/
	return (*count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_flag(string[i], &args, &count);
			i++;
		}
		else
		{
			count += ft_char((char)string[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int e;
	int	f;

	a = ft_printf("HI\n");
	b = printf("HI\n");
	printf("mine: %d, built-in: %d\n", a, b);

	c = ft_printf("Hi %s", "there.\n");
	d = printf("Hi %s", "there.\n");
	printf("mine: %d, built-in: %d\n", c, d);

	e = ft_printf("0\n");
	f = printf("0\n");
	printf("mine: %d, built-in: %d\n", e, f);	
}
