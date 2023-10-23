#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;

};
void push(struct node** head, int ndata){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode) {
        printf("Memory error");
        return ;
        }
    newnode->data = ndata;
    newnode->next = (*head);
    (*head) = newnode;
    
}
void insertAfter(struct node* prev, int data){
    
    if(prev == NULL) {
        printf("The given previous node must be non-NULL\n");
        return;
}
    else{
        struct node* new_node = (struct node *) malloc(sizeof(struct node));
        new_node->data=data;
        new_node->next = prev->next;
        prev->next= new_node;
    }
}
struct node* searchNode(struct node* head, int targetData) {
    struct node* current = head;

    while (current != NULL) {
        if (current->data == targetData) {
            return current; // Found a node with the target data
        }
        current = current->next;
    }

    return NULL; // Data not found in the list
}
int search(struct node* head,int key){
    struct node* temp=head;
    while(temp!= NULL){
        if(key==temp->data){
            return 1;

        }
        temp=temp->next;
    }
    return 0;
}
void reverse(struct node** head) {
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return;  
    }

    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev; 
}
void delfront(struct node** head){
    struct node *temp;
    temp=*head ;
    *head=(*head)->next;
    free(temp);
}
void delend(struct node** head){
    if(*head==NULL){
        return;}
    struct node *end=*head;
    struct node *prev=NULL;
    while(end->next){
        prev=end;
        end=end->next;
    }
    prev->next=NULL;
    free(end);
}
void delMid(struct node* head){
    if (head == NULL || head->next == NULL) {
        return;
    }
    struct node *temp1=head;
    struct node *temp2=head;
    struct node *prev=NULL;
    while(temp2->next!=NULL && temp2!=NULL){
        prev=temp1;
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
    prev->next=temp1->next;
    free(temp1);
}
void deleteN(struct node** head, int pos) {
    if (*head == NULL || pos < 1) {
        return;
    }

    if (pos == 1) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node* current = *head;
    struct node* prev = NULL;
    int i = 1;

    while (current != NULL && i < pos) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        return;
    }

    prev->next = current->next;
    free(current);
}
void displayList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }
}
void insertend(struct node** head, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode) {
        printf("Memory error");
        return ;
        }
    struct node* temp=(*head);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->data=data;
    temp->next=newnode;
    newnode->next=NULL;

}

int main() {
    struct node* head = NULL;
    int choice, data, key, pos;
    int afterData;
    struct node* afterNode;
    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Add a node at the beginning\n");
        printf("2. Insert a node after a given node\n");
        printf("3. Search for a key\n");
        printf("4. Reverse the list\n");
        printf("5. Delete the first node\n");
        printf("6. Delete the last node\n");
        printf("7. Delete a node at a given position\n");
        printf("8. Display the list\n");
        printf("9. Insert node at the end\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at the beginning: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:

                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data of the node to insert after: ");
                scanf("%d", &afterData);

                afterNode = searchNode(head, afterData);
                if (afterNode == NULL) {
                    printf("Node not found. Data not inserted.\n");
                } else {
                    insertAfter(afterNode, data);
                }
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(head, key)==1) {
                    printf("Key found in the list.\n");
                } else {
                    printf("Key not found in the list.\n");
                }
                break;
            case 4:
                reverse(&head);
                printf("List reversed.\n");
                break;
            case 5:
                delfront(&head);
                printf("First node deleted.\n");
                break;
            case 6:
                delend(&head);
                printf("Last node deleted.\n");
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteN(&head, pos);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Enter data to add at the end: ");
                scanf("%d", &data);
                insertend(&head,data);
                printf("entered successfully");
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}