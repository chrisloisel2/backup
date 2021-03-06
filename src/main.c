/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 16:11:54 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	free_all(t_lst *s, t_stack *r)
{
	t_lst	*x;

	s = lstlast(s);
	x = NULL;
	while (s != NULL)
	{
		if (s->prev != NULL)
			x = s->prev;
		else
			x = NULL;
		free (s);
		s = NULL;
		s = x;
	}
	free(r->tl);
	r->tl = NULL;
	free(r->a);
	r->a = NULL;
	free(r->b);
	r->b = NULL;
	free(r);
	r = NULL;
}

int	ft_push_swap(int num, char **argv)
{
	t_lst	*s;
	t_stack	*r;

	s = lstnew();
	r = malloc(sizeof(t_stack));
	r->coup = 0;
	if (ft_recup(num, argv, r) == -1)
	{
		free(r);
		free(s);
		return (-1);
	}
	order(r->tl, r->lena, r->a);
	s = ft_algo(s, r);
	free_all(s, r);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
		ft_push_swap(argc, argv);
	while(1);
	return (0);
}
