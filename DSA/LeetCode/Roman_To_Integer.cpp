/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.



Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900
*/

#include <iostream>
// #include <vector>

using namespace std;

int romanToInt(string s)
{
    int ans = 0;
    int i = 0;
    while (i <= s.length())
    {
        switch (s[i])
        {
        case 'I':
            /* code */
            if (s[i + 1] == 'V')
            {
                ans = ans + 4;
                i = i + 1;
            }
            else if (s[i + 1] == 'X')
            {
                ans = ans + 9;
                i++;
            }
            else
                ans = ans + 1;
            break;

        case 'V':
            /* code */
            ans = ans + 5;
            break;

        case 'X':
            /* code */
            /* code */
            if (s[i + 1] == 'L')
            {
                ans = ans + 40;
                i = i + 1;
            }
            else if (s[i + 1] == 'C')
            {
                ans = ans + 90;
                i++;
            }
            else
                ans = ans + 10;
            break;

        case 'L':
            /* code */
            ans = ans + 50;
            break;

        case 'C':
            /* code */
            /* code */
            if (s[i + 1] == 'D')
            {
                ans = ans + 400;
                i = i + 1;
            }
            else if (s[i + 1] == 'M')
            {
                ans = ans + 900;
                i++;
            }
            else
                ans = ans + 1;
            break;

        case 'D':
            /* code */
            ans = ans + 500;
            break;

        case 'M':
            /* code */
            ans = ans + 1000;
            break;
        default:
            break;
        }
        i++;
    }

    return ans;
}

int main()
{
    string s = "III";

    int ans = romanToInt(s);

    cout << "Roman to Integer : " << ans;
}
