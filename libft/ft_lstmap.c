/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:35:55 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/03 16:12:29 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_clear(t_list **lst, void (*del)(void *), void *content)
{
	if (content)
		del(content);
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new;
	void	*temp;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		temp = f(lst->content);
		if (temp == NULL)
			return (ft_clear(&new_list, del, temp));
		new = ft_lstnew(temp);
		if (new == NULL)
			return (ft_clear(&new_list, del, temp));
		ft_lstadd_back(&new_list, new);
		lst = lst->next;
	}
	return (new_list);
}
