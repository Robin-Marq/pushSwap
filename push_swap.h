/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:30:49 by rmarquar          #+#    #+#             */
/*   Updated: 2023/11/10 15:47:35 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

void			build_stack_a(t_stack_node **a, char **argv);
char			**split(char *str, char separator);

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

int				check_the_stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			check_if_stack_is_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			min_on_top(t_stack_node **a);

void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			set_target_b(t_stack_node *a, t_stack_node *b);

#endif

// 100 Random Numbers:
//
// 81 -10 43 100 45 -64 -31 23 14 -24 61 87 72 76 -71 -11 34 -39 67 -15 83 10 -41 -14 42 -72 86 69 7 79 97 -21 -30 66 -100 88 -59 -89 -23 95 11 -58 -6 -92 74 19 -45 -90 36 -38 28 5 -66 -28 -75 91 -87 99 18 24 -16 38 -4 26 77 -29 -1 -50 59 78 57 62 31 40 -48 -86 -88 -94 -54 3 73 20 82 56 37 52 -74 85 89 2 -34 -57 -82 -49 -56 98 -65 -2 6 27

// 500 RANDOM NUMBERS:
//
// 136 -66 -49 -335 -402 -233 380 223 78 -168 192 -171 -239 -395 -163 176 -322 -323 -404 347 -165 121 140 76 -296 -387 448 -414 326 -473 34 0 58 359 -377 -80 32 55 214 198 12 -310 -342 -15 152 354 -247 346 351 37 -487 294 -380 -181 434 -36 -141 483 159 342 -240 155 431 133 -145 -440 -354 7 -78 87 -471 47 197 102 355 -244 445 255 63 -455 -232 45 -327 475 368 1 -298 -207 117 -200 424 206 -332 -399 238 487 303 -9 41 -162 405 331 -352 129 -256 390 457 -1 362 -62 2 -28 -280 -416 480 25 -279 283 413 -270 275 -465 -308 467 -422 -230 453 492 -23 -211 344 314 -359 -273 -199 322 462 -426 -19 -2 114 -26 -489 -360 -274 -129 -212 293 -51 -500 338 -301 77 212 -7 190 199 316 -430 14 -56 364 -40 -428 441 -383 315 171 -83 -113 -214 26 -446 -135 365 -11 -146 -348 391 -173 393 -339 381 244 317 477 -389 -294 -345 68 93 305 -73 81 337 433 -488 497 9 -271 426 113 -448 -96 -144 -105 172 -114 439 84 -261 -424 -293 222 202 -219 309 -328 156 49 -290 -478 -22 -54 115 69 -122 -453 154 280 -278 -229 325 -104 -90 369 -85 -415 -133 268 35 298 -224 404 419 -188 -447 -412 -39 335 422 -6 182 -98 94 -277 318 67 -349 -388 180 -343 245 378 340 59 -443 360 403 295 19 -5 361 -382 160 481 485 -63 266 -408 -29 -460 443 215 -463 398 -435 130 108 -33 491 -172 257 5 123 -95 251 -355 239 -445 217 92 276 -34 16 243 138 -153 -496 -169 -222 -492 248 267 417 -281 193 109 -237 -346 -490 103 -260 -497 23 141 -75 -385 -213 200 39 -149 145 -409 -480 -283 194 126 463 -373 -226 -258 -225 134 388 -13 196 432 -470 -150 -24 226 30 169 184 -100 233 348 143 70 -493 -176 -159 428 235 -126 -288 86 291 -174 137 111 -238 -140 -253 52 -467 488 185 -267 -330 -403 330 131 178 -474 139 -381 471 99 -194 -41 -265 476 358 166 382 179 -47 -303 374 -127 310 -420 -221 468 -18 370 40 429 -444 -397 -245 -481 308 231 230 -161 411 53 -429 -186 -30 135 339 282 219 -367 -262 158 85 -170 -184 -418 -91 153 -35 -264 174 -209 -158 -441 -374 -311 -217 186 -57 -479 416 237 -138 -472 350 474 33 425 478 -32 262 165 394 -454 -433 -396 -72 -347 -59 -216 -12 -266 210 -190 -259 353 -166 -175 -457 395 207 181 -196 204 -215 151 436 -177 -379 423 -180 -252 -314 319 470 80 482 167 105 464 246 64
