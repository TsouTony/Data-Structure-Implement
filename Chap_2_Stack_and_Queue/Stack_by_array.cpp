#include<iostream>
using namespace std;

int top = 0;//initailize the position of stack top

void print_stack(int* stk)
{
    int i;
    cout<<"current stack is: ";
    for(i=1;i<=top;i++)
        cout<<stk[i]<<" ";
    cout<<endl;
}
void push(int*stk,int in,int siz)
{
    if(top == siz)
        cout<<"stack is full,can't push data any more"<<endl;
    else
    {
        top++;
        stk[top] = in;
    }
}

int pop(int* stk)
{
    int out;
    if(top == 0)
        cout<<"stack is empty,can't pop data any more"<<endl;
    else
    {
        out = stk[top];
        top--;
        cout<<"pop "<<out<<" out"<<endl;
        return out;
    }
}

int main()
{
    int siz;
    int in,out;
    string cmd;
    cout<<"input the size of the stack you want: ";
    cin>>siz;
    int stk[siz+1];
    cout<<"input [push X] for push X in the stack and [pop] for pop the data from the stack."<<endl;
    while(cin>>cmd)
    {
        if(cmd == "push")
        {
            cin>>in;
            push(stk, in, siz);
            print_stack(stk);
        }
        else if(cmd == "pop")
        {
            out = pop(stk);
            print_stack(stk);
        }
        else
            cout<<"wrong comd has been input"<<endl;
    }


    return 0;
}
