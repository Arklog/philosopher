/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrfd_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:46:13 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/19 01:23:27 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

void	ft_putstrfd_mt(char *msg, int fd)
{
	static pthread_mutex_t	m = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&m);
	ft_putstrfd(ft_itoa((int64_t)get_timestamp()), fd);
	write(fd, " ", 1);
	ft_putstrfd(msg, fd);
	pthread_mutex_unlock(&m);
}
