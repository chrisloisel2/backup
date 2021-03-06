/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/26 22:44:10 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	order2(int *d, int x, int *a)
{
	int	i;
	int	y;
	int	test;

	y = 1;
	test = 2147483647;
	i = 0;
	while (y < x)
	{
		while (i < x)
		{
			if (a[i] < test && a[i] > d[y - 1])
				test = a[i];
			i++;
		}
		d[y] = test;
		test = 2147483647;
		y++;
		i = 0;
	}
}

void	order(int *d, int x, int *a)
{
	int	i;
	int	test;

	i = x - 1;
	test = 2147483647;
	while (a != NULL && i >= 0)
	{
		if (a[i] < test)
			test = a[i];
		i--;
	}
	d[0] = test;
	order2(d, x, a);
}

int	ft_check_order(t_stack *r)
{
	int	i;
	int	y;

	y = r->lenmax - 1;
	i = 0;
	if (r->lena == 0)
		return (2);
	while (i < r->lena && (r->a[i] == r->tl[y]))
	{
		i++;
		y--;
	}
	if (y == -1)
		return (0);
	if (i == r->lena)
		return (2);
	return (1);
}

long	ft_long_atoi(const char *str)
{
	int		i;
	int		neg;
	long	nb;

	nb = 0;
	i = 0;
	neg = 1;
	while (ft_white_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}
