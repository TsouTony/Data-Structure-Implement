#include<iostream>
using namespace std;


int start = 0, rear = 0;


int queue_length(int ary_siz)
{
    //若rear > start，則 (rear - start + ary_siz) % ary_siz = rear-start (因為rear-start < n)
    //此處rear - start 即為 array 中有存放data(i.e.,queue長度)之格子個數
    //若rear < start，則 (rear - start + ary_siz) % ary_siz = rear -start + ary_siz (因為 rear - start +ary_siz < n)
    //此處rear - start 即為 array 中沒有存放data之格子個數的負值，所以此負值加上ary_siz即為有data之格子個數
    return (rear - start + ary_siz)%ary_siz;
}
void print_queue(int* ary,int ary_siz)
{
    int i,j=start;
    cout<<"current queue is: ";
    for(i=0;i<queue_length(ary_siz);i++)
    {
        j=(j+1)%ary_siz;
        cout<<ary[j]<<" ";
    }
    cout<<endl;
}

void enqueue(int* ary, int in,int ary_siz)
{
//    cout<<"enqueue's ary: "<<ary<<endl;
//    cout<<"enqueue's ary[1]: "<<ary[1]<<endl;
    if((rear+1)%ary_siz == start)
    {
        cout<<"queue full"<<endl;
    }
    else
    {
        rear = (rear+1)%ary_siz;
        ary[rear] = in;
//        cout<<"enqueue successfully"<<endl;
    }
//    cout<<"current start: "<<start<<" ,current rear: "<<rear<<endl;
    return;
}

int dequeue(int* ary,int ary_siz)
{
    int out;
//    cout<<"dequeue's ary: "<<ary<<endl;
//    cout<<"dequeue's *ary: "<<*ary<<endl;
//    cout<<"dequeue's ary[0]: "<<ary[0]<<endl;
//    cout<<"dequeue's ";
//    print_queue(ary,ary_siz);
    if(start == rear)
    {
        out = NULL;
    }
    else
    {
        start = (start+1)%ary_siz;
        out = ary[start];
    }
//    cout<<"dequeue's out: "<<out<<endl;
//    cout<<"current start: "<<start<<" ,current rear: "<<rear<<endl;
    return out;

}

void push(int* ary, int in, int ary_siz)
{
    //cout<<"ary in push: "<<ary<<endl;
    enqueue(ary, in, ary_siz);
}

int pop(int* ary,int ary_siz)
{
    int i,out;
    for(i=0; i<queue_length(ary_siz)-1; i++)
    {
        out = dequeue(ary,ary_siz);
//        cout<<"pop's out: "<<out<<endl;
        enqueue(ary,out,ary_siz);
//        print_queue(ary,ary_siz);
    }
    out = dequeue(ary,ary_siz);
    if(out == NULL)cout<<"stack empty"<<endl;
    return out;
}

int main()
{
    int in,out;
    int wsiz,rsiz;
    cout<<"input the size your stack need: ";
    cin>>wsiz;
    rsiz = wsiz+1;
    int ary[rsiz];
    string cmd;
    cout<<"input:\n[push X] for push X in the stack\n[pop] for pop the data from the stack."<<endl;
    while(cin>>cmd)
    {
//        cout<<"main's ary: "<<ary<<endl;
//        cout<<"main's *ary: "<<*ary<<endl;
//        cout<<"main's ary[1]: "<<ary[1]<<endl;
        if(cmd == "push")
        {
            cin>>in;
            //cout<<"ary in main: "<<ary<<endl;
            push(ary,in,rsiz);
            print_queue(ary,rsiz);
        }
        else if(cmd == "pop")
        {
            out = pop(ary,rsiz);
            if(out!=NULL)cout<<"pop "<<out<<" out"<<endl;
            print_queue(ary,rsiz);
        }
        else cout<<"wrong cmd input"<<endl;
    }

    return 0;
}
