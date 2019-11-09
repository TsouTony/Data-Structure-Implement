#include<iostream>
using namespace std;


struct node
{
    char data;
    node* next;
};

bool Is_empty(node* top_cop)
{
    if(top_cop == NULL)
        return true;
    else
        return false;
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
    //print_stack(*top_addr);
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
    //print_stack(*top_addr);
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

bool match(string in)
{
    int i = 0;
    node* top = NULL;
    bool b_appear = false;
    while(in[i] != NULL)
    {
        if(in[i] == 'b')
        {
            b_appear = true;
            if(Is_empty(top))
            {
                cout<<"b more that a"<<endl;
                return false;
            }
            else pop(&top);
        }
        else if(in[i] == 'a')
        {
            if(b_appear == true)
            {
                cout<<"a after b"<<endl;
                return false;
            }
            else push(&top,in[i]);
        }
        else
        {
            cout<<"wrong input"<<endl;
            return false;
        }
        i++;
    }
    if(Is_empty(top))return true;
    else
    {
        cout<<"a more than b"<<endl;
        return false;
    }
}

int main()
{
    string in;
    bool legal;
    cout<<"input a*b* to check wheather a is always precede then b and |a| == |b|"<<endl;
    while(cin>>in)
    {
        legal = match(in);
        if(legal)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
