#include <iostream>
#include <vector> //dynamic array

int main()
{
    std::vector<int> vec{4, 2, 3, 5, 1}; // vector of type int
    // initialised universally.

    for (auto i : vec)
        std::cout << i << ", ";
    std::cout << '\n';

    // the iterator is passed by reference to modify the elements
    for (auto &i : vec)
        i += 2;

    for (auto i : vec)
        std::cout << i << ", ";
}