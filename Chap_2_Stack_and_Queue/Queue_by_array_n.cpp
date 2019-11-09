#include<iostream>
using namespace std;

int start = 0, rear = 0;


int queue_length(int ary_siz,bool flag)
{
    //�Yrear > start�A�h (rear - start + ary_siz) % ary_siz = rear-start (�]��rear-start < n)
    //���Brear - start �Y�� array �����s��data(i.e.,queue����)����l�Ӽ�
    //�Yrear < start�A�h (rear - start + ary_siz) % ary_siz = rear -start + ary_siz (�]�� rear - start +ary_siz < n)
    //���Brear - start �Y�� array ���S���s��data����l�Ӽƪ��t�ȡA�ҥH���t�ȥ[�Wary_siz�Y����data����l�Ӽ�
    int i;
    if(start == rear)
        if(flag == true)return ary_siz;
        else return 0;
    else return (rear - start + ary_siz)%ary_siz;
}
void print_queue(int* ary,int ary_siz,bool flag)
{
    int i,j=start;
    cout<<"current queue is: ";
    for(i=0;i<queue_length(ary_siz,flag);i++)
    {
        cout<<ary[j]<<" ";
        j=(j+1)%ary_siz;
    }
    cout<<endl;
}

void enqueue(int* ary, int in,int ary_siz,bool* flag)
{
    if(rear == start && *flag == true)
    {
        cout<<"queue full"<<endl;
    }
    else
    {
        ary[rear] = in;
        rear = (rear+1)%ary_siz;
        if(rear == start)
            *flag = true;
//        cout<<"enqueue successfully"<<endl;
    }
    cout<<"current start: "<<start<<" ,current rear: "<<rear<<endl;
    return;
}

int dequeue(int* ary,int ary_siz,bool* flag)
{
    int out;
    if(start == rear && *flag == false)
    {
        cout<<"queue empty"<<endl;
        out = NULL;
    }
    else
    {
        out = ary[start];
        start = (start+1)%ary_siz;
        if(start == rear)
            *flag = false;
    }
    cout<<"current start: "<<start<<" ,current rear: "<<rear<<endl;
    return out;

}

int main()
{
    int siz,in,out;
    int i;
    bool flag=false;//flag true: queue full, flat flase: queue empty
    cout<<"input the size your queue need: ";
    cin>>siz;
    int ary[siz];
    string cmd;
    cout<<"input [enqueue X] for put X in the rear of queue and [dequeue] for delete the data from the front of queue."<<endl;
    while(cin>>cmd)
    {
        if(cmd == "enqueue")
        {
            cin>>in;
            enqueue(ary,in,siz,&flag);
            print_queue(ary, siz,flag);
            cout<<"current queue length: "<<queue_length(siz,flag)<<endl;
        }
        else if(cmd == "dequeue")
        {
            out = dequeue(ary,siz,&flag);
            print_queue(ary, siz, flag);
            cout<<"current queue length: "<<queue_length(siz,flag)<<endl;
        }
        else cout<<"wrong cmd"<<endl;
    }

    return 0;
}

