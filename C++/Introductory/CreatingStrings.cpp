#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    set<string> arr;
    cin >> str;
    sort(str.begin(), str.end());
    do {
        arr.insert(str);
    } while (next_permutation(str.begin(), str.end()));

    cout << arr.size() << endl;
    for (const string& str: arr)
        cout << str << endl;
}