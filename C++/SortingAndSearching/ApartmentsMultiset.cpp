#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    multiset<int> applicants;
    multiset<int> apartments;

    for (int i = 0; i<n; i++)
    {
        int num;
        cin >> num;
        applicants.insert(num);
    }
    for (int i = 0; i<m; i++)
    {
        int num;
        cin >> num;
        apartments.insert(num);
    }
        
    int counter = 0;
    auto applicants_itr = applicants.begin();
    auto apartments_itr = apartments.begin();

    while (applicants_itr != applicants.end() && (apartments_itr != apartments.end()))
    {
        int lower_bound = *applicants_itr - k;
        int upper_bound = *applicants_itr + k;
      
        if (*apartments_itr < lower_bound)
        {
            ++apartments_itr;
        }
        else if (*apartments_itr > upper_bound)
        {
            ++applicants_itr;
        }
        else
        {
            ++counter;
            ++apartments_itr;
            ++applicants_itr;
        }
    }
    cout << counter << endl;
}