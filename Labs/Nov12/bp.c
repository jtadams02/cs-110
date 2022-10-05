#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _letter {
        char info;
        struct _letter *next;
} Letter;

// Build a linked list to represent the specified word.
// Return the head of the linked list built.
Letter *buildList(char word[]);

// Print the linked list.
// For example, if the linked list represents CRIMSON,
// it prints C-->R-->I-->M-->S-->O-->N 
void printList(Letter *head);

int main() {
	char word[100];
	printf("Enter a word: ");
	scanf("%s", word);

	Letter *head = buildList(word);

	printList(head);

	return 0;
}


Letter *buildList(char word[]){
	int len = strlen(word);
	Letter *head = NULL;
	Letter *temp;

	for(int i=len-1;i>=0;i--)	
	{
		char ch = word[i];
		temp = (Letter*)malloc(sizeof(Letter));
		temp->info = ch;
		temp->next = head;
		head = temp;

	}
	return head;
}

void printList(Letter *head) {
    Letter *temp = head;
    while (temp != NULL) {
        printf("%c", temp->info);
        temp = temp->next;
        if (temp != NULL) {
            printf("-->");
        }
    }
    printf("\n");
}