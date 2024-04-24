/*
    QuickSort
    Best : O(nlogn) - when partition is done in middle
    Worst : (n^2) - when array is sorted either increasing or decreasing i.e; pivot is on either ends
*/
#include <iostream>
#include<climits>
using namespace std;

int partition(int a[],int l,int h)
{
    int pivot=a[l];//selecting the first element as pivot
    int i=l,j=h;
    do{
        do{
            i++;
        }while(a[i]<=pivot);//i will point on element that is greater than the pivot
        do{
            j--;
        }while(a[j]>pivot);//j will point on element less than or equal to pivot
        if(i<j)// such i j exits swap the element 
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    // now swap with the pivot element and put it on the right location
    a[l]=a[j];
    a[j]=pivot;
    return j;
}
void QuickSort(int a[],int l,int h)
{
    if(l<h)
    {
        int loc=partition(a,l,h);//putting the pivot element on its sorted position
        QuickSort(a,l,loc);//now sorting is done on left side of partition (loc will act as infinity)
        QuickSort(a,loc+1,h);// now sorting is done on right side of partition
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    a[n]=INT_MAX;
    QuickSort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
