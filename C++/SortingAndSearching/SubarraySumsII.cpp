#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

using namespace std;

int main()
{
    int size, target_sum;
    cin >> size >> target_sum;
    vector<ll> cum_sum_array(size);
    ll total = 0;
    int new_element;
    for (int i = 0; i < size; i++)
    {
        cin >> new_element;
        total += new_element;
        cum_sum_array[i] = total;
    }

    map<ll,int> cum_sum_frequency;
    cum_sum_frequency[0]++;
    ll counter = 0;
    for (const ll& element: cum_sum_array)
    {
        counter += cum_sum_frequency[element - target_sum];
        cum_sum_frequency[element]++;
    }
    cout << counter << endl;
}