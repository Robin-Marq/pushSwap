/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:01:44 by rmarquar          #+#    #+#             */
/*   Updated: 2023/11/06 10:16:07 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function will swap two nodes:
// ----------------------------------
// sa - for swap a
// sb - for swap b
// ss - for swap swap - both will be swapped
// -----------------------------------------

static	void	swap(t_stack_node **head)
{
	t_stack_node	*current;
	t_stack_node	*prev;
	t_stack_node	*next;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	prev = current->prev;
	next = current->next;
	if (prev != NULL)
	{
		prev->next = next;
		current->prev = prev;
	}
	if (next != NULL)
	{
		next->prev = prev;
		current->next = next->next;
		next->next = current;
	}
	current->prev = NULL;
	*head = next;
}

void	sa(t_stack_node	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
