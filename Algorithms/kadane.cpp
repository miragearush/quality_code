/*
    Author : Arush
    Kadane's Algorithm 
    Used to find the largest subsequence
    Time Complexity : O(n)
    Example problem link : https://codeforces.com/contest/327/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
          cin>>a[i];
     int sum=0,start=-1,ansstart=-1,ansend=-1,count=0,maxi=INT_MIN;
     for(int i=0;i<n;i++)
     {
        if(sum==0)//sub-sequence starts once sum is zero
               start=i;
          if(a[i]==0)//this is because of problem statement
          {
               sum+=1;
          }
          else if(a[i]==1)//given in problem statement
               sum-=1;
          if(sum>maxi)//whenever present sub sequence sum is g.t maxi 
          {
               maxi=sum;//we first replace the maxi with sum
               ansstart=start;//since this sum is maxi so we store starting index of present sub sequence 
               ansend=i;
          }
          if(sum<0)//whenever sum is less than zero we start again
          {
              sum=0;
          }
     }
     for(int i=ansstart;i<=ansend;i++)//ans start contains the starting index of max sub sequence
     {
          a[i]=1-a[i];
     }
     for(int i=0;i<n;i++)
     {
         if(a[i]==1)
               count++; 
     }
          
     cout<<count;
     return 0;
     
}