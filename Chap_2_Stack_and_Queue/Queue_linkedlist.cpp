#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void print_queue(node* start)
{
    cout<<"current queue: ";
    while(start != NULL)
    {
        cout<<start->data<<" ";
        start = start->next;
    }
    cout<<endl;
}


void enqueue(node** start_addr,node** rear_addr,int in)
{
    node* t = new node;
    t->data = in;
    if(*start_addr == NULL)
    {
        *start_addr = t;
        *rear_addr = t;
    }
    else
    {
        (*rear_addr)->next = t;
        *rear_addr = t;
    }
    return;
}

int dequeue(node** start_addr, node** rear_addr)
{
    int out;
    if(*start_addr == NULL)
    {
        cout<<"queue empty"<<endl;
        return NULL;
    }
    node* t = *start_addr;
    out = (*start_addr)->data;
    *start_addr = (*start_addr)->next;
    if(*start_addr == NULL)
        *rear_addr == NULL;
    delete t;
    return out;
}


int main()
{
    int in;
    node* start = NULL;
    node* rear = NULL;
    string cmd;
    cout<<"input [enqueue x] to enqueue x to the queue or [dequeue] to delete the front of queue"<<endl;
    while(cin>>cmd)
    {
        if(cmd == "enqueue")
        {
            cin>>in;
            enqueue(&start, &rear, in);
            print_queue(start);

        }
        else if(cmd == "dequeue")
        {
            dequeue(&start, &rear);
            print_queue(start);
        }
        else
            cout<<"wrong cmd"<<endl;
        cout<<"input [enqueue x] to enqueue x to the queue or [dequeue] to delete the front of queue"<<endl;
    }


    return 0;
}
