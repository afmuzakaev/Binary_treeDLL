#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTreeToDLL {
private:
    Node* prev;
    Node* head;

    void convertToDLL(Node* root) {
        if (!root)
            return;

        convertToDLL(root->left);

        if (!prev) {
            head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        convertToDLL(root->right);
    }

public:
    Node* binaryTreeToDLL(Node* root) {
        prev = nullptr;
        head = nullptr;
        convertToDLL(root);
        return head;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    BinaryTreeToDLL converter;
    Node* dllHead = converter.binaryTreeToDLL(root);

    // Printing the DLL
    Node* current = dllHead;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->right;
    }

    return 0;
}
