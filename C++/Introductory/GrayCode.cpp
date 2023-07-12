#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
    deque<string> myqueue;
    int n;
    cin >> n;
    int total_num = pow(2,n);
    cout << string(n,'0') << '\n';
    myqueue.push_front(string(n-1,'0') + "1");
    int counter = 1;
    bool ends_with_zero = false;
    while (counter < total_num)
    {
        string curr_binary = myqueue.back();
        cout << curr_binary << '\n';
        counter++;
        myqueue.pop_back();
        if (ends_with_zero)
        {
            myqueue.push_front(curr_binary.substr(1) + "0");
            myqueue.push_front(curr_binary.substr(1) + "1");
            ends_with_zero = false;
        }
        else
        {
            myqueue.push_front(curr_binary.substr(1) + "1");
            myqueue.push_front(curr_binary.substr(1) + "0");
            ends_with_zero = true;
        }
    } 
    cout << endl;       
}