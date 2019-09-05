#include <stdio.h>
#include <stdlib.h>

// Struct for storing nodes
struct node {
   int value;
   struct node *next;
};

// Initialize list
struct node *start = NULL;
int count = 0;

// Function for printing list
void print_list() 
{
   struct node *mynode;
   mynode = start;
   
   if (mynode == NULL) 
   {
      printf("Linked list is empty.\n");
      return;
   }
   
   printf("Linked list: ");
   while (mynode->next != NULL) 
   {
      printf("%d ", mynode->value);
      mynode = mynode->next;
   }
   printf("%d\n", mynode->value);
}

// Function for inserting nodes
void insert_node(int index, int x) 
{
    // Check if index is in range of array
    if (index > count)
    {
        printf("Error. Impossible to add element.\n");
        return;
    }
    
    struct node *new, *tmp, *prev;
    new = (struct node*)malloc(sizeof(struct node));
    count++;
    
    // Insert element to position 0
    if (index == 0)
    {
        if (start == NULL) {
            start = new;
            start->value = x;
            start->next = NULL;
            return;
        }
   
        new->value = x;
        new->next = start;
        start = new;
        
        return;
    }
    
    // Insert element to another position
    int pos = 1;
    prev = start;
    tmp = start->next;
    
    while (pos < index) 
    {
        prev = tmp;
        tmp = tmp->next;
        pos++;
    }
    
    prev->next = new;
    new->value = x;
    
    prev->next = new;
    new->value = x;
    new->next = tmp;
}

// Function for deleting nodes
void delete_node(int index) 
{
    // Check if index is in range of array
    if (index >= count)
    {
        printf("Error. Impossible to delete element.\n");
        return;
    }
    
    struct node *new, *prev, *tmp;
    
    // Delete first node
    if (index == 0)
    {
        new = start->next;
        free(start);
        start = new;
        return;
    }
    
    // Delete last node
    if (index == count - 1)
    {
        new = start;
   
        while (new->next != NULL) 
        {
            prev = new;
            new = new->next;
        }
        
        free(new);
        prev->next = NULL;
        return;
    }
    
    int pos = 1;
    prev = start;
    tmp = start->next;
    
    while (pos < index) 
    {
        prev = tmp;
        tmp = tmp->next;
        pos++;
    }
    
    prev->next = tmp->next;
    free(tmp);
    count--;
}

// Main function
int main () 
{
    int action, ind, val;
    
    printf("\nInput 0 to finish.\n");
    printf("Input 1 to printf linked list elements.\n");
    printf("Input 2 to add element.\n");
    printf("Input 3 to delete element.\n\n");
    
    
    while(1)
    {  
        printf("Action: ");
        scanf("%d", &action);
        
        if (action == 0) break;
        
        if (action == 1) 
        {
            print_list();
            printf("\n");
        }
        else if (action == 2)
        {
            printf("Input position to add element: ");
            scanf("%d", &ind);
            printf("Input value of element to add: ");
            scanf("%d", &val);
            insert_node(ind, val);
            printf("\n");
        }
        else if (action == 3)
        {
            printf("Input position of element to delete: ");
            scanf("%d", &ind);
            delete_node(ind);
            printf("\n");
        }
        else
        {
            printf("Wrong action. Try again!\n");
        }
    }
    
    return 0;
}