/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:28:14 by qlefevre          #+#    #+#             */
/*   Updated: 2022/06/08 15:48:42 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char const *s, int *len)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr("(null)", len);
	else
	{
		while (s[i])
		{
			ft_putchar(s[i], len);
			i++;
		}
	}
}

void    ft_putnbr_u(unsigned int nbr, int *len)
{
        if (nbr < 10)
                ft_putchar(nbr + 48, len);
        else
        {
                ft_putnbr_u(nbr / 10, len);
                ft_putnbr_u(nbr % 10, len);
        }
}

void    ft_putnbr_p(size_t nbr, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
        if (nbr < 16)
                ft_putchar(hex[nbr], len);
        else
        {
                ft_putnbr_p(nbr / 16, len);
                ft_putnbr_p(nbr % 16, len);
        }
}

void    ft_putnbr_x(unsigned int nbr, int *len)
{
        char    *hex;

        hex = "0123456789abcdef";
        if (nbr < 16)
        {
                ft_putchar(hex[nbr], len);
        }
        else
        {
                ft_putnbr_x(nbr / 16, len);
                ft_putnbr_x(nbr % 16, len);
        }
}


void    ft_putnbr_X(unsigned int nbr, int *len)
{
        char    *hex;

        hex = "0123456789ABCDEF";
        if (nbr < 16)
        {
                ft_putchar(hex[nbr], len);
        }
        else
        {
                ft_putnbr_X(nbr / 16, len);
                ft_putnbr_X(nbr % 16, len);
        }
}

int	ft_formats(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_putnbr_p(va_arg(args, size_t), len);
	}
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_putnbr_x(va_arg(args, unsigned int), len);
	else if (c == 'X')
		ft_putnbr_X(va_arg(args, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
	return (1);
}

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(-2, len);
		ft_putnbr(147483648, len);
	}
	else if (nbr >= 0 && nbr < 10)
	{
		ft_putchar (nbr + 48, len);
	}
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(nbr * (-1), len);
	}
	else
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	len;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start(ptr, s);

	while (s[i])
	{
		if (s[i] == '%')
			i = i + ft_formats(s[i + 1], ptr, &len);
		else
		{
			ft_putchar(s[i], &len);
		}
		i++;
	}
	va_end(ptr);
	return (len);
}

/*int	main(void)
{
	char	c = 'a';
	int	age = -2147483648;
	char	*s = NULL;

	printf("number of char = %d\n", ft_printf("Bonjour quel age %s tu? \n.%X\n%d\n\n", s, age, age));
	printf("Bonjour quel age %c tu? \n.%X\n%s", c, age, s);
	return (0);
}*/
