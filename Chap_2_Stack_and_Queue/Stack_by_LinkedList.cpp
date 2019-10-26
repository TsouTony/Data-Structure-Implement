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

//�o��ǤJ��top�n�O*top����m(&top)�A�]���o�˱q�o�̧��top�Amain����top�~�|��ۧ��
//�]���ǤJ���O&top�A�O�������СA�]���ŧi�ɭn�ŧinode**
void push(node** top,int in)
{
    cout<<"top: "<<top<<endl;
    cout<<"*top: "<<*top<<endl;
    node* t = new node;
    t->data = in;
    //�]��top�����Ȳ{�Otop����}�A�ҥH�n��*top�~����omain����top���V����}
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
    //�]��top�����Ȳ{�Otop����}�A�ҥH�n��*top�~����omain����top���V����}
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
            //�n�ǤJ&top�~�|��main��top��function��top�O�P�@��
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
