/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:10:09 by rmarquar          #+#    #+#             */
/*   Updated: 2023/11/06 10:47:06 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In this function we work with the "MEDIAN"
// First we check the stack len an divide it by 2.
// So we have the median (the middle of the list) and
// can say if it is above the middle or not and
// can choose the shortest way to make our movement.

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = check_the_stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a != NULL)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b != NULL)
		{
			if ((current_b->nbr) < (a->nbr)
				&& (current_b->nbr) > (best_match_index))
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

// This function will calculate how much moves it will cost
// to move the nodes, and will choose the cheapest (shortest) one
// to make the movement. So this is the solution to choose the shortest
// way to do the smallest movements.

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = check_the_stack_len(a);
	len_b = check_the_stack_len(b);
	while (a != NULL)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (stack == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (stack != NULL)
	{
		if ((stack->push_cost) < (cheapest_value))
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
