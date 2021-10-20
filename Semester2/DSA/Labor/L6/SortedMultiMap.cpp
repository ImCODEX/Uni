#include "SMMIterator.h"
#include "SMMKIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) : root{nullptr}, current_size(0), relation(r) {}

//Method for adding an element in the SortedMultiMap's BST
//O(h)
void SortedMultiMap::add(TKey c, TValue v) {
    root = insert_rec(root, c, v);
    current_size++;
}

//Method for searching for a key in the SortedMultiMap's BST
//Returns the values associated to it.
//O(h)
vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue> values;
    BSTNode *current_node = root;
    bool found = false;
    while (current_node != nullptr && !found) {
        if (current_node->key == c) {
            for (int i = 0; i < current_node->size; i++) { //create vector
                values.push_back(current_node->values[i]);
            }
            found = true;
        } else if (this->relation(current_node->key, c)) { //binary search
            current_node = current_node->right;
        } else {
            current_node = current_node->left;
        }
    }
    return values;
}

//Method for removing a value from a node from the SortedMultiMap's BST
//Returns true if the pair was removed (it was part of the multimap),
//false if nothing is removed
//O(h)
bool SortedMultiMap::remove(TKey c, TValue v) {
    if (root != nullptr && root->key == c && root->size == 1 && root->values[0] == v) {
        //case of removing root node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            current_size--;
            return true;
        }
        if (root->left == nullptr) {
            BSTNode *old_root = root;
            root = root->right;
            old_root->right = nullptr;
            current_size--;
            return true;
        }
        if (root->right == nullptr) {
            BSTNode *old_root = root;
            root = root->left;
            old_root->left = nullptr;
            current_size--;
            return true;
        }

    }
    bool found = false;
    remove_rec(root, c, v, found);
    if (found) {
        current_size--;
    }
    return found;
}

//Method for returning size
//Theta(1)
int SortedMultiMap::size() const {
    return current_size;
}

//Method for returning boolean of current_size == 0
//Theta(1)
bool SortedMultiMap::isEmpty() const {
    return current_size == 0;
}

//Theta(1)
SMMIterator SortedMultiMap::iterator() const {
    return SMMIterator(*this);
}

SMMKIterator SortedMultiMap::key_iterator() const {
    return SMMKIterator(*this);
}

//Destructor
//Theta(destroy_rec());
SortedMultiMap::~SortedMultiMap() {
    destroy_rec(root);
}

//Method for initialising a new default node
//Theta(1)
void SortedMultiMap::construct_da(BSTNode *node) {
    node->size = 0;
    node->capacity = 10;
    node->values = new TValue[10];
}

//Method for resizing the dynamic array
//Theta(n)
void SortedMultiMap::resize_da(BSTNode *node, double factor) {
    node->capacity *= (int) factor;
    TValue *new_values = new TValue[node->capacity];
    for (int i = 0; i < node->size; i++)
        new_values[i] = node->values[i];
    delete[] node->values;
    node->values = new_values;
}

//Destructor for the dynamic array
//Theta(1)
void SortedMultiMap::destroy_da(BSTNode *node) {
    delete[] node->values;
}

//Method for adding an element to the dynamic array of an node
//Theta(1) or Theta(n) if size is at capacity
void SortedMultiMap::add_da(BSTNode *node, TValue element) {
    if (node->size == node->capacity)
        resize_da(node, 2);
    node->values[node->size] = element;
    node->size++;
}

//Method for removing an element from the dynamic array of an node
//Theta(n)
void SortedMultiMap::remove_da(BSTNode *node, int index) {
    if (node->size == node->capacity/4)
        resize_da(node, 0.5);
    if (index > -1 && index < node->size) {
        node->size--;
        for (int j = index; j < node->size; j++) {
            node->values[j] = node->values[j + 1];
        }
    }
}
//Method for searching an element in the dynamic array of a node
//Returns the index or -1 if not found
//Theta(n)
int SortedMultiMap::search_da(BSTNode *node, TValue element) {
    for (int i = 0; i < node->size; i++) {
        if (node->values[i] == element) {
            return i;
        }
    }
    return -1;
}

// Method for initializing an BSTNode
// Theta(1)
BSTNode *SortedMultiMap::init_node(TKey c, TValue v) {
    BSTNode *node = new BSTNode();
    construct_da(node); //construct the array of the node
    node->key = c;
    add_da(node, v); //add value to the array
    node->left = nullptr;
    node->right = nullptr; //the new node will first be a leaf
    return node;
}

// Method for recursively inserting a node in the tree.
// O(h)
BSTNode *SortedMultiMap::insert_rec(BSTNode *node, TKey c, TValue v) {
    if (node == nullptr) {
        node = init_node(c, v); //if node doesn't exist initialise node
    } else if (node->key == c) { //if we are at node add value to array
        add_da(node, v);
    } else if (relation(node->key, c)) { //continue to search for node
        node->right = insert_rec(node->right, c, v);
    } else {
        node->left = insert_rec(node->left, c, v);
    }
    return node;
}

// Method for finding the minimum node of a subtree.
// O(h)
BSTNode *SortedMultiMap::minimum(BSTNode *node) {
    if (node == nullptr) { //stop condition for recursive operation
        return nullptr;
    } else {
        while (node->left != nullptr) { //the minimum will always be in
                                        //the farthest left node
            node = node->left;
        }
        return node;
    }
}

//Method for recursively removing a node from the tree.
//O(h)
BSTNode *SortedMultiMap::remove_rec(BSTNode *node, TKey c, TValue v, bool &found) {
    if (node == nullptr) { //stop condition
        return nullptr;
    } else if (node->key == c) { //if node is found
        if (node->size != 0) { //remove value if size not 0
            int value_index = search_da(node, v);
            if (value_index != -1) {
                remove_da(node, value_index);
                found = true;
            }
        }
        if (node->size == 0) { //if size is 0
            found = true; //we need to find
            BSTNode *min = minimum(node->right); //the node with the minimum key but bigger than our current one
            node->key = min->key; //and copy all the attributes over
            node->values = min->values;
            node->size = min->size;
            node->capacity = min->capacity;
            resize_da(node, 1);
            node->right = remove_rec(node->right, min->key, v, found); //we remove min node from the bst
            destroy_da(min); //we destroy min node's array
            return node;
        }
    } else if (relation(node->key, c)) { //search for node
        node->right = remove_rec(node->right, c, v, found);
        return node;
    } else {
        node->left = remove_rec(node->left, c, v, found);
        return node;
    }
    return node;
}

// Method for recursively destroying a tree.
// O(h)
void SortedMultiMap::destroy_rec(BSTNode *node) {
    if (node != nullptr) {
        this->destroy_rec(node->left);
        this->destroy_rec(node->right); //goes to the leaf
        destroy_da(node); //performs delete there of the array of the node
        delete node; //performs delete of the node
    }
}