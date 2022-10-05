#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
   char *name;
   struct _node *next;
} Node;

Node *addBack(Node *head, char *name) {
   Node *node = malloc(sizeof(Node));
   node->name = malloc( sizeof(char) * (strlen(name)+1) );
   strcpy(node->name, name);
   node->next = NULL;
   
   if (head == NULL)
      return node;
   
   Node *cur = head;
   while (cur->next != NULL)
      cur = cur->next;
   cur->next = node;
   
   return head;
}

void printList(Node *head);

int main() {
   Node *head = NULL;
   
   char buff[100];
   printf("Enter strings to add to the list, \"STOP\" to end:\n");
   while (1) {
      scanf("%s", buff);
      
      if (strcmp(buff, "STOP") == 0) break;
      
      head = addBack(head, buff);
   }
   
   printf("Sublist:\n");
   printList(head);
   
   return 0;
}

// DO NOT MODIFY ANYTHING ABOVE THIS LINE

// Remember: ints do not auto-initialize to 0
void printList(Node *head) {
   int charTotal = 0;
   int counter = 0;
   for(Node *i = head;i!=NULL;i=i->next)
   {
      counter++;
      charTotal+=strlen(i->name);
   }
   int average = charTotal/counter;
   printf("The average length of these names is: %d\n",average);
   for(Node *n = head;n!=NULL;n=n->next)
   {
      if(strlen(n->name)>average)
      {
         printf("%s ",n->name);
      }
   }
   printf("\n");
}
