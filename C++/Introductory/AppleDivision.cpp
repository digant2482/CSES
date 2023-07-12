#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    arr.resize(n);
    long long sum_of_arr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum_of_arr += arr[i];
    }

    deque<string> myqueue;
    myqueue.push_front(string(n-1,'0')+"1");

    long long min_difference = 1e18;
    int last_element = pow(2,n)-1;
    for (int i = 0; i < last_element;i++)
    {
        string curr_binary = myqueue.back();
        long long curr_sum = 0;   
        for(int i = 0; i < n; i ++)
        {
            if (curr_binary[i] == '1')
                curr_sum += arr[i];
        }
        min_difference = min(min_difference,abs(sum_of_arr - 2*curr_sum));
        // Updating deque as required is great practice
        myqueue.pop_back();
        myqueue.push_front(curr_binary.substr(1)+"0");
        myqueue.push_front(curr_binary.substr(1)+"1");
    }
    cout << min_difference << endl;  
}