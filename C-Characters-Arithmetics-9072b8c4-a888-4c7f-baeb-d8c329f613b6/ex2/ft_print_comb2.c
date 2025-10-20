/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalayyou <nalayyou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:31:38 by nalayyou          #+#    #+#             */
/*   Updated: 2025/10/20 14:32:09 by nalayyou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = -nb2;
	}
	if (nb2 >= 10)
	{
		ft_putnbr(nb2 / 10);
		ft_putnbr(nb2 % 10);
	}
	if (nb2 < 10)
	{
		ft_putchar(nb2 + '0');
	}
}

void	printtwo(int a, int b)
{
	if (a <= 9)
	{
		ft_putnbr(0);
		ft_putnbr(a);
	}
	else
		ft_putnbr(a);
	write(1, " ", 1);
	if (b <= 0)
	{
		ft_putnbr(0);
		ft_putnbr(b);
	}
	else
		ft_putnbr(b);
}

void	ft_print_comb2(void)
{
	long int	a;
	long int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a != b)
				printtwo(a, b);
			if (a != 98 && b != 99)
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
			b++;
		}
		a++;
	}
}
