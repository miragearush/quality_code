//finding divisors in O(root n )
#include <iostream>

using namespace std;

int main() {
    int n,count=0;
    cin>>n;
    for(int i=1;i*i <=n;i++)
    {
        if(n%i==0) // i is a factor
            count++;
        if(i!=n/i) //if i is a factor then n/i will also be a factor
            count++;
    }
    cout<<count;
    return 0;
}