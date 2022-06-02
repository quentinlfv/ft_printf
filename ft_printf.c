/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:28:14 by qlefevre          #+#    #+#             */
/*   Updated: 2022/06/01 18:22:07 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nbr);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void    ft_putnbr_tolow_hexa(unsigned long long nbr)
{
	char	*hex;

	hex = "01";
        if (nbr == -2147483648)
        {
                ft_putnbr(-2);
                ft_putnbr(147483648);
        }
        else if (nbr >= 0 && nbr < 2)
        {
                ft_putchar (hex[nbr]);
        }
        else if (nbr < 0)
        {
                ft_putchar('-');
                ft_putnbr(nbr * (-1));
        }
        else
        {
                ft_putnbr(nbr / 2);
                ft_putnbr(nbr % 2);
        }
}

void    ft_putnbr_toup_hexa(int nbr)
{
        char    *hex;

        hex = "0123456789ABCDEF";
        if (nbr == -2147483648)
        {
                ft_putnbr(-2);
                ft_putnbr(147483648);
        }
        else if (nbr >= 0 && nbr < 16)
        {
                ft_putchar (hex[nbr]);
        }
        else if (nbr < 0)
        {
                ft_putchar('-');
                ft_putnbr(nbr * (-1));
        }
        else
        {
                ft_putnbr(nbr / 16);
                ft_putnbr(nbr % 16);
        }
}

int	ft_formats(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		ft_putnbr_tolow_hexa(va_arg(args, unsigned long long));
	else if (c == 'u')
		ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		ft_putnbr_tolow_hexa((unsigned long long)va_arg(args, int));
	else if (c == 'X')
		ft_putnbr_toup_hexa(va_arg(args, int));
	else if (c == '%')
		ft_putchar('%');
	return (1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
	}
	else if (nbr >= 0 && nbr < 10)
	{
		ft_putchar (nbr + 48);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * (-1));
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	ft_printf(const char *s, ...)
{
	int	i;
	va_list	ptr;

	i = 0;
	va_start(ptr, s);

	while (s[i])
	{
		if (s[i] == '%')
			i = i + ft_formats(s[i + 1], ptr);
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (i);
}

int	main(void)
{
	char	c = 'a';
	int	age = 10.35;
	char	*s = "et je m'apelle Mucho\n";

	ft_printf("Bonjour quel age %c tu? \n-%X\n%p\n", c, age, s);
	printf("Bonjour quel age %c tu? \n-%X\n%p", c, age, s);
	return (0);
}
