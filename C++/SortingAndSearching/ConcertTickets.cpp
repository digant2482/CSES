#include <iostream>
#include <set>

using namespace std;

int main()
{
    int num_tickets, num_customers;
    cin >> num_tickets >> num_customers;

    multiset<int> tickets_arr;
    for(int i = 0; i<num_tickets ;i++)
    {
        int ticket_price;
        cin >> ticket_price;
        tickets_arr.insert(ticket_price);
    }  

    for(int i = 0; i<num_customers ;i++)
    {
        int customer_bid;
        cin >> customer_bid;
        auto itr = tickets_arr.upper_bound(customer_bid);
        if (itr != tickets_arr.begin())
        {
            cout << *--itr << '\n';
            tickets_arr.erase(itr);
        }
        else
            cout << -1 << endl;
    }  
}