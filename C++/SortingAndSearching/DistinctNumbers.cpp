#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> myset;
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        myset.insert(k);
    } 
    cout << myset.size() << endl;
}   