/*
    Insertion sort
    first element in itself is already sorted so sorting starts from 2nd onwards
    we are selecting a postion for every element
*/
#include <iostream>
using namespace std;

void insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int x=a[i];
        int j=i-1;
        while(a[j]>x && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
int main()
{
    int a[]={6,1,5,3,2};
    insertionsort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";

    return 0;
}
