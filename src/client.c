/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:08:58 by angrios           #+#    #+#             */
/*   Updated: 2025/08/28 20:45:49 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <time.h>

static void	ft_usleep(int microseconds)
{
	struct timespec ts;

	ts.tv_sec = microseconds / 1000000;
	ts.tv_nsec = (microseconds % 1000000) * 1000;
	nanosleep(&ts, NULL);
}

int	send_signal(int server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, SIGUSR1);
	else if (bit == 1)
		kill(server_pid, SIGUSR2);
	ft_usleep(100);
	return (0);
}

int	send_char(int server_pid, char chr)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (chr >> i) & 1;
		send_signal(server_pid, bit);
		i--;
	}
	
	return (0);
}

int main(int argc, char *argv[])
{
	int		i;
	int		pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <SERVER_PID> <MESSAGE>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	ft_printf("Message sent succesfully!\n");
	return (EXIT_SUCCESS);
}
