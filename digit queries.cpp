#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v(18,0);
 
void cal(vector<ll> &v)
{
    for (ll i = 1; i <= 17; i++)
    {
        v[i] = ((9 * i * pow(10, i - 1)));
    }
    return;
}
 
ll solve()
{
    cal(v);
    
    // printing value of v
    // for(auto i:v)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
 
 
    ll query = 1;
    cin >> query;
    while (query--)
    {
        ll k;
        cin >> k;
 
        ll sum = 0;
        ll length_of_number = 0;
        for (ll i = 0; i <= 17; i++)
        {
            sum += v[i];
            if (sum <= k)
            {
                length_of_number = i + 1;
            }
            else
            {
                break;
            }
        }
 
 
        sum -= v[length_of_number];
        // cout<<"sum : "<<sum<<endl;
        ll difference = k - sum;
        // cout<<"difference : "<<difference<<endl;
        ll starting_number = pow(10, length_of_number - 1);
        ll distance_from_starting_number = (difference / length_of_number);
        // sum += (distance_from_starting_number * length_of_number);
        ll actual_number = starting_number + distance_from_starting_number - 1;
        ll remainder = difference % length_of_number;
        // cout<<"remainder : "<<remainder<<endl;
        // cout<<"actual_number : "<<actual_number<<endl;
        // cout<<"sum : "<<sum<<endl;
        if (remainder == 0)
        {
            cout << actual_number % 10 << endl;
        }
        else
        {
            actual_number++;
            // cout<<"final actual number : "<<actual_number<<endl;
            remainder = length_of_number - remainder;
            while (remainder--)
            {
                actual_number /= 10;
            }
            cout << actual_number % 10 << endl;
        }
    }
 
    return 0;
}
 
int main()
{
    solve();
    return 0;
}