#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr(26,0);
    string str;
    string ans;
    char odd_char = 0;
    cin >> str;
    int total_odd_char = 0;
    for (int i = 0; i<str.length();i++)
        arr[str[i]-'A'] += 1;

    for (int i = 0; i<26; i++)
    {
        if (total_odd_char>1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        
        if (arr[i] % 2 == 1)
        {
            total_odd_char += 1;
            odd_char = char(65+i);
        }

        if (arr[i])
            ans += string(arr[i]/2, char(65+i));
    }  
    string reversed_ans;
    reversed_ans = ans;
    reverse(reversed_ans.begin(), reversed_ans.end());
    if (odd_char)
        cout << ans + odd_char + reversed_ans << endl;     
    else
        cout << ans + reversed_ans << endl; 
}