/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:55:11 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/21 20:22:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*tab;
	int	size;
	int	i;

	if (start > end)
		size = start - end;
	else
		size = end - start;
	if (!(tab = (int*)malloc(sizeof(int) * (size))))
		return (0);
	i = 0;
	while (i <= size)
	{
		if (start > end)
			tab[i++] = start--;
		else
			tab[i++] = start++;
	}
	return (tab);
}
