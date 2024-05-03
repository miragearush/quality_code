/*
    Selection sort
    find the smallest element and swap with it
*/
#include <iostream>
using namespace std;

int smallest(int a[],int k,int n)
{
    int small=k;
    for(int i=k+1;i<n;i++)
    {
        if(a[i]<a[small])
        {
            small=i;
        }
    }
    return small;
}

void selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int smaller=smallest(a,i,n);
        int temp=a[i];
        a[i]=a[smaller];
        a[smaller]=temp;
    }
}
int main()
{
    int a[]={6,1,5,3,2};
    selectionsort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";

    return 0;
}
