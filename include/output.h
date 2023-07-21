/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:34:53 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/19 02:12:25 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include <pthread.h>
# include <sys/time.h>
# include "defines.h"
# include "libft.h"

/**
 * Thread sage putstrfd
 * 
 * @param msg	the message to write
 * @param fd	the file descriptor to write in
*/
void		ft_putstrfd_mt(char *msg, int fd);

void		is_sleeping(t_thread_data *d);

void		is_eating(t_thread_data *d);

void		is_thinking(t_thread_data *d);

void		is_dead(t_thread_data *d);

void		is_taking_fork(t_thread_data *d);

u_int64_t	get_timestamp(void);

#endif