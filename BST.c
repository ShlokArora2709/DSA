#include <stdio.h>
#include <stdlib.h>

// Structure definition for a binary tree node
struct node {
    int data;
    struct node *left, *right;
};

// Function to search for a node with a given key in the BST
struct node* search_node(struct node* node, int data) {
    // Base Cases: node is NULL or the data is found at the current node
    if (node == NULL || node->data == data) {
        return node;
    } else if (data < node->data) {
        // Recursive call on the left subtree if the data is smaller
        return search_node(node->left, data);
    } else {
        // Recursive call on the right subtree if the data is larger
        return search_node(node->right, data);
    }
}

// Function to find the node with the minimum value in a BST
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node with a given key from the BST
struct node* delete_node(struct node* node, int data) {
    // Search for the node to be deleted
    struct node* delNode = search_node(node, data);

    // If node to be deleted is not found, return the original tree
    if (!delNode) {
        return node;
    }

    // Case 1: Node with only one child or no child
    if (delNode->left == NULL) {
        struct node* temp = delNode->right;
        free(delNode);
        return temp;
    } else if (delNode->right == NULL) {
        struct node* temp = delNode->left;
        free(delNode);
        return temp;
    }

    // Case 3: Node with two children
    struct node* temp = minValueNode(delNode->right);
    // Copy the data of the minimum value node (temp) to the node to be deleted (delNode)
    delNode->data = temp->data;

    // Recursively delete the minimum value node from the right subtree of delNode
    delNode->right = delete_node(delNode->right, temp->data);
    return node;
}

// Function to create a new node with the given data
struct node* NewNode(int data) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

// Function to insert a new node with the given data into the BST
struct node* Insert_node(struct node* node, int data) {
    // Base Case: If the tree is empty, create a new node
    if (node == NULL) {
        return NewNode(data);
    } else if (data < node->data) {
        // Recursive call on the left subtree if the data is smaller
        node->left = Insert_node(node->left, data);
    } else {
        // Recursive call on the right subtree if the data is larger
        node->right = Insert_node(node->right, data);
    }
    return node;
}

// Function to perform an in-order traversal of the BST
void inorder_traversal(struct node* root) {
    if (root != NULL) {
        // Recursive call on the left subtree
        inorder_traversal(root->left);

        // Print the current node's data
        printf("%d ", root->data);

        // Recursive call on the right subtree
        inorder_traversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, data;

    do {
        // Menu for user interaction
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insertion
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = Insert_node(root, data);
                break;

            case 2:
                // Deletion
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete_node(root, data);
                break;

            case 3:
                // In-order Traversal
                printf("In-order Traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}