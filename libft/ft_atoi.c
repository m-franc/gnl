/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:33:17 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/20 13:36:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	n;
	int			result;

	result = 0;
	n = 1;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				n = -1;
			str++;
		}
		while (*str >= 48 && *str <= 57)
			result = result * 10 + (*str++ - '0');
		return (((int)result * n));
		str++;
	}
	return (0);
}
