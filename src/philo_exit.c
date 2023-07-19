/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:34:37 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/19 02:28:14 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

static void	free_all(void)
{
	t_philo_data	*p;

	p = philo();
	while (p->iforks >= 0)
		pthread_mutex_destroy(p->forks + (p->iforks--));
	if (p->forks)
		free(p->forks);
	if (p->philos)
		free(p->philos);
}

void	philo_exit(int code, char *msg)
{
	if (msg)
		ft_putstrfd(msg, (int)(code > 0) + 1);
	exit(code);
}
