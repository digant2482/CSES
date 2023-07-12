#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp (pair<int,int>& a, pair<int,int>& b)
    {return a.second < b.second;}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> movies(n);
    for (int i = 0; i<n; i++)
        cin >> movies[i].first >> movies[i].second;

    sort(movies.begin(), movies.end(), cmp);

    multiset<int> persons;
    persons.insert(movies[0].second);
    int movies_watched = 1;
    k -= 1;

    for (int i = 1; i < n; i++)
    {
        if (persons.upper_bound(movies[i].first) != persons.begin())
        {
            persons.erase(--persons.upper_bound(movies[i].first));
            persons.insert(movies[i].second);
            movies_watched ++;
        }
        else
        {
            if (k)
            {
                k--;
                persons.insert(movies[i].second);
                movies_watched++;
            }
        }
    }
    cout << movies_watched << endl;
}