#include "cub3d.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = malloc (1 * sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

void	ft_lstprint(t_list *lst)
{
	if (lst)
	{
		while (lst)
			lst = lst->next;
	}
}
