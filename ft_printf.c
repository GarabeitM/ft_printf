/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:53:49 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/20 19:19:31 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_specifier(char specifier, va_list *args, int *count)
{
	if (specifier == 'c')
		*count += ft_char(va_arg(*args, int));
	else if (specifier == 's')
		*count += ft_str(va_arg(*args, char *));
	else if (specifier == 'p')
		*count += ft_ptr(va_arg(*args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		*count += ft_nbr(va_arg(*args, int));
	else if (specifier == 'u')
		*count += ft_unsigned_int(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		*count += ft_hex(va_arg(*args, unsigned int), 'x');
	else if (specifier == 'X')
		*count += ft_hex(va_arg(*args, unsigned int), 'X');
	else if (specifier == '%')
		*count += ft_char('%');
	return (*count);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, string);
	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			format_specifier(string[i], &args, &count);
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
