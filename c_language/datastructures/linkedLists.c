#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* linkedListAdd(Node* list, int addedVal);
void displayLinkedList(Node* list);

int main(void)
{
    Node* myList = malloc(sizeof(Node));
    if(myList == NULL) return 11;
    myList->val = 1;
    myList = linkedListAdd(myList, 14);
    myList = linkedListAdd(myList, 15);
    myList = linkedListAdd(myList, 16);
    myList = linkedListAdd(myList, 17);
    displayLinkedList(myList);
}

Node* linkedListAdd(Node* list, int addedVal)
{
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) exit(17);
    newNode->val = addedVal;
    newNode->next = list;
    return newNode;
}

void displayLinkedList(Node* list)
{
    Node* currNode = list;
    while (currNode != NULL){
        printf("%i|", currNode->val);
        currNode = currNode->next;
    }
}



