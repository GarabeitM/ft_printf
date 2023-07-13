/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:11:58 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/13 11:26:00 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_char(char c);
int		ft_str(char *args);
int		ft_nbr(int number);
int		ft_unsigned_int(unsigned int u);
int		ft_printf(const char *string, ...);

#endif