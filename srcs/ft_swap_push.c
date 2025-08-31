/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:45:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/31 18:16:22 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*sa(t_list **a)
{
	t_list	*lst;
	void	*cfirst;

	lst = *a;
	if (ft_lstsize(lst) < 2)
		return (NULL);
	cfirst = lst->next->content;
	lst->next->content = lst->content;
	lst->content = cfirst;
	return ("sa\n");
}

char	*sb(t_list **b)
{
	t_list	*lst;
	void	*cfirst;

	lst = *b;
	if (ft_lstsize(lst) < 2)
		return (NULL);
	cfirst = lst->next->content;
	lst->next->content = lst->content;
	lst->content = cfirst;
	return ("sb\n");
}

char	*ss(t_list **a, t_list **b)
{
	char	*ca;
	char	*cb;

	ca = sa(a);
	cb = sb(b);
	if (ca == NULL && cb == NULL)
		return (NULL);
	return ("ss\n");
}

char	*pa(t_list **a, t_list **b)
{
	void	*nfirsta;
	void	*nfirstb;

	if (ft_lstsize(*b) == 0)
		return (NULL);
	if (ft_lstsize(*b) < 2)
		nfirstb = 0;
	else
		nfirstb = (*b)->next;
	if (ft_lstsize(*a) == 0)
		nfirsta = 0;
	else
		nfirsta = (*a);
	(*b)->next = nfirsta;
	(*a) = *b;
	(*b) = nfirstb;
	return ("pa\n");
}

char	*pb(t_list **a, t_list **b)
{
	void	*nfirsta;
	void	*nfirstb;

	if (ft_lstsize(*a) == 0)
		return (NULL);
	if (ft_lstsize(*a) < 2)
		nfirsta = 0;
	else
		nfirsta = (*a)->next;
	if (ft_lstsize(*b) == 0)
		nfirstb = 0;
	else
		nfirstb = (*b);
	(*a)->next = nfirstb;
	(*b) = *a;
	(*a) = nfirsta;
	return ("pb\n");
}
