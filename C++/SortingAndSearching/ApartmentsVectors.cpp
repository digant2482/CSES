#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i<n; i++)
        cin >> applicants[i];
    for (int i = 0; i<m; i++)
        cin >> apartments[i];
        
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int counter = 0;
    int i = 0;
    int j = 0;

    while (i<n && j<m)
    {
        int lower_bound = applicants[i] - k;
        int upper_bound = applicants[i] + k;

        int curr_apartment = apartments[j];
        if (upper_bound < curr_apartment)
            i++;
        else if (curr_apartment < lower_bound)
            j++;
        else
        {
            counter += 1;
            i++;
            j++;
        } 
    }
    cout << counter << endl;
}