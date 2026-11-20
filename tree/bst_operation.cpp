
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// 1. Insert a value into BST
Node* insert(Node* root, int value) {

    if (root == nullptr) {
        Node* temp = new Node;
        temp->data = value;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        cout << "Duplicate values are not allowed!\n";

    return root;
}

// 2. Search for a value
bool search(Node* root, int value) {

    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// Find minimum value node
Node* findMin(Node* root) {

    while (root != nullptr && root->left != nullptr)
        root = root->left;

    return root;
}

// 3. Delete a node
Node* deleteNode(Node* root, int value) {

    if (root == nullptr)
        return nullptr;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {

        // Case 1: No child (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: Only right child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// 4. Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 5. Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {

    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 6. Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {

    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 7. Free the allocated memory
void destroyTree(Node* root) {

    if (root == nullptr)
        return;

    destroyTree(root->left);
    destroyTree(root->right);

    delete root;
}

int main() {

    Node* root = nullptr;
    int choice, value;

    do {

        cout << "\n\n===== BINARY SEARCH TREE MENU =====\n";
        cout << "1. Insert a value\n";
        cout << "2. Search a value\n";
        cout << "3. Delete a value\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Display BST\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Insertion operation completed.\n";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;

                if (search(root, value))
                    cout << value << " found in BST.\n";
                else
                    cout << value << " not found in BST.\n";

                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;

                if (search(root, value)) {
                    root = deleteNode(root, value);
                    cout << "Value deleted successfully.\n";
                }
                else {
                    cout << "Value does not exist in BST.\n";
                }

                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                cout << "BST (Inorder): ";
                inorder(root);
                cout << endl;
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 8);

    destroyTree(root);

    return 0;
}
