#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = n-1;
    int counter = 0;
    
    while(i<=j)
    {
        if (arr[j] + arr[i] <= x)
        {
            counter++;
            i++;
            j--;
        }
        else
        {
            counter++;
            j--;    
        }
    } 
    cout << counter << endl;   
}