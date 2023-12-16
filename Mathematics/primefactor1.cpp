/*
    Prime Factorization
    Time Complexity : O(sqrt(N))
    Author :Arush Kumar
*/

#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    for(int i=2;i*i<=n;i++)//if a no is not prime then one factor is always less than its square root
    {
        if(n%i==0)
        {
            int count=0;
            while(n%i==0)
            {
                count++;
                n/=i;
            }
            if(n>1)
            cout<<"("<<i<<"^"<<count<<")"<<"*";
            else
                cout<<"("<<i<<"^"<<count<<")";
        }
    }
    if(n>1)
        cout<<"("<<n<<"^1)";
    return 0;
}
