#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main()
{
    int n, target_sum;
    cin >> n >> target_sum;
    vector<int> array(n);

    for (int i = 0; i<n; i++)
        cin >> array[i];
    
    int i = 0; int j = 1;
    ll curr_sum = array[i];
    int counter = 0;
    while (i < n && j < n)
    {
        if (curr_sum >= target_sum)
        {
            if (curr_sum == target_sum)
                counter++;
            curr_sum -= array[i];
            i++;
        } 
        else 
        {
            curr_sum += array[j];
            j++;
        }
    }
    while (i < n && curr_sum >= target_sum)
    {
        if (curr_sum == target_sum)
                counter++;
        curr_sum -= array[i];
        i++;
    }
    cout << counter << endl;
}