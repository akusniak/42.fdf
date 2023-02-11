/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:46:45 by akusniak          #+#    #+#             */
/*   Updated: 2022/11/22 11:22:24 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_list;

	if (*lst)
	{
		while (*lst)
		{
			temp_list = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp_list;
		}
		*lst = 0;
	}
}
