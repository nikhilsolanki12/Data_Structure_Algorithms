#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int modifyMEX(int n, std::vector<int> &arr)
{
    // Find the maximum element for efficient frequency array allocation.
    int max_element = *std::max_element(arr.begin(), arr.end());

    // Create a frequency array to store the count of each element (0 to max_element).
    std::vector<int> freq(max_element + 1, 0);

    // Count the frequency of each element in the original array.
    for (int num : arr)
    {
        freq[num]++;
    }

    // Check if the MEX is already present (unchangeable).
    if (freq[0] > 0)
    {
        return -1;
    }

    // Iterate through the frequency array to find the MEX.
    for (int i = 0; i <= max_element; i++)
    {
        if (freq[i] == 0)
        { // Missing element (potential MEX)
            // Check if any higher element has a frequency, indicating unchangeable MEX.
            for (int j = i + 1; j <= max_element; j++)
            {
                if (freq[j] > 0)
                {
                    return -1;
                }
            }
            // MEX can be changed by removing elements, return minimum removal (1).
            return 1;
        }
    }

    // No MEX found (all elements consecutive), return -1.
    return -1;
}

// No valid MEX found, return -1 (all elements present)

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = modifyMEX(n, arr);
    cout << "Minimum elements to remove: " << result << endl;

    return 0;
}
