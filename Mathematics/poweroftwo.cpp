
#include <bits/stdc++.h>
using namespace std;

int main() {
long long n ;
cin>>n;
// logic of this code is power of two is always carry one set bit  2 -10 , 4 -100 , 8-1000
int cont=0;
        while(n )
        {
          
           if(n&1==1) // using and gate to  1&1 = 1 and 1&0 = 0 and gate oprate right most bit 
           cont++;
         n= n>>1;// right shift operater to use shift the bit >>1 that is sift one time and >>2 that is sift two  (number)>>(number of time sift)
           
            
        }
        if(cont==1)//only conter is one then is power of two
       cout<<"YES";
       else cout<<"NO";
    }
