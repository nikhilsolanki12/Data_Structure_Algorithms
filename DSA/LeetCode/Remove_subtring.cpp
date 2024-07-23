#include <iostream>
#include <string.h>

using namespace std;

string removeOccurance(string str, string path)
{
}

int main()
{
    string str = "abcabcxyz";
    string path = "abc";

    // cout << str.find(path);
    int i = str.find(path);
    while (str.find(path) != -1)
    // if(str.find(path))
    {
        int i = str.find(path);
        str.erase(i, path.length());
    }
    cout << str;
}