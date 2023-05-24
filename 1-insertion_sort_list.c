#include "sort.h"


/**
* _swap - Function that swaps a node with its previous node in the list
* @node: Double pointer to the node
* @list: Double pointer to the head of the list
*
* Return: void
*/
void _swap(listint_t **node, listint_t **list)
{
	listint_t *prev_node = NULL, *next_node = NULL;

	prev_node = (*node)->prev;
	next_node = (*node)->next;

	if (next_node)
	{
		next_node->prev = prev_node;
	}
	if (prev_node)
	{
		prev_node->next = next_node;
	}

	prev_node->prev ? (prev_node->prev->next = *node) : (*list = *node);

	(*node)->next = prev_node;
	(*node)->prev = prev_node->prev;
	prev_node->prev = *node;
	prev_node->next = next_node;

	print_list((const listint_t *)*list);

}

/**
* insertion_sort_list - Sorts a doubly link list of integers in ascending order
* @list: double pointer to the head of the list
*
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *second, *node;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	second = (*list)->next;
	while (second)
	{
		node = second, second = second->next;
		while (node->prev && node->prev->n > node->n)
		{
			_swap(&node, list);
		}
	}
}
