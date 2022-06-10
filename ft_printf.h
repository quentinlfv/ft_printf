/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:18:59 by qlefevre          #+#    #+#             */
/*   Updated: 2022/06/10 15:13:40 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

void	ft_putnbr(int nbr, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char const *s, int *len);
void	ft_putnbr_u(unsigned int nbr, int *len);
void	ft_putnbr_p(va_list arg, int *len);
void	ft_putnbr_x(unsigned long nbr, int *len);
void	ft_putnbr_upx(unsigned long nbr, int *len);
void	ft_putnbr(int nbr, int *len);
int		ft_formats(char c, va_list args, int *len);
int		ft_printf(const char *s, ...);

#endif
