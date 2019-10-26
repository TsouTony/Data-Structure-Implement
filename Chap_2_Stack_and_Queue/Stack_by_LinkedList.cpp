#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

print_stack(node* top)
{
    node* t = top;
    cout<<"current stack is: ";
    while(t != NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

//這邊傳入的top要是*top的位置(&top)，因為這樣從這裡改動top，main中的top才會跟著改動
//因為傳入的是&top，是雙重指標，因此宣告時要宣告node**
void push(node** top,int in)
{
    cout<<"top: "<<top<<endl;
    cout<<"*top: "<<*top<<endl;
    node* t = new node;
    t->data = in;
    //因為top中之值現是top的位址，所以要取*top才能取得main中之top指向的位址
    t->next = *top;
    *top = t;
    cout<<"push sucessful"<<endl;
}

int pop(node** top)
{
    int out;
    if(*top == NULL)
        cout<<"stack is empty,can't pop data any more"<<endl;
    else
    {
    node* t;
    //因為top中之值現是top的位址，所以要取*top才能取得main中之top指向的位址
    t = *top;
    out = (*top)->data;
    *top = (*top)->next;
    delete(t);
    }
}

int main()
{
    node* top = NULL;
    int in,out;
    string cmd;
    cout<<"input [push X for push X in the stack and [pop] for pop the data from the stack."<<endl;
    while(cin>>cmd)
    {
        if(cmd == "push")
        {
            cin>>in;
            //要傳入&top才會讓main的top跟function的top是同一個
            push(&top, in);
            print_stack(top);
        }
        else if(cmd == "pop")
        {
            out = pop(&top);
            print_stack(top);
        }
        else
            cout<<"wrong comd has been input"<<endl;
    }


    return 0;
}
