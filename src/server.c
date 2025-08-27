/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:06:42 by angrios           #+#    #+#             */
/*   Updated: 2025/08/27 13:45:28 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Señal 1 recibida\n");
	else if (signal == SIGUSR2)
		ft_printf("Señal 2 recibida\n");
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
