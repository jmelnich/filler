/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:52:25 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/19 19:27:14 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int visual(void)
{
	char *line;

	line = NULL;
	get_next_line(STDIN_FILENO, &line);
	printf("%s\n", line);
	return (1);
}

int	main(void)
{
	visual();
	return (0);
}