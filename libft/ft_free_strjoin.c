/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 04:28:24 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/27 03:28:51 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strjoin(char *s1, char *s2, char **leaks)
{
	char	*new;

	new = *leaks;
	*leaks = ft_strjoin(s1, s2);
	if (new)
		free(new);
	new = NULL;
}
