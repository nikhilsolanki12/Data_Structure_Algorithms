#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    int i = 0, j = s.length() - 1;

    while (i <= j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;

        }
        else
        {
            if(47>s[i]|| 58<s[i]<98)
             i++;
            if(47>s[j]|| 58<s[j]<98) 
             j--;
        }
    }
    if(i>j)
     return 
    
    return true;
}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    // string s = "Ror Ror";
    // s=tolower(s);
    cout << s << " is validPalindrome : " << isPalindrome(s);

    return 0;
}
