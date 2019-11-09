#include<iostream>
#include<string>
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

//這邊傳入的top_addr要是top指標的位置(&top)，因為這樣從這裡改動top_addr，main中的top才會跟著改動
//因為傳入的是&top，是雙重指標，因此宣告時要宣告node**
void push(node** top_addr,int in)
{
//    cout<<"top_addr: "<<top_addr<<endl;
//    cout<<"*top_addr: "<<*top_addr<<endl;
    node* t = new node;
    t->data = in;
    //因為top_addr中之值現是top的位址，所以要取*top才能取得main中之top指向的位址
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
        //因為top_addr中之值現是top的位址，所以要取*top_addr才能取得main中之top指向的位址
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

bool Palindrome(string in)
{
    node* top = NULL;
    int i=0,j;
    for(j=0; j<in.size()/2; j++)
    {
        push(&top,in[i]);
        i++;
    }
    if(in.size() % 2 != 0)
        i++;
    for(j=0; j<in.size()/2; j++)
    {
        if(in[i] != pop(&top))
            return false;
        i++;
    }
    return true;
}

int main()
{
    string in;
    bool legal;
    while(cin>>in)
    {
        legal = Palindrome(in);
        if(legal)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}
