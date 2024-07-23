#include <set>
#include <iostream>

int main()
{
    // Create two sets
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {3, 4, 5, 6, 7};

    // Find the intersection of the two sets
    std::set<int> intersection;

    // Print the intersection
    for (int i : intersection)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}