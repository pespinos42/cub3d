#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    struct s_list   *next;
    char            *content;
}   t_list;

typedef struct s_data
{
    char    *nombre_fichero;
    t_list  *lista;
}   t_data;

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
		return(NULL);
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
        {
            printf("VALOR DEL NODO -> %s\n", lst->content);
            lst = lst->next;
        }
    }
}

int main()
{
    t_data miEstructura;
    miEstructura.lista = NULL;

    ft_lstadd_back(&miEstructura.lista, ft_lstnew("HOLA MUNDO"));
    ft_lstadd_back(&miEstructura.lista, ft_lstnew("¿Qué tal?"));

    ft_lstprint(miEstructura.lista);

    return (0);
}