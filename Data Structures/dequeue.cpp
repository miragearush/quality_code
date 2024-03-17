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
void insert_front(Queue *q,int x)
{
    if(q->front==-1)
    {
        cout<<"Insertion from front not possible\n";
        return;
    }
    q->Q[q->front]=x;
    q->front--;
}
void insert_back(Queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        cout<<"Insertion from back not possible\n";
        return;
    }
    q->rear++;
    q->Q[q->rear]=x;
}
int delete_front(Queue *q)
{
    if(q->front==q->rear)
    {
        cout<<"Dequeue is empty\n";
        return -1;
    }q->front++;
    int x=q->Q[q->front];
    return x;
}
int delete_back(Queue *q)
{
    if(q->front==q->rear)
    {
        cout<<"Dequeue is empty\n";
        return -1;
    }
    int x=q->Q[q->rear];
    q->rear--;
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
    int size,choice;
    cout<<"Enter size :\n";
    cin>>size;
    Queue q;
    create(&q,size);
    do{
        cout<<"1.Insert from front\n";
        cout<<"2.Insert from back\n";
        cout<<"3.Delete from front\n";
        cout<<"4.Delete from back\n";
        cout<<"5.Display\n";
        cout<<"6.Exit\n";
        cin>>choice;
        int x;
        switch(choice)
        {
            case 1:
            cout<<"Enter element:\n";
            cin>>x;
            insert_front(&q,x);
            break;
            case 2:
            cout<<"Enter element:\n";
            cin>>x;
            insert_back(&q,x);
            break;
            case 3:
            cout<<delete_front(&q)<<" deleted\n";
            break;
            case 4:
            cout<<delete_front(&q)<<" deleted\n";
            break;
            case 5:
            display(&q);
            break;
            case 6:
            exit(0);
        }
    }while(choice!=6);

    return 0;
}
