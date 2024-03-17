#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void insert(int index,int x)
{
    Node *t=new Node,*p=first;
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1 && p;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int deleti(int index)
{
    Node *p,*q=NULL;
    int x=-1;
    if(index==0)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}
void display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    do{
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.display\n";
        cout<<"4.Exit\n";
        int choice;
        cin>>choice;
        int ind,num;
        switch(choice)
        {
            case 1:
            cout<<"Enter index & num to insert\n";
            cin>>ind>>num;
            insert(ind,num);
            break;
            case 2:
            cout<<"Enter index to delete\n";
            cin>>ind;
            cout<<"Element deleted "<<deleti(ind)<<endl;
            break;
            case 3:
            display(first);
            break;
            case 4:
            cout<<"Program exited successfully\n";
            exit(0);
        }
    }while(1);

    return 0;
}
