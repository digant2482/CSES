#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
    // if (a.first < b.first)
    //     return true;
    // else if (a.first > b.first)
    //     return false;
    // else 
    // {
    //     if (a.second > b.second)
    //         return true;
    //     else
    //         return false;
    // }  
}

int main()
{
    int num_ranges;
    cin >> num_ranges;
    vector<pair<int,int>> elements(num_ranges);
    map<pair<int,int>, int> pos_elements;

    for (int i = 0; i < num_ranges;i++)
    {
        cin >> elements[i].first >> elements[i].second;
        pos_elements[{elements[i].first,elements[i].second}] = i;        
    }

    sort(elements.begin(), elements.end(), cmp);

    vector<int> contains(num_ranges,0);
    int lower_limit = 1e9 + 1;
    for (int i = num_ranges-1; i >= 0; i--)
    {
        if (elements[i].second >= lower_limit)
            contains[pos_elements[{elements[i].first, elements[i].second}]] = 1;
        else
            lower_limit = elements[i].second;
    }
    for (int& elements:contains)
        cout << elements << " ";

    cout << endl;

    vector<int> contained(num_ranges,0);
    int upper_limit = 0;
    for (int i = 0; i < num_ranges; i++)
    {
        if (elements[i].second <= upper_limit)
            contained[pos_elements[{elements[i].first, elements[i].second}]] = 1;
        else
            upper_limit = elements[i].second;
    }
    for (int& elements:contained)
        cout << elements << " ";
}