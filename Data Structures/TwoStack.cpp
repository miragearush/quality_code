#include <iostream>
#define SIZE 100
using namespace std;

int stack[SIZE];
int top1=-1,top2=SIZE;
void push(int stackno,int x)
{
    //overflow condition
    if(top1+1==top2)
    {
        cout<<"Stack Overflow\n";
        return;
    }
    if(stackno==1)
    {
        top1++;
        stack[top1]=x;
    }
    else if(stackno==2)
    {
        top2--;
        stack[top2]=x;
    }
}
int pop(int stackno)
{
    int x=-1;
    if(stackno==1)
    {
        if(top1==-1)
        {
            cout<<"Stack 1 is empty\n";
            return x;
        }
        x=stack[top1];
        top1--;
    }
    else if(stackno==2)
    {
        if(stackno==2 && top2==SIZE)
        {
            cout<<"Stack 2 is empty\n";
            return x;
        }
        x=stack[top2];
        top2++;
    }
    return x;
}
void display(int stackno)
{
    if(stackno==1)
    {
        if(top1==-1)
        {
            cout<<"Stack 1 is empty\n";
            return ;
        }
        for(int i=0;i<=top1;i++)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
    else if(stackno==2)
    {
        if(top2==SIZE)
        {
            cout<<"Stack 2 is empty\n";
            return ;
        }
        for(int i=SIZE-1;i>=top2;i--)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int choice,x;
    cout<<"1.Push in stack 1\n";
    cout<<"2.Push in stack 2\n";
    cout<<"3.Pop from stack 1\n";
    cout<<"4.Pop from stack 2\n";
    cout<<"5.Display stack 1\n";
    cout<<"6.Display stack 2\n";
    cout<<"7.Exit\n";
    do {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter element to push\n";
            cin>>x;
            push(1,x);
            break;
            case 2:
            cout<<"Enter element to push\n";
            cin>>x;
            push(2,x);
            break;
            case 3:
            cout<<"Popped "<<pop(1)<<endl;
            break;
            case 4:
            cout<<"Popped "<<pop(2)<<endl;
            break;
            case 5:
            display(1);
            break;
            case 6:
            display(2);
            break;
            case 7:
            exit(0);
        }
    }while(choice!=7);

    return 0;
}
