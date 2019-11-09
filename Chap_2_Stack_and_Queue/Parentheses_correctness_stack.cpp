#include<iostream>
using namespace std;

struct node
{
    char data;
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
    node* t = new node;
    t->data = in;
    //因為top中之值現是top的位址，所以要取*top才能取得main中之top指向的位址
    t->next = *top;
    *top = t;
    return;
}

int pop(node** top)
{
    int out;
    if(*top == NULL)
    {
        out = NULL;
    }
    else
    {
        node* t;
        //因為top中之值現是top的位址，所以要取*top才能取得main中之top指向的位址
        t = *top;
        out = (*top)->data;
        *top = (*top)->next;
        delete(t);
    }
    return out;
}

int Parenthese(string p)
{
    node* top = NULL;
    int i=0;
    char out;
    while(p[i] != NULL)
    {
        if(p[i] == '(')
        {
            push(&top,p[i]);
            //print_stack(top);
        }
        else if(p[i] == ')')
        {
            out = pop(&top);
            //print_stack(top);
            if(out == NULL)
            {
                return 0;
            }
        }
        else
        {
            return 2;
        }
        i++;
    }
    if(top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    string p;
    char out;
    int cas;
    cout<<"input a stream of ( ) to confirm wheather the parentheses is legal or not"<<endl;
    while(cin>>p)
    {
        cas = Parenthese(p);
//        switch(cas)
//        {
//            case 0:
//                cout<<"no"<<endl;
//            case 1:
//                cout<<"yes"<<endl;
//            case 2:
//                cout<<"wrong input please just input (, ) or 0"<<endl;
//        }
        if(cas == 0)cout<<"no"<<endl;
        else if(cas == 1)cout<<"yes"<<endl;
        else cout<<"wrong input please just input (, ) or 0"<<endl;
        cout<<"input a stream of ( ) to confirm wheather the parentheses is legal or not"<<endl;
    }
    return 0;
}
