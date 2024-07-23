#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
{

    int max = 0, index = 0;
    for (int i = 0; i < dimensions.size(); i++)
    {
        int pow1 = sqrt((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]));
        if (pow1 >= max)
        {
            max = pow1;
            index = i;
        }
    }

    return dimensions[index][0] * dimensions[index][1];
    return 0;
}

int main()
{
    vector<vector<int>> dimension1{{1, 2}, {2, 3}, {4, 6}, {9, 2}, {7, 6}, {7, 4}, {9, 8}, {8, 2}, {9, 4}};
    vector<vector<int>> dimension2{{9, 100}, {1, 100}};
    // std::cout << "/* message */" << areaOfMaxDiagonal(dimension2);

    float max = 0, area;
    for (int i = 0; i < dimension2.size(); i++)
    {
        float pow1 = sqrt((dimension2[i][0] * dimension2[i][0] + dimension2[i][1] * dimension2[i][1]));
        if (pow1 >= max)
        {
            max = pow1;
            area = dimension2[i][0] * dimension2[i][1];
        }
        cout << area << endl;
    }

    // return dimension2[index][0] * dimension2[index][1];
    return 0;
}
