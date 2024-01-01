//checking prime in O(sqrt n)
#include<bits/stdc++.h>
using namespace std;

int main() {
     long long n;
     cin>>n;
     if(n<=1) //checking when n<=1
     {
          cout<<"NO";
          exit(0);
     }
     if(n==2 || n==3) //checking when n=2,3
     {
          cout<<"YES";
          exit(0);
     }
     /*
     in (6n-1) & (6n+1) cases div by 2 & 3 are ommited so checking such cases seperatly
     */
     if(n%2==0 || n%3==0)
     {
          cout<<"NO";
          exit(0);
     }
     for(int i=5;i<=sqrt(n);i+=6) //this loop runs like (6n-1)
     {
          if(n%i==0 || n%(i+2)==0)//i+2 will act as (6n+1)
          {
               cout<<"NO";
               return 0;
          }
     }
     cout<<"YES";
     return 0;
}