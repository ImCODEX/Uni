#include "SMMIterator.h"
#include "SortedMultiMap.h"

//Constructor
//O(n)
SMMIterator::SMMIterator(const SortedMultiMap &d) : map(d), stack{nullptr} {
    BSTNode *node = d.root;
    while (node != nullptr) {
        stack_push(node);
        node = node->left;
    }
    if (stack != nullptr) {
        current_node = stack_top();
    } else {
        current_node = nullptr;
    }
    value_index = 0;
}

//Method for resetting the iterator to the first element of the SMMIterator.
//Theta(n)
void SMMIterator::first() {
    while (stack != nullptr) {
        stack_pop();
    }
    BSTNode *node = map.root;
    while (node != nullptr) {
        stack_push(node);
        node = node->left;
    }
    if (stack != nullptr) {
        current_node = stack_top();
    } else {
        current_node = nullptr;
    }
    value_index = 0;
}

//Method for advancing the iterator to the next element of the SMMIterator
//O(n)
void SMMIterator::next() {
    if (!valid()) {
        throw std::exception();
    }

    if (value_index < current_node->size -1) { //go trough elements of the array
        value_index++;
    }
    else {
        BSTNode* node = stack_top();
        stack_pop();
        if (node->right != nullptr) { //find the minimum element bigger as the current one
            node = node->right;
            while (node != nullptr) {
                stack_push(node);
                node = node->left;
            }
        }
        if (stack != nullptr) { //set current node
            current_node = stack_top();
        }
        else {
            current_node = nullptr;
        }
        value_index = 0;
    }
}

//Method for checking if the iterator is valid.
//Theta(1)
bool SMMIterator::valid() const {
    return !map.isEmpty() && current_node != nullptr;
}

//Method for retrieving the current element
//Theta(1)
TElem SMMIterator::getCurrent() const {
    if (!this->valid()) {
        throw std::exception();
    }
    return TElem(current_node->key, current_node->values[value_index]);
}

//Method for pushing elements on the stack
//Theta(1)
void SMMIterator::stack_push(BSTNode *node) {
    if (stack == nullptr) {
        stack = new stack_node;
        stack->node = node;
        stack->next = nullptr;
        return;
    }
    auto *new_stack_node = new stack_node;
    new_stack_node->node = node;
    new_stack_node->next = stack;
    stack = new_stack_node;
}

//Method for popping elements from the stack
//Theta(1)
BSTNode *SMMIterator::stack_pop() {
    if (stack == nullptr)
        return nullptr;
    BSTNode *return_node = stack->node;
    auto *temp_stack_node = stack;
    stack = stack->next;
    temp_stack_node->next = nullptr;
    delete temp_stack_node;
    return return_node;
}

//Method for returning the top of the stakc
//Theta(1)
BSTNode *SMMIterator::stack_top() {
    return stack->node;
}
