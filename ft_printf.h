/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:18:59 by qlefevre          #+#    #+#             */
/*   Updated: 2022/06/08 14:27:02 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

void    ft_putnbr(int nbr, int *len);
void    ft_putchar(char c, int *len);
void    ft_putptr_tolow_hexa(size_t nbr, int *len);
void    ft_putnbr_tolow_hexa(int nbr, int *len);
void    ft_putnbr_toup_hexa(int nbr, int *len);
int     ft_formats(char c, va_list args, int *len);
void    ft_putnbr(int nbr, int *len);
int     ft_printf(const char *s, ...);

#endif
