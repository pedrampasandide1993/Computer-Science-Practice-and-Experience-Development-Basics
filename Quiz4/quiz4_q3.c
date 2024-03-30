// CODE: Library(s) you need

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// CODE: Write the function createNode()

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// CODE: You need a recursive function to deallocate memory of the binary tree

int main() {

    struct Node *root1 = createNode(2,NULL,NULL);
    root1->left = createNode(5,NULL,NULL);
    root1->right = createNode(6,NULL,NULL);
    root1->right->right = createNode(3,NULL,NULL);

    // Perform in-order traversal to display the binary tree
    printf("In-order traversal of the binary tree: ");
    inorderTraversal(root1);
    printf("\n");

    // Cleanup: Free memory
    // CODE: deallocateTree(root1);
    return 0;
}
