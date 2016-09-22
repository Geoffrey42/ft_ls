/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:04:44 by ggane             #+#    #+#             */
/*   Updated: 2016/09/22 18:42:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list	*merge_lists(t_list *a, t_list *b)
{
	t_list	*merged_list;

	merged_list = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (choose_compare_list_function(a, b) <= 0)
	{
		merged_list = a;
		merged_list->next = merge_lists(a->next, b);
	}
	else
	{
		merged_list = b;
		merged_list->next = merge_lists(a, b->next);
	}
	return (merged_list);
}

void	partition(t_list *head, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

void	merge_sort(t_list **source)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *source;
	a = NULL;
	b = NULL;
	if (head == NULL || head->next == NULL)
		return ;
	partition(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*source = merge_lists(a, b);
}
