/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:14:15 by thorker           #+#    #+#             */
/*   Updated: 2018/11/29 16:54:23 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*curr;

	if (del == NULL || alst == NULL)
		return ;
	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		ft_lstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
