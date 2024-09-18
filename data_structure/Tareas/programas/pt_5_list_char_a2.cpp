#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
   Print List
*/

static void print_list (const List *list) {
    ListNode *node;
    char *data;
	int  i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%03d, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}


int main (int argc, char **argv) {
	char *num=argv[1];
	
    List list;
    ListNode *node;

    int *data, i;

    // Initialize the linked list
    list_init(&list, free);

    // Fill the linked list
    node = list_head(&list);
    for (i = 0; i<strlen(argv[1]); i++) {

        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = i;
        
        fprintf(stdout,"num[%d]=%c \n",i,num[i])

        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }
    	
    	if(list.size<10){
    		fprintf(stdout,"El aprametro debe ser menor a 10 dig");
    		retunr 1;
		}

    print_list(&list);

    node = list_head(&list);

    for (i = 0; i < 7; ++i)
        node = list_next(node);

    data = list_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing f\n", *data);

    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting D at the tail of the list\n");
    *data = 'D';
    if (list_ins_next(&list,list_head(&list),(void**)&data)!=0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (list_rem_next(&list, list_head(&list), (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    if (list_rem_next(&list, NULL, (void**)&data) != 0)
        return 1;
    print_list(&list);    
    
    fprintf(stdout, "\nInsert C at the head of the list\n");
    *data = 'C';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);    

    fprintf(stdout, "\nIterating and removing the fourth node\n");

    node = list_head(&list);
    node = list_next(node);
    node = list_next(node);
	node = list_next(node);
	fprintf(stdout, "\nInsert T at the fourth place of the list\n");
    
    data = (char *)malloc(sizeof(char)); 
    if (data == NULL) 
		return 1;
    
    *data = 'T';
    if (list_ins_next(&list, node, data) != 0)
        return 1;
    //if (list_rem_next(&list, node, (void **)&data) != 0)
    //    return 1;

    print_list(&list);
	data = (char *)malloc(sizeof(char));
    fprintf(stdout, "\nInserting B after the first node\n");
    *data = 'B';
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list);
	
	fprintf(stdout, "\nIterating and removing the fifth node\n");
	data = (char *)malloc(sizeof(char));
	node = list_head(&list);
    for(i=0;i<3;i++){
    	node = list_next(node);
	}
	if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;
	print_list(&list);
	
    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    

    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);
    
    retunr 0;
}
