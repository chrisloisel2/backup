/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/26 22:36:39 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	ft_print_lst(t_lst *s, t_stack *r)
{
	int	i;

	if (r->lena > r->lenb)
		i = r->lena - 1;
	else
		i = r->lenb - 1;
	printf("  état de la stack %d\n-----------------------\n", s->core);
	printf("   {%d}            {%d}\nnum = ", r->lena, r->lenb);
	while (i >= 0)
	{
		if (r->lena > i)
			printf("|a[%d]", r->a[i]);
		else
			printf("     ");
		printf("    %d       ", i);
		if (r->lenb > i)
			printf("b[%d]|\n", r->b[i]);
		else
			printf("\n");
		i--;
	}
	printf("range = %d\n", s->range);
	printf("\n");
}

void	ft_print_core(t_lst *s)
{
	printf("----------core = %d----------\n", s->core);
	printf("  range[%d]\n", s->range);
	printf(" posmax[%d]\n", s->posmax);
	printf(" posmin[%d]\n", s->posmin);
	printf("    max[%d]\n", s->max);
	printf("    min[%d]\n", s->min);
	printf("   push[%d]\n", s->top);
	printf("   push[%d]\n", s->bot);
}
