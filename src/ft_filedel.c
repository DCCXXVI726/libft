/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:24:55 by thorker           #+#    #+#             */
/*   Updated: 2020/07/05 18:56:51 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	ft_filedel(t_file **file, int fd, char **line)
{
	t_file	*curr;
	t_file	*next;

	curr = *file;
	next = curr->next;
	while (curr != 0 && next != 0)
	{
		if (next->fd == fd)
		{
			next = next->next;
			free(curr->line);
			free(curr->next);
			curr->next = next;
			return ;
		}
		curr = next;
		next = curr->next;
	}
	free(curr->line);
	free(curr);
	ft_strdel(line);
	*file = NULL;
}
