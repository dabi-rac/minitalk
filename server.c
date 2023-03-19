/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:49:59 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/19 13:13:23 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ditto(int sig)
{
    static  unsigned char   ciar = 0;
    static  int             ito = 0;
    
    ciar |= (sig == SIGUSR1);
    if(++ito == 8)
    {
        ito = 0;
        write(1, &ciar, 1);
        ciar = 0;
    }
    else
    ciar += 1 << ito;
}


int     main(void)
{
    pid_t   pid;
    
    pid = getpid();
    printf("PID: %d\n", pid);
    signal(SIGUSR1, ditto);
    signal(SIGUSR2, ditto);
    while(1)
        pause();
}