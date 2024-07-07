#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SPACING 1

typedef struct Node {
    bool isLeaf;
    int degree;
    int *keys;
    struct Node **children;
    struct Node *next;
    int numKeys;
} Node;

typedef struct BPTree {
    Node *root;
    int degree;
} BPTree;

/* Function Headers */

/**
 * @brief Create a new Node
 * 
 * @param degree Degree of the B+ Tree
 * @param isLeaf Whether the Node is a Leaf Node or not
 * @return Node* Pointer to the newly created Node
 */
Node* createNode(int degree, bool isLeaf);

/**
 * @brief Create a new B+ Tree
 * 
 * @param degree Degree of the B+ Tree
 * @return BPTree* Pointer to the newly created B+ Tree
 */
BPTree* createBPTree(int degree);

/**
 * @brief Insert a key into the B+ Tree
 * 
 * @param tree Pointer to the B+ Tree
 * @param key Key to be inserted
 * @return void
 */
void insert(BPTree *tree, int key);

/**
 * @brief Insert a key into the Node
 * 
 * The function inserts a key into the Node.
 * If the Node is a leaf node, insert the key into the Node.
 * If the Node is an internal node, insert the key into the child node.
 * If the child node is full after insertion, split the child node.
 * If there is duplicate key, insert it to the leftest of the same key
 * 
 * @param node Pointer to the Node
 * @param key Key to be inserted
 * @return void
 */
void insertNode(Node *node, int key);

/**
 * @brief Split the child node of the Node
 * 
 * The new child node is always bigger or equal to the original child node.
 * 
 * @param node Pointer to the Node
 * @param i Index of the child node to be split
 * @return void
 */
void splitChild(Node *node, int i);

/**
 * @brief Print the B+ Tree
 * 
 * @param tree Pointer to the B+ Tree
 * @return void
 */
void printTree(BPTree *tree);

/**
 * @brief Print the Node
 * 
 * @param node Pointer to the Node
 * @param space Number of spaces to be printed
 * @return void
 */
void printNode(Node *node, int space);

/**
 * @brief Search for a key in the B+ Tree
 * 
 * This function also prints the path taken to find the key.
 * 
 * @param node Pointer to the Node
 * @param key Key to be searched
 * @return void
 */
void search(Node *node, int key);

/* Implementations */

/* Implementations */
Node *createNode(int degree, bool isLeaf) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->degree = degree;
    node->isLeaf = isLeaf;

    node->keys = (int*) malloc(sizeof(int) * degree);
    node->children = (Node**) malloc(sizeof(Node*) * degree);

    node->next = NULL;
    node->numKeys = 0;

    return node;
}

BPTree *createBPTree(int degree) {
    BPTree *tree = (BPTree*) malloc(sizeof(BPTree));
    tree->degree = degree;
    tree->root = createNode(degree, true);

    return tree;
}

void insert(BPTree *tree, int key) {
    Node *root = tree->root;
    insertNode(root, key);

    if (root->numKeys == tree->degree) {
        Node *newRoot = createNode(tree->degree, false);
        newRoot->children[0] = root;
        tree->root = newRoot;

        splitChild(newRoot, 0);
    }
}

void insertNode(Node *node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && key <= node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key <= node->keys[i]) {
            i--;
        }
        i++;
        insertNode(node->children[i], key);

        if (node->children[i]->numKeys == node->degree) {
            splitChild(node, i);
            if (key > node->keys[i]) i++;
        }
    }
}

void splitChild(Node *node, int i) {
    Node *child = node->children[i];
    Node *newChild = createNode(child->degree, child->isLeaf);

    if (child->isLeaf) {
        int start = child->degree / 2;

        newChild->numKeys = child->degree - start;
        child->numKeys = start;

        for (int j = 0; j < newChild->numKeys; j++) {
            newChild->keys[j] = child->keys[j + start];
        }

        newChild->next = child->next;
        child->next = newChild;

        for (int j = node->numKeys; j > i; j--) {
            node->children[j + 1] = node->children[j];
        }

        node->children[i + 1] = newChild;

        for (int j = node->numKeys - 1; j >= i; j--) {
            node->keys[j + 1] = node->keys[j];
        }

        node->keys[i] = child->keys[start];
        node->numKeys++;
    } else {
        int start = (child->degree + 1) / 2;

        newChild->numKeys = child->degree - start;
        child->numKeys = start - 1;

        for (int j = 0; j < newChild->numKeys; j++) {
            newChild->keys[j] = child->keys[j + start];
        }

        for (int j = 0; j < newChild->numKeys + 1; j++) {
            newChild->children[j] = child->children[j + start];
        }

        newChild->next = child->next;
        child->next = newChild;

        for (int j = node->numKeys; j > i; j--) {
            node->children[j + 1] = node->children[j];
        }
        node->children[i + 1] = newChild;

        for (int j = node->numKeys - 1; j >= i; j--) {
            node->keys[j + 1] = node->keys[j];
        }
        node->keys[i] = child->keys[start - 1];
        node->numKeys++;
    }
}

void search(Node *node, int key) {
    Node *current = node;
    while (!current->isLeaf) {
        int i = 0;

        while (i < current->numKeys && key >= current->keys[i]) {
            i++;
        }

        current = current->children[i];
        printf("%d\n", i + 1);
    }

    int i = 0;
    while (i < current->numKeys && key > current->keys[i]) {
        i++;
    }

    if (i < current->numKeys && key == current->keys[i]) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
}

void printTree(BPTree *tree) {
    printf("B+ Tree Akhir:\n");
    printNode(tree->root, 0);
}

void printNode(Node *node, int space) {
    if (node == NULL) {
        return;
    }

    space += SPACING;

    if (node->isLeaf) {
        for (int i = 0; i < node->numKeys; i++) {
            for (int j = SPACING; j < space; j++) {
                printf("-");
            }

            printf("%d\n", node->keys[i]);
        }
    } else {
        printNode(node->children[0], space);

        for (int i = 0; i < node->numKeys; i++) {
            for (int j = SPACING; j < space; j++) {
                printf("-");
            }

            printf("%d\n", node->keys[i]);
            printNode(node->children[i + 1], space);
        }
    }
}

int main() {
    // Main Program
    int degree;
    scanf("%d", &degree);

    if (degree < 3) {
        printf("Degree should be greater than or equal to 3.\n");
        return 0;
    }

    BPTree *tree = createBPTree(degree);

    int num_of_operations;
    scanf("%d", &num_of_operations);

    while (num_of_operations--) {
        int operation, key;
        scanf("%d %d", &operation, &key);

        if (operation == 1) {
            insert(tree, key);
        } else if (operation == 2) {
            search(tree->root, key);
        }
    }
    
    printTree(tree);
    return 0;
}