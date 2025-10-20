/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalayyou <nalayyou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:05:58 by nalayyou          #+#    #+#             */
/*   Updated: 2025/10/20 14:06:05 by nalayyou         ###   ########.fr       */
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

void	shortprint(int a, int b, int c)

{
	ft_putnbr(a);
	ft_putnbr(b);
	ft_putnbr(c);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb(void)

{
	int long	a;
	int long	b;
	int long	c;

	a = 0;
	while (a < 9)
	{
		b = a + 1;
		while (b <= 9)
		{
			c = b + 1;
			while (c <= 9)
			{
				if (a != b && a != c && b != c)
				{
					shortprint(a, b, c);
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
