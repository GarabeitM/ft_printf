/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:52:05 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/20 19:03:40 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *args)
{
	size_t	i;

	i = 0;
	if (!args)
		return (write(1, "(null)", 6));
	while (args[i] != '\0')
	{
		ft_char(args[i]);
		i++;
	}
	return (i);
}
