/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:30:29 by rmarquar          #+#    #+#             */
/*   Updated: 2023/12/01 15:56:33 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The main program is basicly divided in 3 main parts:
// ---------------------------------------------------------
// 1.) check the arguments who is coming in and build a linked list
// 2.) build_stack_A function and give all arguments from the linked list to it
// 3.) sort the stacks
// ---------------------------------------------------------

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	build_stack_a(&a, argv +1);
	if (!check_if_stack_is_sorted(a))
	{
		if (check_the_stack_len(a) == 2)
			sa(&a, false);
		else if (check_the_stack_len(a) == 3)
			sort_three(&a);
		else if (check_the_stack_len(a) == 4)
			sort_four(&a, &b);
		else if (check_the_stack_len(a) == 5)
			sort_five(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	// system("leaks push_swap");
	return (0);
}
