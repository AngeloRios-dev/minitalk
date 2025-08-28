/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:06:42 by angrios           #+#    #+#             */
/*   Updated: 2025/08/28 21:32:57 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	store_message(char **msg, char new_char)
{
	char	*temp_msg;
	char	str[2];

	str[0] = new_char;
	str[1] = '\0';	
	temp_msg = ft_strjoin(*msg, str);
	if (!temp_msg)
		return (1);
	free(*msg);
	*msg = temp_msg;
	return (0);
}

void	signal_handler(int signal)
{
	static char		chr;
	static int		bit_counter;
	static char		*msg;

	if (signal == SIGUSR1)
		chr = (chr << 1);
	if (signal == SIGUSR2)
		chr = (chr << 1) | 1;
	bit_counter++;
	if (bit_counter == 8)
	{
		// write(1, &chr, 1);
		store_message(&msg, chr);
		chr = 0;
		bit_counter = 0;
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
