/*
 * Node.c
 *
 *  Created on: 1 февр. 2022 г.
 *      Author: Evgeny
 */

#include "Node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Node* get_last(Node* node)
{
	while(node->next)
	{
		node = node->next;
	}
	return node;
}


void push(Node *node, char* data, int size) {
	if( node->word == NULL )
	{
		node->word = (char*)malloc( (size + 1) * sizeof(char) );
		strncpy( node->word, data, size );
		node->word[size] = END_SYMBOL;
		node->size = size;
		return;
	}
	node = get_last( node );
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->word = (char*)malloc( (size + 1) * sizeof(char) );
    strncpy( tmp->word, data, size );
    tmp->word[size] = END_SYMBOL;
    tmp->size = size;
    tmp->next = NULL;
    node->next = tmp;
}


Node* create_list()
{
	Node *tmp = (Node*) malloc(sizeof(Node));
	tmp->next = NULL;
	tmp->size = 0;
	tmp->word = NULL;
	return tmp;
}


Node* copy_list(Node *list)
{
	Node* new_list = create_list();
	while( list )
	{
		push( new_list, list->word, list->size );
		list = list->next;
	}
	return new_list;
}


void terminate_list(Node* node)
{
	Node *tmp;
	while( node )
	{
		tmp = node;
		node = node->next;
		free( tmp->word );
		free( tmp );
	}
}


Node* exchange( Node* first, Node* last )
{
	if( first == last )
	{
		return first;
	}
	last->next = first->next;
	Node* tmp = first;
	while( tmp->next != last )
	{
		tmp = tmp->next;
	}
	tmp->next = first;
	first->next = NULL;
	return last;
}


void print_list( Node* list )
{
	while( list )
	{
		printf( "%s\n", list->word );
		list = list->next;
	}
}
