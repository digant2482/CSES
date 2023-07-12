#include <iostream>
#include <set>
#define ll long long

using namespace std;

int main()
{
    ll n;
    set<int> group1, group2;
    cin >> n;
    ll sum = (n*(n+1)/2);
    ll target = sum/2;
    if (sum%2 == 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        
        for (ll i = n; i>0; i--)
        {
            if(i <= target)
            {
                target -= i;
                group2.insert(i);
            }
            else
                group1.insert(i);
        }
    cout << group1.size() << endl;
    for (const auto& element : group1) 
        cout << element << " ";
    cout << endl;

    cout << group2.size() << endl;
    for (const auto& element : group2) 
        cout << element << " ";
    cout << endl;
    }
}