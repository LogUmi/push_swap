/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:39 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/31 18:16:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_lstclear_ps(t_list **lst)
{
	t_list	*tlst;
	t_list	*slst;

	tlst = *lst;
	while (tlst != 0)
	{
		slst = tlst->next;
		free(tlst);
		tlst = slst;
	}
	*lst = 0;
	return ;
}

int	ft_freestack(t_list **a, t_list **b, int **nbr)
{
	int	i;

	i = 0;
	ft_lstclear_ps(a);
	ft_lstclear_ps(b);
	if (nbr && nbr[0])
	{
		while (nbr[i])
			free(nbr[i++]);
		free(nbr);
	}
	return (0);
}

static int	startorder(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 1)
		return (1);
	if (ft_lstsize(*a) == 2)
		algo_2(a, b);
	if (ft_lstsize(*a) == 3)
		algo_3(a, b);
	if (ft_lstsize(*a) == 4)
		algo_4(a, b, 0);
	if (ft_lstsize(*a) == 5)
		algo_5(a, b);
	if (ft_lstsize(*a) > 5 && ft_lstsize(*a) <= 75)
		algo_50(a, b, 0, 0);
	if (ft_lstsize(*a) > 75)
		if (algo_radix(a, b) == 0)
			return (0);
	return (1);
}

int	setstack(int **nbr, int i)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(nbr[i--]);
	if (!a)
		return (ft_freenbr(nbr));
	while (i > -1)
	{
		b = ft_lstnew(nbr[i--]);
		if (!b)
			return (ft_freestack(&a, &b, nbr));
		ft_lstadd_front(&a, b);
	}
	b = NULL;
	if (testsort(&a, &b, 0, 0) == 0)
		return (ft_freestack(&a, &b, nbr));
	if (startorder(&a, &b) == 0)
		write (1, "Error\n", 6);
	return (ft_freestack(&a, &b, nbr));
}
