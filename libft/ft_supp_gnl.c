/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:30:35 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/27 07:01:57 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_malloc(char **stat)
{
	*stat = malloc(sizeof(char) * 1);
	*stat[0] = '\0';
	return (*stat);
}

int	ft_supp_gnl(char *stat, char **line)
{
	if (!stat)
		stat = ft_malloc(&stat);
	if (ft_checkfile(stat) != -1)
	{
		*line = ft_sub_str(stat, 0, ft_checkfile(stat));
		stat = ft_run_stat(stat);
		return (1);
	}
	return (0);
}
