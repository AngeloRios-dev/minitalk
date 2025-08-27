/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:08:58 by angrios           #+#    #+#             */
/*   Updated: 2025/08/27 13:42:20 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_signal(int server_pid, int signal)
{
	if (signal == 1)
		kill(server_pid, SIGUSR1);
	else if (signal == 2)
		kill(server_pid, SIGUSR2);
	return (0);
}

// Usage: ./client SERVER_PID "message"
int main(int argc, char *argv[])
{
	int	pid;
	int	signal;

	(void)argc;
	pid = ft_atoi(argv[1]);
	signal = ft_atoi(argv[2]);
	send_signal(pid, signal);
	return (EXIT_SUCCESS);
}
