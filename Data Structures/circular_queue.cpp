/*
    Menue driven program for Circular Queue
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
    q->front=q->rear=0;
    q->Q=new int(size);
}
void enqueue(Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
    {
        cout<<"Queue is full\n";
        return ;
    }
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
}
int dequeue(Queue *q)
{
    if(q->front==q->rear)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    q->front=(q->front+1)%q->size;
    int x=q->Q[q->front];
    return x;
}
void display(Queue *q)
{
    int i=q->front+1;
    do{
        cout<<q->Q[i]<<" ";
        i=(i+1)%q->size;
    }while(i!=(q->rear+1)%q->size);
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