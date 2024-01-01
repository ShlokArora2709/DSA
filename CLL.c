#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

};
struct node* push(struct node* last, int ndata){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode) {
        printf("Memory error");
        return last;
        }
    newnode->data = ndata;
    newnode->next = newnode;
    return newnode;
}
int search(struct node* head,int key){
    struct node* temp=head;
    while(temp->next!=head){
        if(key==temp->data){
            return 1;

        }
        temp=temp->next;
    }
    return 0;
}
struct node* searchNode(struct node* head, int targetData) {
    struct node* current = head;

    while (current->next!=head) {
        if (current->data == targetData) {
            return current; // Found a node with the target data
        }
        current = current->next;
    }

    return NULL; // Data not found in the list
}
void displayCLL(struct node* last) {
    if (last == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    struct node* current = last->next;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != last->next);

    printf(" end\n");
}

int main(){
    struct node* last = NULL;
    int data,c,k;
    while(1){
        printf("1.insert new node\n");
        printf("2.display\n");
        printf("3.insert at end\n");
        printf("10.exit\n");
        printf("enter choice");
        scanf("%d",&c);
        switch (c){
            case 1:
                printf("Enter data for the first element: ");
                scanf("%d", &data);
                if(!last){
                    last=push(&last,data);
                }
                else{
                    struct node* temp=push(&last,data);
                    temp->next=last->next;
                    last->next=temp;
                }
                break;
            case 2:
                displayCLL(last);
                break;
            case 3:
                printf("Enter data for the last element: ");
                scanf("%d", &data);
                struct node* temp=push(&last,data);
                temp->next=last->next;
                last->next=temp;
                temp=last;
                break;
            case 4:
                printf("Enter key to search: ");
                scanf("%d", &k);
                if (search(&last, k)==1) {
                    printf("Key found in the list.\n");
                } else {
                    printf("Key not found in the list.\n");
                }
                break;
            case 10:
                exit(0);
        }
    }
}