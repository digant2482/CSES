#include <iostream>
#include <set>

using namespace std;

int main()
{
    int lenStreet, trafficLights;
    cin >> lenStreet >> trafficLights;
    multiset<int> lights;
    lights.insert(0);
    lights.insert(lenStreet);
    multiset<int> passageLength;
    passageLength.insert(lenStreet);
    
    int posLight;
    for (int i = 0; i<trafficLights; i++)
    {
        cin >> posLight;
        auto itr = lights.insert(posLight);
        int right = *next(itr,1);
        int left = *next(itr,-1);
        passageLength.erase(passageLength.find(right-left));
        passageLength.insert(right - posLight);
        passageLength.insert(posLight - left);
        cout << *--passageLength.end() << " ";
    }
}