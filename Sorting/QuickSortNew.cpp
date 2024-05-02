/*
    QuickSort
    In this we take first element as pivot 
    we iterate from right and stop when we find element smaller than pivot 
    now we check if right (j) has reached pivot as it has found no element smaller
    that means it is in the correct position
    else
    we replace pivot with that element as smaller element should be in left of pivot
    also we change the pivot index as it has been swaped
    now we check for left side 
    
*/
#include <iostream>

using namespace std;
int partition(int a[],int start,int end)
{
    int i=start,j=end,pivot=start,flag=0;
    while(flag!=1)
    {
        while(a[pivot]<=a[j] && pivot!=j)
            j--;
        if(j==pivot)
            flag=1;
        else
        {
            int temp=a[pivot];
            a[pivot]=a[j];
            a[j]=temp;
            pivot=j;
        }
        if(flag!=1)
        {
            while(a[pivot]>=a[i] && pivot!=i)
                i++;
            if(i==pivot)
                flag=1;
            else
            {
                int temp=a[pivot];
                a[pivot]=a[i];
                a[i]=temp;
                pivot=i;
            }
        }
    }
    return pivot;
}

void QuickSort(int a[],int start,int end)
{
    int part;
    if(start<end)
    {
        int part=partition(a,start,end);
        QuickSort(a,start,part-1);
        QuickSort(a,part+1,end);
        
    }
}

int main()
{
    int a[]={4,1,2,3,6,13};
    QuickSort(a,0,5);
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";

    return 0;
}
