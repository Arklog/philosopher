/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:15:35 by pierre            #+#    #+#             */
/*   Updated: 2023/07/10 01:54:02 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

/**
 * Convert the initial portion of s into a long integer according to the
 * given base, if successful *endptr == s evaluate to true
 *
 * @param s		the string to be converted
 * @param endptr
 * @param base		the base in which to convert
 * @return
 *
 * @warning			if the specified base is different from 8, 10 or 16
 * 					the function behavior is undefined
 * @warning			s must be not NULL
 * @warning			*endptr should point to something other than s (in case
 * 					of)
 */
long	ft_strtol(const char *s, char **endptr, int base);

int		ft_strtoi(const char *str, char **endptr, int base);

/**
 * Convert the string str into i
 * @param str
 * @return
 */
int		ft_atoi(char *str);

#endif
