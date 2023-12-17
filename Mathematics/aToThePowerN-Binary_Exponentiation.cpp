/*
    Binary Exponentiation technique to find a to the power n
    Author: Arush
    Time Complexity : O(log n)
    
    Logic: Eg:- 2 to the power 9
    
    res     base    power
    1       2       9   when power is odd multiply it with res and make it even
    1*2     2       8   when even square the base and div power by 2
    2       4       4 
    2       16      2 
    2       256     1 
    2*256   256     0
    
    res=512
*/
#include <iostream>

using namespace std;

long long int atothepowerN(int a,int n)
{
    long long int res=1;
    while(n)
    {
        if(n%2)//odd power
        {
            res*=a;//multiplying res with base 
            n--;//subtraction 1 from power
        }
        else//for even power
        {
            a*=a;//squaring the base
            n/=2;//dividing the power by 2
        }
    }
    return res;
}
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<atothepowerN(a,n);
    return 0;
}