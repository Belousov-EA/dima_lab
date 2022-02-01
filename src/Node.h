/*
 * Node.h
 *
 *  Created on: 1 февр. 2022 г.
 *      Author: Evgeny
 */

#ifndef NODE_H_
#define NODE_H_

#define END_SYMBOL '\0'
#define SPACE ' '

typedef struct Node
{
	char* word;
	int size;
	struct Node *next;
} Node;

Node* get_last(Node* node);
void push(Node *node, char* data, int size);
Node* create_list();
Node* copy_list(Node *list);
void terminate_list(Node* node);
Node* exchange( Node* first, Node* last );
void print_list( Node* list );

#endif /* NODE_H_ */
