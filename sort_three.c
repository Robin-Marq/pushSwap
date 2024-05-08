/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:26:56 by rmarquar          #+#    #+#             */
/*   Updated: 2023/11/10 15:46:26 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function is to sort the last three elements in stack A,
// when everything else in the beginning was pushed to stack B
// the max value will now be on the bottom, and the min value
// will be on the top.
// After this operation, the stack b will be come back to stack A,
// node by node.

void	sort_three(t_stack_node **a)
{
	t_stack_node	*largest_node;

	largest_node = find_max(*a);
	if (largest_node == *a)
		ra(a, false);
	else if ((*a)->next == largest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	min_on_top(a);
	pb(b, a, false);
	sort_three(a);
	pa(a, b, false);
	pa(a, b, false);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	min_on_top(a);
	pb(b, a, false);
	min_on_top(a);
	pb(b, a, false);
	sort_three(a);
	pa(a, b, false);
	pa(a, b, false);
}
