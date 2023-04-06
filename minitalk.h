/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:51:40 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/23 23:13:03 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_hex_putnbr(unsigned int nb, const char *s);
int		ft_address_print(unsigned long point, const char *s);
int		ft_putnbr_unsigned(unsigned int nb);
#endif
