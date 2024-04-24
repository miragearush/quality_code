/*
    MergeSort
    O(nlogn)
    Divide conquer and combine
*/
#include <iostream>
#include<climits>
using namespace std;

void merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int temp[100];//creating auxillary array and storing the merged sorted result
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    for(;i<=mid;i++)//if first half is remaining then copy the rest in temp
        temp[k++]=a[i];
    for(;j<=h;j++)//if second half is remaining then copy the rest in temp / only one of the two will be left
        temp[k++]=a[j];
    for(i =l;i<=h;i++)//after everything finally copy the result in array
        a[i]=temp[i];
}
void MergeSort(int a[],int l,int h)
{
    if(l<h)//it will stop when there is one or zero element as l==h at that time
    {
        int mid=(l+h)/2;
        MergeSort(a,l,mid);//divide & sort left part
        MergeSort(a,mid+1,h);//divide & sort right part
        merge(a,l,mid,h); //finally merge left and right part
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    MergeSort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
