/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:06:23 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/17 16:12:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*result;
	int				size;
	int long		ln;

	size = ft_intlen(n);
	ln = (long int)n;
	if (!(result = (char*)malloc(sizeof(char) * (size) + 1)))
		return (NULL);
	if (ln < 0)
		*result = '-';
	result[size--] = '\0';
	if (ln <= 9 && ln >= 0)
		result[size--] = '0' + ln;
	while (ln != 0)
	{
		if (ln < 0)
			ln = -ln;
		result[size--] = '0' + (ln % 10);
		ln /= 10;
	}
	return (result);
}
