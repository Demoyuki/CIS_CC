// Victor Marrujo
// Chpt7 PA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 10

struct Node {
	int key;
    struct Node* left;
    struct Node* right;
};

struct BinarySearchTree {
	struct Node* root;
};

void initBST(struct BinarySearchTree* bst) {
    bst->root = NULL;
}

struct Node* getRoot(struct BinarySearchTree* bst) {
    return bst->root;
}

struct Node* search(struct BinarySearchTree* bst, int desiredKey) {
	printf("\nSearching for node %d", desiredKey);
    struct Node* currentNode = bst->root;
	printf("\nStarting at root node %d", currentNode->key);
    while (currentNode != NULL) {
        if (currentNode->key == desiredKey) {
            return currentNode;
        } else if (desiredKey < currentNode->key) {
			printf("\nDid not find node, navigating to node %d's left child", currentNode->key); 
            currentNode = currentNode->left;
        } else {
			printf("\nDid not find node, navigating to node %d's right child", currentNode->key); 
            currentNode = currentNode->right;
        }
    }
    return NULL;
}

void insert(struct BinarySearchTree* bst, struct Node* node) {
	printf("\nInserting node %d", node->key);
    if (bst->root == NULL) {
        bst->root = node;
		printf("\nInserted node %d as the root node.\n", node->key);
    } else {
        struct Node* currentNode = bst->root;
        while (currentNode != NULL) {
            if (node->key < currentNode->key) {
				printf("\nChecking node %d for left child." , currentNode->key);
                if (currentNode->left == NULL) {
					printf("\nInserting node %d as left child of node %d.\n", node->key, currentNode->key);
                    currentNode->left = node;
                    currentNode = NULL;
                } else {
                    currentNode = currentNode->left;
					printf("\nTraversed to left child node %d.", currentNode->key);
                }
            } else {
				printf("\nChecking node %d for right child." , currentNode->key);
                if (currentNode->right == NULL) {
					printf("\nInserting node %d as right child of node %d.\n", node->key, currentNode->key);
                    currentNode->right = node;
                    currentNode = NULL;
                } else {
                    currentNode = currentNode->right;
					printf("\nTraversed to right child node %d.", currentNode->key);
                }
            }
        }
    }
}

bool removeNode(struct BinarySearchTree* bst, int key) {
    struct Node* parent = NULL;
    struct Node* current = bst->root;

    while (current != NULL) {
        if (current->key == key) {
            if (current->left == NULL && current->right == NULL) { // Remove leaf
                if (parent == NULL) // Node is root
                    bst->root = NULL;
                else if (parent->left == current)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            } else if (current->right == NULL) { // Remove node with only left child
                if (parent == NULL) // Node is root
                    bst->root = current->left;
                else if (parent->left == current)
                    parent->left = current->left;
                else
                    parent->right = current->left;
            } else if (current->left == NULL) { // Remove node with only right child
                if (parent == NULL) // Node is root
                    bst->root = current->right;
                else if (parent->left == current)
                    parent->left = current->right;
                else
                    parent->right = current->right;
            } else { // Remove node with two children
                struct Node* successorParent = current;
                struct Node* successor = current->right;
                while (successor->left != NULL) {
                    successorParent = successor;
                    successor = successor->left;
                }
                current->key = successor->key; // Copy successor's key to current node
                if (successorParent == current)
                    successorParent->right = successor->right;
                else
                    successorParent->left = successor->right;
                free(successor); // Free the successor node
            }
            return true; // Node found and removed
        } else if (current->key < key) { // Search right
            parent = current;
            current = current->right;
        } else { // Search left
            parent = current;
            current = current->left;
        }
    }
    return false; // Node not found
}
	
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node* root, int space)
{
    // Base case
    if (root == NULL) {
        return;
	}
	
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++) {
		printf(" ");
	}
    printf("%d\n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct Node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// savesm time creating nodes
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}
int main() {

    // Initialize the Binary Search Tree
    struct BinarySearchTree bst;
    initBST(&bst);

    // Insert nodes in the specified order
    insert(&bst, createNode(20));
    insert(&bst, createNode(35));
    insert(&bst, createNode(13));
    insert(&bst, createNode(6));
    insert(&bst, createNode(24));
    insert(&bst, createNode(18));
    insert(&bst, createNode(48));
    insert(&bst, createNode(1));
    insert(&bst, createNode(27));

    // Print the BST in 2D
    printf("Current tree:\n");
    print2D(bst.root);

    // Remove nodes 18 and 48
    removeNode(&bst, 18);
    removeNode(&bst, 48);

    // Print the BST after removing nodes 18 and 48
    printf("\nTree after removing nodes 18 and 48:\n");
    print2D(bst.root);

    // Insert nodes 16 and 45
    insert(&bst, createNode(16));
    insert(&bst, createNode(45));

    // Print the BST after inserting nodes 16 and 45
    printf("\nTree after inserting nodes 16 and 45:\n");
    print2D(bst.root);

    // Remove nodes 6 and 24
    removeNode(&bst, 6);
    removeNode(&bst, 24);

    // Print the BST after removing nodes 6 and 24
    printf("\nTree  after removing nodes 6 and 24:\n");
    print2D(bst.root);

    // Remove node 20 and attempt to remove node 38 (not in tree)
    removeNode(&bst, 20);
    removeNode(&bst, 38); // This should not remove anything

    // Print the BST after removing node 20 and attempting to remove node 38
    printf("\nTree after removing node 20 and attempting to remove node 38:\n");
    print2D(bst.root);

    return 0;
}