/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:49:59 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/19 19:35:23 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ditto(int sig, siginfo_t *info, void *str)
{
	static int	ciar;
	static int	ito;

	(void)str;
	if (sig == SIGUSR1)
	ciar += 1 << ito;
	ito++;
	if (ito == 8)
	{
		write(1, &ciar, 1);
		if (ciar == '\0')
			kill(info->si_pid, SIGUSR1);
			ciar = 0;
			ito = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	siga;

	pid = getpid();
	printf("PID: %d\n", pid);
	siga.sa_sigaction = &ditto;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	sigemptyset(&siga.sa_mask);
	while (1)
		pause();
}
