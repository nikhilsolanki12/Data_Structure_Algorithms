#include <iostream>
#include <string>

using namespace std;

string reverseVowels(string s)
{
    int j = s.length();
    int i = 0;
    for (i; i < j; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            for (j; j > i; j--)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
                {
                    char s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                    cout << i << ":" << j << endl;
                    // i++;
                    j--;
                    break;
                }
            }
    }
    return s;
}
int main()
{
    string s = "JasddsdseIOUE";

    cout << reverseVowels(s);
    return 0;
}