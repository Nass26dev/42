/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ww.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:01:46 by nass              #+#    #+#             */
/*   Updated: 2024/12/20 18:01:47 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_WW_H
# define RULES_WW_H

# include "push_swap.h"

// swap.c
void	sa_ww(t_stack *a);
void	sb_ww(t_stack *b);
void	ss_ww(t_stack *a, t_stack *b);
// push.c
void	pa_ww(t_stack *a, t_stack *b);
void	pb_ww(t_stack *a, t_stack *b);
// rotate.c
void	ra_ww(t_stack *a);
void	rb_ww(t_stack *b);
void	rr_ww(t_stack *a, t_stack *b);
// reverse_rotate.c
void	rra_ww(t_stack *a);
void	rrb_ww(t_stack *b);
void	rrr_ww(t_stack *a, t_stack *b);

#endif