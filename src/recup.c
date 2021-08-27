/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:49:32 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/27 03:49:35 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	ft_recup_split(char **argv, t_stack *r)
{
	int	i;
	int	len;

	len = ft_strlen(argv[1]) - 1;
	i = 0;
	r->lena = 1;
	r->lenb = 0;
	while (argv[1][i] != '\0' && (ft_isdigit(argv[1][i + 1]) ||
				argv[1][i + 1] == '-' || argv[1][i + 1] == ' '))
	{
		if (argv[1][i] == ' ' && (ft_isdigit(argv[1][i + 1]) ||
					argv[1][i + 1] == '-'))
			r->lena++;
		i++;
	}
	if (i == len)
		return (ft_fill_stack2(argv, r->lena - 1, r));
	return (1);
}

int	ft_recup(int num, char **argv, t_stack *r)
{
	if (num == 2 && (ft_strlen(argv[1]) > 2) && ft_recup_split(argv, r) == 1)
	{
		printf("ERROR\n");
		return (-1);
	}
	else if (num > 2 && (ft_check_arg(num - 1, argv, r) == -1
			|| ft_fill_stack(num - 1, argv, r) == -1))
	{
		printf("ERROR\n");
		return (-1);
	}
	return (0);
}