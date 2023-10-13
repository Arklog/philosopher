/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:45:20 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/26 14:45:20 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <pthread.h>

char	*ft_itoa(int64_t val)
{
	static __thread char	buff[21] = {0};
	size_t					i;
	char					c;
	int						mul;

	ft_memset(&buff, 0, 21);
	i = 19;
	if (val < 0)
		mul = -1;
	else
		mul = 1;
	while (val)
	{
		c = (val % 10) * mul;
		buff[i--] = c + 48;
		val /= 10;
	}
	if (mul < 0)
		buff[i] = '-';
	return (buff);
}
