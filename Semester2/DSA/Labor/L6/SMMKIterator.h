#pragma once
#include "SortedMultiMap.h"

class SMMKIterator {

    friend class SortedMultiMap;
private:
    //DO NOT CHANGE THIS PART
    const SortedMultiMap& map;
    SMMKIterator(const SortedMultiMap& map);

    //TODO - Representation
    BSTNode *current_node;
    struct stack_node {
        BSTNode *node;
        stack_node *next;
    };
    stack_node *stack;

    void stack_push(BSTNode *node);

    BSTNode * stack_pop();

    BSTNode * stack_top();

public:
    void first();
    void next();
    bool valid() const;
    TKey getCurrent() const;

};

