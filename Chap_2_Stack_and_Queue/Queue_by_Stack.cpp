#include<iostream>
using namespace std;


struct node
{
    int data;
    node* next;
};

bool Is_empty(node* top_cop)
{
    if(top_cop == NULL)return true;
    else return false;
}


void print_stack(node* top_cop)
{
    cout<<"current stack is: ";
    while(top_cop != NULL)
    {
        cout<<top_cop->data<<" ";
        top_cop = top_cop->next;
    }
    cout<<endl;
    return;
}

//�o��ǤJ��top_addr�n�Otop���Ъ���m(&top)�A�]���o�˱q�o�̧��top_addr�Amain����top�~�|��ۧ��
//�]���ǤJ���O&top�A�O�������СA�]���ŧi�ɭn�ŧinode**
void push(node** top_addr,int in)
{
//    cout<<"top_addr: "<<top_addr<<endl;
//    cout<<"*top_addr: "<<*top_addr<<endl;
    node* t = new node;
    t->data = in;
    //�]��top_addr�����Ȳ{�Otop����}�A�ҥH�n��*top�~����omain����top���V����}
    t->next = *top_addr;
    *top_addr = t;
    //cout<<"push sucessful"<<endl;
    return;
}

int pop(node** top_addr)
{
    int out;
    if(*top_addr == NULL)
    {
        cout<<"stack is empty,can't pop data any more"<<endl;
        out = NULL;
    }
    else
    {
    node* t;
    //�]��top_addr�����Ȳ{�Otop����}�A�ҥH�n��*top_addr�~����omain����top���V����}
    t = *top_addr;
    out = (*top_addr)->data;
    *top_addr = (*top_addr)->next;
    delete(t);
    }
    return out;
}

void clear_stack(node** top_addr)
{
    node* t;
    while(*top_addr != NULL)
    {
        t = *top_addr;
        *top_addr = (*top_addr)->next;
        delete(t);
    }
    return;
}

void enqueue(node** Stop_addr,int in)
{
    push(Stop_addr,in);
}

int dequeue(node** Stop_addr,node** Ttop_addr)
{
    int out;
    if(*Ttop_addr!=NULL)
    {
        out = pop(Ttop_addr);
        return out;
    }
    else
    {
        if(Is_empty(*Stop_addr))
        {
            cout<<"Queue empty"<<endl;
            return NULL;
        }
        else
        {
            while(!Is_empty(*Stop_addr))
            {
                out = pop(Stop_addr);
                push(Ttop_addr,out);
            }
            dequeue(Stop_addr,Ttop_addr);
        }
    }
}


int main()
{
    node* Stop = NULL;
    node* Ttop = NULL;
    string cmd;
    int in,out;
    cout<<"input [enqueue x] to enqueue x to the queue or [dequeue] to delete the front of queue"<<endl;
    while(cin>>cmd)
    {
        if(cmd == "enqueue")
        {
            cin>>in;
            enqueue(&Stop, in);
//            print_stack(start);

        }
        else if(cmd == "dequeue")
        {
            out = dequeue(&Stop, &Ttop);
            if(out != NULL)cout<<"Delete "<<out<<" in Queue."<<endl;
//            print_stack(start);
        }
        else
            cout<<"wrong cmd"<<endl;
        cout<<"input [enqueue x] to enqueue x to the queue or [dequeue] to delete the front of queue"<<endl;
    }
    return 0;
}
