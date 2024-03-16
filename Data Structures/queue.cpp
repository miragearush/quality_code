/*
    Menue driven program for linear Queue
    Author : Arush
    Date : 16/03/2024
*/
#include <iostream>

using namespace std;

struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};
void create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int(size);
}
void enqueue(Queue *q,int x)
{
    if(q->rear==(q->size)-1)
    {
        cout<<"Queue is full\n";
        return ;
    }
    q->rear++;
    q->Q[q->rear]=x;
}
int dequeue(Queue *q)
{
    if(q->front==q->rear)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    q->front++;
    int x=q->Q[q->front];
    return x;
}
void display(Queue *q)
{
    for(int i=q->front+1;i<=q->rear;i++)
        cout<<q->Q[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,choice;
    cout<<"Enter size : \n";
    cin>>n;
    Queue q;
    create(&q,n);
    do{
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Display\n";
        cout<<"4.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int x;
                cout<<"Enter element to insert:\n";
                cin>>x;
                enqueue(&q,x);
                break;
            case 2:
                cout<<"Element deleted "<<dequeue(&q)<<endl;
                break;
            case 3:
                display(&q);
                break;
            case 4:
                cout<<"Exited successfully !\n";
                exit(0);
        }
    }while(choice!=4);
    return 0;
}
