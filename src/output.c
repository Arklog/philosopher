/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 02:03:50 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/19 02:14:59 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

void	is_sleeping(t_thread_data *p)
{
	char	*tmp;

	tmp = ft_strcat(ft_itoa(p->tid), " is sleeping");
	ft_putstrfd_mt(tmp, 1);
	free(tmp);
}

void	is_eating(t_thread_data *p)
{
	char	*tmp;

	tmp = ft_strcat(ft_itoa(p->tid), " is eating");
	ft_putstrfd_mt(tmp, 1);
	free(tmp);
}

void	is_thinking(t_thread_data *p)
{
	char	*tmp;

	tmp = ft_strcat(ft_itoa(p->tid), " is thinking");
	ft_putstrfd_mt(tmp, 1);
	free(tmp);
}

void	is_dead(t_thread_data *p)
{
	char	*tmp;

	tmp = ft_strcat(ft_itoa(p->tid), " is died");
	ft_putstrfd_mt(tmp, 1);
	free(tmp);
}

void	is_taking_fork(t_thread_data *p)
{
	char	*tmp;

	tmp = ft_strcat(ft_itoa(p->tid), " has taken a fork");
	ft_putstrfd_mt(tmp, 1);
	free(tmp);
}
