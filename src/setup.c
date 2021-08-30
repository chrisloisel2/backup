/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 16:28:57 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	ft_raloc(t_stack *r)
{
	r->a = malloc(sizeof(int) * r->lena + 1);
	r->b = malloc(sizeof(int) * r->lena + 1);
	r->tl = malloc(sizeof(int) * r->lena + 1);
	return (0);
}

int	ft_test(char *str, long max, t_stack *r)
{
	int		i;
	long	test;

	test = ft_long_atoi(str);
	if (test > 2147483647 || test < -2147483648)
		return (0);
	i = 0;
	while (i < max)
	{
		if (r->a[i] == test)
			return (0);
		i++;
	}
	return (1);
}

int	ft_fill_stack2(char **argv, int num, t_stack *r)
{
	int		i;
	int		y;
	char	**tab;

	y = 0;
	r->lenmax = r->lena;
	ft_raloc(r);
	tab = ft_split(argv[1], ' ');
	while (num >= 0)
	{
		i = 0;
		while (tab[num][i] != '\0' && (ft_isdigit(tab[num][i]) ||
					(tab[num][i] == '-' && i == 0)))
			i++;
		if (i != ft_strlen(tab[num]))
			return (ft_freed(r, tab));
		if (!((tab[num][i] == '\0') && ft_test(tab[num], y, r)))
			return (ft_freed(r, tab));
		r->a[y] = ft_atoi(tab[num]);
		y++;
		num--;
	}
	free_tab(tab);
	r->lena = r->lenmax;
	return (0);
}

int	ft_fill_stack(int num, char **argv, t_stack *r)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	r->lenmax = num;
	ft_raloc(r);
	while (num > 0)
	{
		while (argv[num][i] != '\0' && (ft_isdigit(argv[num][i]) ||
					(argv[num][i] == '-' && i == 0)))
			i++;
		if (i != ft_strlen(argv[num]))
			return (ft_negafree(r));
		if (!((argv[num][i] == '\0') && ft_test(argv[num], y, r)))
			return (ft_negafree(r));
		r->a[y] = ft_atoi(argv[num]);
		y++;
		i = 0;
		num--;
	}
	return (1);
}

int	ft_check_arg(int num, char **argv, t_stack *r)
{
	int	i;

	i = 0;
	r->lena = num;
	r->lenb = 0;
	while (num > 0)
	{
		while (argv[num][i] != '\0' && (ft_isdigit(argv[num][i]) ||
					(argv[num][i] == '-' && ft_isdigit(argv[num][i + 1]))))
			i++;
		if (i != ft_strlen(argv[num]))
			return (-1);
		if (!(argv[num][i] == '\0'))
			return (-1);
		i = 0;
		num--;
	}
	return (1);
}
