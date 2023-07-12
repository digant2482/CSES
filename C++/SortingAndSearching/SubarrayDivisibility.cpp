#include <iostream>
#include <vector>
#include <map>
typedef long long ll;

using namespace std;    

int main()
{
    int size;
    cin >> size;
    vector<ll> cum_sum_remainder_array(size);
    int num;
    ll cum_sum_remainder = 0;
    for (int i = 0; i<size; i++)
    {
        cin >> num;
        cum_sum_remainder += (num % size + size)%size;
        cum_sum_remainder_array[i] = cum_sum_remainder;
    }
    
    vector<int> modulo_cum_sum_remainder(size);
    for (int i = 0; i<size; i++)
        modulo_cum_sum_remainder[i] = cum_sum_remainder_array[i] % size;

    map<ll,int> cum_sum_frequency;
    cum_sum_frequency[0]++;
    ll counter = 0;
    for (const int& element: modulo_cum_sum_remainder)
    {
        counter += cum_sum_frequency[element];
        cum_sum_frequency[element]++;
    }
    cout << counter << endl; 
}