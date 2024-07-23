#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string losingPlayer(int x, int y)
{

    string ans;
    int cnt = 0;

    while (x >= 1 && y >= 4)
    {
        cnt++;
        x = x - 1;
        y = y - 4;
    }
    if (cnt % 2 != 0)
    {
        return "Alice";
    }

    return "BoB";
}
int nearestLeft(string s, int index)
{
    vector<int> v;

    return -1;
}

int minimumLength(string s)
{
    // int arr[26];
    vector<int> arr(26);
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - 'a']++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
            if (arr[i] % 2)
            {
                cnt = cnt + 1;
            }
            else
            {
                cnt += 2;
            }
    }

    return cnt;
}
int main()
{

    int x = 2, y = 7;

    // string s = "abaachcbcbb";
    // // string s = "htukrysju";
    // // string s = "jsebaejj";

    // // string s = "aa";

    // // cout << losingPlayer(x, y);
    // cout << minimumLength(s);

    string s = "10110";

    vector<char> arr;
    for (char ch : s)
    {
        arr.push_back(ch);
    }

       return 0;
}