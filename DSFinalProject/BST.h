#ifndef BST_H
#define BST_H

template <typename T>
//binary search tree template class
class BST {
public:
    BST();//constructor
    ~BST();//destructor

    //inserting and removing data from bst and also in-order traversal
    void insert(const T& data);
    void remove(const T& data);
    bool search(const T& data) const;
    void inOrderTraversal(void (*visit)(const T& data)) const;

private:
    //node structure for each element in the bst.
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
    };
    //root node of tree
    Node* root;
    void insert(Node*& node, const T& data);
    void remove(Node*& node, const T& data);
    bool search(Node* node, const T& data) const;
    void inOrderTraversal(Node* node, void (*visit)(const T& data)) const;
    void clear(Node* node);
};

//implementation methods for bst

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    clear(root);
}

template <typename T>
void BST<T>::insert(const T& data) {
    insert(root, data);
}

template <typename T>
void BST<T>::remove(const T& data) {
    remove(root, data);
}

template <typename T>
bool BST<T>::search(const T& data) const {
    return search(root, data);
}

template <typename T>
void BST<T>::inOrderTraversal(void (*visit)(const T& data)) const {
    inOrderTraversal(root, visit);
}
//recursive insert helper function
template <typename T>
void BST<T>::insert(Node*& node, const T& data) {
    if (node == nullptr) {
        node = new Node(data);
    }
    else if (data < node->data) {
        insert(node->left, data);
    }
    else if (data > node->data) {
        insert(node->right, data);
    }
}
//remove heler function
template <typename T>
void BST<T>::remove(Node*& node, const T& data) {
    if (node == nullptr) return;

    if (data < node->data) {
        remove(node->left, data);
    }
    else if (data > node->data) {
        remove(node->right, data);
    }
    else {
        // Node to be deleted found
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

template <typename T>
bool BST<T>::search(Node* node, const T& data) const {
    if (node == nullptr) {
        return false;
    }
    else if (data == node->data) {
        return true;
    }
    else if (data < node->data) {
        return search(node->left, data);
    }
    else {
        return search(node->right, data);
    }
}

template <typename T>
void BST<T>::inOrderTraversal(Node* node, void (*visit)(const T& data)) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, visit);
        visit(node->data);
        inOrderTraversal(node->right, visit);
    }
}

template <typename T>
void BST<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

#endif // BST_H
