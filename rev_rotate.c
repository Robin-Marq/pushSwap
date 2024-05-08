/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:47:25 by rmarquar          #+#    #+#             */
/*   Updated: 2023/11/06 10:30:17 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function will rotate the last element to the top of the stack
// it can be:
// --------------------------------------
// rra - move the last element from stack "A" to the top on stack "A".
// rrb - move the last element from stack "B" to the top on stack "B".
// rrr - move both elemts of the stacks from the bottom to the top.
// ---------------------------------------------------------

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool checker)
{
	rev_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	rev_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
