/*
    Matrix Exponentiation (matrix ^ n)
    Author : Arush
    Time Complexity :O(m^3*n)
    Tips: Concept used in this is same as in Binary Exponentiation refer that program for
          better explanation with example
    Problem Link- https://www.spoj.com/problems/MPOW/
*/
#include <iostream>

#define mod 1000000007
#define N 101

typedef long long ll;

ll a[N][N],ide[N][N];

using namespace std;

void multi(ll a[][N],ll b[][N],int m)//simple matrix multiplication
{
    ll res[m+1][m+1];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            res[i][j]=0;
            for(int k=1;k<=m;k++)
            {
                res[i][j]=(res[i][j]%mod+((a[i][k]%mod)*(b[k][j]%mod)%mod))%mod;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=res[i][j];
        }
    }
}

void power(ll a[][N],int m,int n)
{
    for(int i=1;i<=m;i++)//setting up identity matrix ; result will be stored in this 
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j)
                ide[i][j]=1;
            else
                ide[i][j]=0;
        }
    }
    while(n)//same concept as in binary Exponentiation
    {
        if(n%2)//when odd we multipliy ide=ide*a and power--
        {
            multi(ide,a,m);
            n--;
        }
        else//when its even we multiply a with a and power/2
        {
            multi(a,a,m);
            n/=2;
        }
    }
    for(int i=1;i<=m;i++)//finally copying the final result from ide to matrix a
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=ide[i][j];
        }
    }
}
void printmat(ll a[][N],int m)//to print the matrix 
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll m,n;
        cin>>m>>n;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        power(a,m,n);
        printmat(a,m);
    }

    return 0;
}
