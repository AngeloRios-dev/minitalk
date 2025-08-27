/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:06:42 by angrios           #+#    #+#             */
/*   Updated: 2025/08/27 17:32:29 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_char = 0;
int		g_bit_counter = 0;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_char = (g_char << 1);
	else if (signal == SIGUSR2)
		g_char = (g_char << 1) | 1;
	g_bit_counter++;
	if (g_bit_counter == 8)
	{
		write(1, &g_char, 1);
		g_char = 0;
		g_bit_counter = 0;
	}
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
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
