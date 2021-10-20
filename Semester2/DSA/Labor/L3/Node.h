#pragma once

typedef int TElem;
#define NULL_TELEM 0

class Node {
public:
    int i, j;
    TElem value;
    int next{}, prev{};

    Node() = default;

    ~Node() = default;
};