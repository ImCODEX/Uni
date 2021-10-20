#include "L3_Postescu_Razvan_DSM.h"

#include <cassert>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

// CustomException for various errors
DSMException::DSMException(const string &msg) : exception(), msg{msg} {}

const string &DSMException::get_msg() const { return this->msg; }

DSM::DSM(int elemCount) {
    if(this->elemCount > 0){
        this->element_names = vector<string>(elemCount);
        this->elemCount = elemCount;
        this->weight_matrix =
            vector<vector<int>>(elemCount, vector<int>(elemCount, 0));
    }
    else 
        throw(DSMException("Matrix Size can't be less or equal than 0"));
}

DSM::DSM(vector<string> &element_names) {
    this->element_names = element_names;
    this->elemCount = this->element_names.size();
    this->weight_matrix =
        vector<vector<int>>(elemCount, vector<int>(elemCount, 0));
}

// Default destructor since stl::vector has it's own's
DSM::~DSM() = default;

DSM::DSM(const DSM &d) {
    this->element_names = d.element_names;
    this->elemCount = d.elemCount;
    this->weight_matrix = d.weight_matrix;
}

int DSM::size() { return this->elemCount; }

void DSM::set_element_name(int index, string name) {
    if (index < 0)
        throw(DSMException("Index can't be less than 0"));

    // Resize of this->element_names and this->weight_matrix in case index >=
    // this->elemCount
    if (index >= this->elemCount) {
        this->weight_matrix.resize(index + 1, vector<int>(index + 1, 0));
        for (auto &i : this->weight_matrix)
            i.resize(index + 1, 0);
        this->elemCount = index + 1;
        this->element_names.resize(index + 1);
    }

    this->element_names[index] = name;
}
int DSM::find(string name) {
    for (int i = 0; i < this->elemCount; i++)
        if (name == this->element_names[i])
            return i;
    return -1;
}
string DSM::get_name(int index) {
    if (index >= this->elemCount)
        throw(DSMException("Given index can't be greater than maximum index"));

    return this->element_names[index];
}

void DSM::add_link(string from_element, string to_element, int weight) {
    int f = find(from_element);
    int t = find(to_element);

    // if not found add at the end of the list
    if (f == -1)
        this->set_element_name(this->elemCount, from_element);
    if (t == -1)
        this->set_element_name(this->elemCount, to_element);

    this->weight_matrix[find(from_element)][find(to_element)] = weight;
}

void DSM::delete_link(string from_element, string to_element) {
    int f = find(from_element);
    int t = find(to_element);
    if (f != -1 && t != -1)
        this->weight_matrix[find(from_element)][find(to_element)] = 0;
    else
        throw(DSMException("One or two of the elements doesn't exist."));
}

bool DSM::have_link(string from_element, string to_element) {
    if (this->weight_matrix[find(from_element)][find(to_element)] > 0)
        return true;
    return false;
}

int DSM::link_weight(string from_element, string to_element) {
    return this->weight_matrix[find(from_element)][find(to_element)];
}

int DSM::count_to_links(string element_name) {
    int c = 0, f = find(element_name);
    for (int i = 0; i < this->elemCount; i++)
        if (this->weight_matrix[f][i] > 0)
            c++;

    return c;
}

int DSM::count_from_links(string element_name) {
    int c = 0, f = find(element_name);
    for (int i = 0; i < this->elemCount; i++)
        if (this->weight_matrix[i][f] > 0)
            c++;

    return c;
}

int DSM::count_all_links() {
    int c = 0;
    for (int i = 0; i < this->elemCount; i++)
        for (int j = 0; j < this->elemCount; j++)
            if (this->weight_matrix[i][j] > 0)
                c++;
    return c;
}

double DSM::calculate_matrix_density() {
    return (float)count_all_links() / (this->elemCount * this->elemCount);
}

void DSM::print() {
    for (vector<int> i : this->weight_matrix) {
        for (int j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void DSM::prints() {
    for (auto i : this->element_names)
        std::cout << i << " ";
    std::cout << std::endl;
}