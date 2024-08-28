#include <stdio.h>
#include <stdlib.h>

typedef struct lLNode {
    int val;
    struct lLNode* next;
} Node;

Node* listInsert_first(Node *list, int value);
Node* listInsert_last(Node *node, int val);
Node* listInsert_at_position(Node *head, int val, int position);
Node* list_pop(Node **head);
Node* list_unshift(Node **head);
int list_search(Node *head, int search_val);
int delete_node(Node **head, int search_val);
void displayList(Node *node);
void destroy(Node **head);

int main(void){
    
    Node *head = malloc(sizeof(Node));
    head->val = 1;
    head->next = NULL;
    listInsert_last(head, 2);
    listInsert_last(head, 3);
    listInsert_last(head, 4);
    listInsert_at_position(head, 99, 1);
    //int search_position = list_search(head, 4);
    //printf("list item found at position: %i\n", search_position);
    //delete_node(&head, 99);
    //Node *poped = list_pop(&head);
    //Node *poped2 = list_pop(head);
    //Node *poped3 = list_pop(head);
    //Node *poped4 = list_pop(head);
    //Node *poped5 = list_pop(head);
    //printf("\n\npoped node is: %i \n\n", poped->val);
    //destroy(&head);
    displayList(head);
    if(head == NULL) printf("\n the head is null");
    return 0;
}

/**
 * @brief inserts the provided value at the start of the list replacing the head with the new node then newNode->next = head.
 * @paragraph the return value of this function should be assigned to the head of the list, considering that it replaces the head of the list with a new head, keeping the old head will results in a memory leak.
 * @param Node *list the head of the list.
 * @param int value the value to be inserted at the begginig of the list.
 * @return Node *newNode the new head of the list.
 */
Node* listInsert_first(Node *list, int value){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("error line 24\n");
        return NULL;
    }
    newNode->val = value;
    newNode->next = list;
    return newNode;
}

/**
 * @brief inserts the provided value at the end of the list.
 * @param Node *node the head node of the list.
 * @param int val the value to be inserted to the end of the list.
 * @return Node *newNode | NULL returns the added node address or NULL in case of failure.
 */
Node* listInsert_last(Node *node, int val){
    if(node->next == NULL){
        Node *newNode = malloc(sizeof(Node));
        if(newNode == NULL) {
            fprintf(stderr, "error while trying to allocate memory at line: 39\n");
            exit(42);
            return NULL;
        }else{
            newNode->next = NULL;
            newNode->val = val;
            node->next = newNode;
            return newNode;
        }
    }
    listInsert_last(node->next, val);
}

/**
 * @brief inserts a node at a specified position (int position).
 * @paragraph indexing starts from 1 not 0, thus int position param should never be less than or equal to 0, <= 0 index will throw a warning but will not teminate the program.
 * @param Node *head the head of the list.
 * @param int val the value to be inserted.
 * @param int position the position where to inserd the node.
 * @return Node *newNode | NULL
 */
Node* listInsert_at_position(Node *head, int val, int position){
    if(position <= 0){
        fprintf(stderr, "WARNINIG: indexing starts from 1 not 0 (at listInsert_at_position(...) function at line 80)\n");
        return NULL;
    }
    for(Node* curr = head; curr != NULL; curr = curr->next, position--){
        if(position == 1){
            Node* newNode = malloc(sizeof(Node));
            if(newNode == NULL) {
                fprintf(stderr, "ERROR: memory allocation failed at line (57)"); exit(57);
            }
            newNode->val = curr->val;
            newNode->next = curr->next;
            curr->val = val;
            curr->next = newNode;
            return curr;
        }
    }
    if(position > 0) {
        fprintf(stderr, "ERROR: the provided position is out of list range.\nat line 61"); exit(62);
    }
}

/**
 * @brief this function displays the values inside the nodes of the provided linkedList.
 * @param Node *node the head of the list.
 * @return void
 */
void displayList(Node *node){
    if(node == NULL) {
        printf("* end of the list *\n");
        return;
    };
    printf("node: %i \n", node->val);
    displayList(node->next);
}

/**
 * @brief pops the last node in the list (removes it and returns its) and returns it.
 * @param Node **head a pointer to the head of the list.
 * @return Node *poped | NULL
 */
Node* list_pop(Node **head){
    if(*head == NULL) return NULL;
    if((*head)->next == NULL){
        Node *poped = *head;
        *head = NULL;
        return poped;
    }
    for(Node *curr = *head; curr != NULL; curr = curr->next){
        if(curr->next->next == NULL){
            Node *poped = curr->next;
            curr->next = NULL;
            return poped;
        }
    }
    return NULL;
}

/**
 * @brief returns the first node of the list and reset the head to the next node.
 * @param Node **head a pointer of the head of the list.
 * @return Node *unshifted | NULL
 */
Node* list_unshift(Node **head){
    if(*head == NULL) return NULL;
    Node *unshifted = *head;
    *head = (*head)->next;
    return unshifted;
}

/**
 * @brief searches the linked list for a specific node value and return its position, in case the value doesn't exist it returns -1;
 * @param Node *head the head of the list.
 * @param int search_val the search value.
 * @return int position | -1
 */
int list_search(Node *head, int search_val){
    if(head == NULL) return -1;
    int i = 1;
    for(Node *curr = head; curr != NULL; curr = curr->next){
        if(curr->val == search_val){
            return i;
        }
        i++;
    }
    return -1;
}

int delete_node(Node **head, int search_val){
    if(*head == NULL) return -1;
    if((*head)->val == search_val){
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return 1;
    }
    for(Node *curr = *head; curr->next != NULL; curr = curr->next){
        if(curr->next->val == search_val){
            Node *tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
            return 1;
        }
    }
    return -1;
}

/**
 * @brief this function destroys the linkedlist by deleting all the nodes inside of it by calling free(on_each_node).
 * @param Node *head the head of the list.
 * @return NULL
 */
void destroy(Node **head){
    if(*head == NULL) {
        return;
    };
    destroy(&(*head)->next);
    printf("destroying node: %i\n", (*head)->val);
    free(*head);
    *head = NULL;
}
