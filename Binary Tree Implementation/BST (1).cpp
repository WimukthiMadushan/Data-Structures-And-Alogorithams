#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left;
  struct node *right;
};

node* createNewNode(int value){
    struct node* newNode = new node;
    newNode->key = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root == NULL)
        return;
    traverseInOrder(root->left);
    cout << root->key <<' ';
    traverseInOrder(root->right);
}

// Insert a root
struct node *insertNode(struct node* root, int key){
    node *newNode = createNewNode(key);
    if(root == NULL){
        root = newNode;
        return root;
    }
    auto current = root;
    while(true){
        if(current->key > key){
            if(current->left == NULL){
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else{
            if(current->right == NULL){
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
    return root;
}

node *findMin(node *pNode);

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        if (root->left == NULL){
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            delete root;
            return temp;
        }
        struct node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


node *findMin(node *Node) {
    if (Node->left == NULL && Node->right == NULL)
        return Node;
    return findMin(Node->left);
}

// Driver code
int main() {
  struct node* root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;

      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;

      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  traverseInOrder(root);
}