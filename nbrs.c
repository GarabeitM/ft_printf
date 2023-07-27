/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:53:05 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/21 11:21:06 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long pointer)
{
	int		i;
	int		count;
	char	string[20];
	char	*base_character;

	i = 0;
	count = 0;
	if (pointer == 0)
		return (write(1, "(nil)", 5));
	base_character = "0123456789abcdef";
	count += write(1, "0x", 2);
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		count += ft_char(string[i]);
	return (count);
}

int	ft_nbr(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		count += ft_char('-');
		count += ft_nbr(number * -1);
	}
	else
	{
		if (number > 9)
			count += ft_nbr(number / 10);
		count += ft_char(number % 10 + '0');
	}
	return (count);
}

int	ft_unsigned_int(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
		count += ft_unsigned_int(u / 10);
	count += ft_char(u % 10 + '0');
	return (count);
}

int	ft_hex(unsigned int x, char x_case)
{
	int		i;
	int		count;
	char	string[8];
	char	*base_character;

	if (x_case == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	count = 0;
	if (x == 0)
		return (count += ft_char('0'));
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		count += ft_char(string[i]);
	return (count);
}