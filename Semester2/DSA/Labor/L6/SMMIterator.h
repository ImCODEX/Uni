#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

	//TODO - Representation
    BSTNode *current_node;
    int value_index;
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
   	TElem getCurrent() const;
};








