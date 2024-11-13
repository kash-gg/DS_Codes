#include <stdio.h>
#include <stdlib.h>

// Structure of a Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Find the minimum value in a BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for a node in the BST
int searchNode(struct Node* root, int data) {
    if (root == NULL) return 0;

    if (data == root->data) return 1;
    else if (data < root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

// Find the maximum value in a BST
struct Node* findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Level Order Traversal using a Queue
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

// Count total nodes in a BST
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Main function to demonstrate the program
int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    printf("Minimum Value: %d\n", findMin(root)->data);
    printf("Maximum Value: %d\n", findMax(root)->data);

    printf("Total Nodes: %d\n", countNodes(root));

    // Search for a node
    int value = 40;
    if (searchNode(root, value))
        printf("Node %d found in the BST\n", value);
    else
        printf("Node %d not found in the BST\n", value);

    // Delete a node
    root = deleteNode(root, 20);
    printf("Inorder Traversal after deletion of 20: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Structure of a Node for the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 1. Check if a Tree is a BST
int isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL) return 1;
    if (node->data < min || node->data > max) return 0;
    return isBSTUtil(node->left, min, node->data - 1) && 
           isBSTUtil(node->right, node->data + 1, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, -2147483648, 2147483647);
}

// 2. Find Height of the BST
int findHeight(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// 3. Check if the BST is balanced
int isBalanced(struct Node* root) {
    if (root == NULL) return 1;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

// 4. Find the Lowest Common Ancestor (LCA)
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    return root;
}

// 5. Convert Sorted Array to BST
struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    struct Node* root = createNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// 6. Convert Sorted List to BST
struct ListNode {
    int data;
    struct ListNode* next;
};

struct Node* sortedListToBST(struct ListNode** head, int n) {
    if (n <= 0) return NULL;

    struct Node* left = sortedListToBST(head, n / 2);

    struct Node* root = createNode((*head)->data);
    root->left = left;

    *head = (*head)->next;

    root->right = sortedListToBST(head, n - n / 2 - 1);

    return root;
}

// 7. Find kth Smallest Element
int kthSmallestUtil(struct Node* root, int* k) {
    if (root == NULL) return -1;

    int left = kthSmallestUtil(root->left, k);
    if (left != -1) return left;

    (*k)--;
    if (*k == 0) return root->data;

    return kthSmallestUtil(root->right, k);
}

int findKthSmallest(struct Node* root, int k) {
    return kthSmallestUtil(root, &k);
}

// 8. Find kth Largest Element
int kthLargestUtil(struct Node* root, int* k) {
    if (root == NULL) return -1;

    int right = kthLargestUtil(root->right, k);
    if (right != -1) return right;

    (*k)--;
    if (*k == 0) return root->data;

    return kthLargestUtil(root->left, k);
}

int findKthLargest(struct Node* root, int k) {
    return kthLargestUtil(root, &k);
}

// 9. Print Nodes at k Distance from the root
void printNodesAtKDistance(struct Node* root, int k) {
    if (root == NULL) return;
    if (k == 0) {
        printf("%d ", root->data);
        return;
    }
    printNodesAtKDistance(root->left, k - 1);
    printNodesAtKDistance(root->right, k - 1);
}

// 10. Flatten BST to Sorted Linked List
void flattenBSTToLinkedList(struct Node* root, struct Node** prev) {
    if (root == NULL) return;

    flattenBSTToLinkedList(root->left, prev);

    root->left = NULL;
    (*prev)->right = root;
    *prev = root;

    flattenBSTToLinkedList(root->right, prev);
}

struct Node* flattenBST(struct Node* root) {
    struct Node* dummy = createNode(-1);
    struct Node* prev = dummy;
    flattenBSTToLinkedList(root, &prev);
    struct Node* flattenedList = dummy->right;
    free(dummy);
    return flattenedList;
}

// 11. Mirror of BST
struct Node* mirrorBST(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* left = mirrorBST(root->left);
    struct Node* right = mirrorBST(root->right);

    root->left = right;
    root->right = left;

    return root;
}

// 12. Merge Two BSTs into a single BST
void storeInorder(struct Node* root, int inorder[], int* index) {
    if (root == NULL) return;

    storeInorder(root->left, inorder, index);
    inorder[(*index)++] = root->data;
    storeInorder(root->right, inorder, index);
}

struct Node* mergeBSTs(struct Node* root1, struct Node* root2) {
    int arr1[100], arr2[100], merged[200];
    int i = 0, j = 0, k = 0;
    
    storeInorder(root1, arr1, &i);
    storeInorder(root2, arr2, &j);
    
    int idx1 = 0, idx2 = 0;
    while (idx1 < i && idx2 < j) {
        if (arr1[idx1] < arr2[idx2])
            merged[k++] = arr1[idx1++];
        else
            merged[k++] = arr2[idx2++];
    }
    while (idx1 < i) merged[k++] = arr1[idx1++];
    while (idx2 < j) merged[k++] = arr2[idx2++];
    
    return sortedArrayToBST(merged, 0, k - 1);
}

// 13. Find Successor and Predecessor
void findPredecessorSuccessor(struct Node* root, struct Node** predecessor, struct Node** successor, int key) {
    if (root == NULL) return;

    if (root->data == key) {
        if (root->left != NULL) {
            struct Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            *predecessor = temp;
        }

        if (root->right != NULL) {
            struct Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            *successor = temp;
        }
        return;
    }

    if (key < root->data) {
        *successor = root;
        findPredecessorSuccessor(root->left, predecessor, successor, key);
    } else {
        *predecessor = root;
        findPredecessorSuccessor(root->right, predecessor, successor, key);
    }
}

// Main function to demonstrate all functions
int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;

    // Construct first BST
    root1 = insertNode(root1, 50);
    insertNode(root1, 30);
    insertNode(root1, 70);
    insertNode(root1, 20);
    insertNode(root1, 40);
    insertNode(root1, 60);
    insertNode(root1, 80);

    // Construct second BST
    root2 = insertNode(root2, 25);
    insertNode(root2, 15);
    insertNode(root2, 35);
    insertNode(root2, 75);
    insertNode(root2, 85);

    printf("Inorder traversal of BST1: ");
    inorderTraversal(root1);
    printf("\n");

    printf("Is BST1 a valid BST? %s\n", isBST(root1) ? "Yes" : "No");
    printf("Height of BST1: %d\n", findHeight(root1));
    printf("Is BST1 balanced? %s\n", isBalanced(root1) ? "Yes" : "No");

    struct Node* LCA = findLCA(root1, 20, 60);
    if (LCA) printf("Lowest Common Ancestor of 20 and 60: %d\n", LCA->data);

    printf("Flattened BST1 to linked list: ");
    struct Node* flattenedList = flattenBST(root1);
    while (flattenedList != NULL) {
        printf("%d ", flattenedList->data);
        flattenedList = flattenedList->right;
    }
    printf("\n");

    struct Node* mirrorRoot = mirrorBST(root1);
    printf("Inorder traversal of mirrored BST1: ");
    inorderTraversal(mirrorRoot);
    printf("\n");

    struct Node* mergedBST = mergeBSTs(root1, root2);
    printf("Inorder traversal of merged BST: ");
    inorderTraversal(mergedBST);
    printf("\n");

    struct Node* predecessor = NULL;
    struct Node* successor = NULL;
    findPredecessorSuccessor(root1, &predecessor, &successor, 40);
    if (predecessor)
        printf("Predecessor of 40 is %d\n", predecessor->data);
    else
        printf("No predecessor for 40\n");

    if (successor)
        printf("Successor of 40 is %d\n", successor->data);
    else
        printf("No successor for 40\n");

    return 0;
}