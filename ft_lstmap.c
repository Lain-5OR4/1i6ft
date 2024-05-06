/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:02:36 by sebiko            #+#    #+#             */
/*   Updated: 2024/05/03 19:21:48 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*return_list;
	void	*tmp_content;

	if (!lst || !f || !del)
		return (NULL);
	return_list = NULL;
	while (lst)
	{
		tmp_content = f(lst->content);
		new_list = ft_lstnew(tmp_content);
		if (!new_list)
		{
			del(tmp_content);
			ft_lstclear(&return_list, del);
			return (NULL);
		}
		ft_lstadd_back(&return_list, new_list);
		lst = lst->next;
	}
	new_list->next = NULL;
	return (return_list);
}
