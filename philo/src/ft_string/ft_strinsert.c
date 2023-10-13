/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:30:57 by pducloux          #+#    #+#             */
/*   Updated: 2023/06/30 21:29:00 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strinsert(const char *str, const char *begin, const char *what)
{
	size_t	strlen;
	size_t	wlen;
	char	*new;

	strlen = ft_strlen(str);
	wlen = ft_strlen(what);
	new = malloc(strlen + wlen + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, str, begin - str);
	ft_memcpy(new + (begin - str), what, wlen);
	if (begin < str + ft_strlen(str))
		ft_memcpy(new + (begin - str) + wlen, begin + 1, ft_strlen(begin + 1));
	new[strlen + wlen] = 0;
	return (new);
}
