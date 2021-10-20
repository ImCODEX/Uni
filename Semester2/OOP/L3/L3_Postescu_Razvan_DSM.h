#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;
#include <exception>
using std::exception;

class DSM {
public:
    DSM(int elementCount);                                             // Constructor with number of elements
    DSM(vector<string> &element_names);                                // Constructor with string
    DSM(const DSM &);                                                  // Copy Constructor
    ~DSM();                                                            // Destructor
    int size();                                                        // Returns size of matrix
    int find(string element);                                          // Returns the index of a string in a vector of strings, or -1 if not found
    void set_element_name(int index, string name);                     // Assigns string to specified index
    string get_name(int index);                                        // Returns string of specified index
    void add_link(string from_element, string to_element, int weight); // Sets value of element on position (from_element, to_element) = weight
    void delete_link(string from_element, string to_element);          // Sets value of element on position (from_element, to_element) = 0
    bool have_link(string from_element, string to_element);            // Returns true if value of element on position (from_element, to_element) > 0, false otherwise
    int link_weight(string from_element, string to_element);           // Returns value of element on posisition (from_element, to_element)
    int count_to_links(string element_name);                           // Counts links from element_name to others
    int count_from_links(string element_name);                         // Counts links from others to element_name
    int count_all_links();                                             // Counts all links
    double calculate_matrix_density();                                 // Returns ElementsOfMatrix/AllLinks
    void print();
    void prints();

private:
    int elemCount;
    vector<vector<int>> weight_matrix;
    vector<string> element_names;
};

class DSMException : public exception {
private:
    string msg;

public:
    DSMException(const string &msg);
    const string &get_msg() const;
};