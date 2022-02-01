/*
 ============================================================================
 Name        : dima1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define EXIT_SUCCESS 0
#define MAX_STRING_SIZE 80

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"

void output_results( Node* ordered_list, Node* changed_list, int short_counter);
int count_short( Node* list, int short_number );
Node* create_word_list( char* string );



int main(void) {
	//read string
	char input_string[MAX_STRING_SIZE + 1];
	gets( input_string );

	//parse string
	Node* ordered_list = create_word_list( input_string );

	//change string
	Node* changed_list = copy_list(ordered_list);
	changed_list = exchange( changed_list, get_last( changed_list ) );

	//count less then 3 symbols words
	int short_counter = count_short( changed_list, 3 );

	output_results( ordered_list, changed_list, short_counter );

	terminate_list( ordered_list );
	terminate_list( changed_list );

	return EXIT_SUCCESS;
}

Node* create_word_list( char* string )
{

	Node* word_list = create_list();

	int j = 0;
	int i = 0;
	for( i = 0; string[i] != END_SYMBOL ; i++ )
	{
		if( string[i] == SPACE )
		{
			push( word_list, &string[j], i-j );
			j = i+1; // trim the space
		}
	}

	//last word:
	push( word_list, &string[j], i-j );
	return word_list;

}




int count_short( Node* list, int short_number )
{
	int counter = 0;
	while(list)
	{
		if( list->size < short_number )
		{
			counter++;
		}
		list = list->next;
	}
	return counter;
}


void output_results( Node* ordered_list, Node* changed_list, int short_counter)
{
	puts( "\nSource list:" );
	print_list( ordered_list );
	puts( "\nConverted list:" );
	print_list( changed_list );
	printf( "\nThe number of words whose length is less than 3: %d", short_counter );
}



