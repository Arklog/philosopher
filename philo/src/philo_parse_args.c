/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:36:36 by pierre            #+#    #+#             */
/*   Updated: 2023/10/10 18:36:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_stdlib.h"

void	philo_parse_args(int argc, char **argv, t_philo_data *d)
{
	char	*endptr;

	if (argc < 5 || argc > 6)
		philo_exit(d);
	endptr = NULL;
	d->nphilos = ft_strtoi(argv[1], &endptr, 10);
	if (endptr != argv[1] + ft_strlen(argv[1]) || d->nphilos <= 0)
		philo_exit(d);
	d->ttd = ft_strtoi(argv[2], &endptr, 10);
	if (endptr != argv[2] + ft_strlen(argv[2]) || d->ttd < 0)
		philo_exit(d);
	d->tte = ft_strtoi(argv[3], &endptr, 10);
	if (endptr != argv[3] + ft_strlen(argv[3]) || d->tte < 0)
		philo_exit(d);
	d->tts = ft_strtoi(argv[4], &endptr, 10);
	if (endptr != argv[4] + ft_strlen(argv[4]) || d->tts < 0)
		philo_exit(d);
}
