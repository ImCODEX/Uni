#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;

class SMMIterator;
class SMMKIterator;

typedef bool(*Relation)(TKey, TKey);

struct BSTNode {
    TKey key;
    TValue *values;
    int size, capacity;
    BSTNode *left;
    BSTNode *right;
};

class SortedMultiMap {
    friend class SMMIterator;
    friend class SMMKIterator;

private:
    //TODO - Representation
    BSTNode *root;
    int current_size;
    Relation relation;

    void construct_da(BSTNode *node);

    void resize_da(BSTNode *node, double factor);

    void destroy_da(BSTNode *node);

    void add_da(BSTNode *node, TValue element);

    void remove_da(BSTNode *node, int index);

    int search_da(BSTNode *node, TValue element);

    BSTNode *init_node(TKey c, TValue v);

    BSTNode *insert_rec(BSTNode *node, TKey c, TValue v);

    BSTNode *minimum(BSTNode *node);

    BSTNode *remove_rec(BSTNode *node, TKey c, TValue v, bool &found);

    void destroy_rec(BSTNode* node);

public:

    // constructor
    SortedMultiMap(Relation r);

    //adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

    //returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

    //removes a key value pair from the sorted multimap
    //returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    SMMKIterator key_iterator() const;

    // destructor
    ~SortedMultiMap();
};
