/*
    Bubble Sort
*/
#include <iostream>
using namespace std;

void bubblesort(int a[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag==0)
            return;//already sorted
    }
}
int main()
{
    int a[]={6,1,5,3,2};
    bubblesort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";

    return 0;
}
