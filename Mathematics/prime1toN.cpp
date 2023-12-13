/*
    Algorithm Used : sieve of Eratosthenes
    More at https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
    Time complexity : O(nloglogn)
    
    The idea of this algo is a no is a prime if its lower prime can't divide it
    so on getting a prime we cancel all its multiple
*/
#include<bits/stdc++.h>

using namespace std;

bool arr[1000001];

vector<int>listofprimes;

void sieve()
{
    int n=1000000;
    arr[0]=arr[1]=true;//0 and 1 are composite so : let true =composite & false=prime
    for(int i=2;i*i<=n;i++)
    {
        if(!arr[i])
        {
            for(int j=i*i;j<=n;j+=i)//first multiple of a number that is unmarked starts from its square
            {                       //eg for i=7 1st unmarked multiple= 49 since 14(7*2) will be marked true by 2
                arr[j]=true;        //-lly 21 by 3,28 by 4...
            }
        }
    }
    for(int i=2;i<=n;i++)
        if(!arr[i])
            listofprimes.push_back(i);
}
int main(){
    sieve();
    for(int i=0;i<=200;i++)//printing first 200 primes
        cout<<listofprimes[i]<<" ";
}
