#include<iostream>
using namespace std;

int start = 0, rear = 0;


int queue_length(int ary_siz)
{
    //�Yrear > start�A�h (rear - start + ary_siz) % ary_siz = rear-start (�]��rear-start < n)
    //���Brear - start �Y�� array �����s��data(i.e.,queue����)����l�Ӽ�
    //�Yrear < start�A�h (rear - start + ary_siz) % ary_siz = rear -start + ary_siz (�]�� rear - start +ary_siz < n)
    //���Brear - start �Y�� array ���S���s��data����l�Ӽƪ��t�ȡA�ҥH���t�ȥ[�Wary_siz�Y����data����l�Ӽ�
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
    cout<<"current start: "<<start<<" ,current rear: "<<rear<<endl;
    return;
}

int dequeue(int* ary,int ary_siz)
{
    int out;
    if(start == rear)
    {
        cout<<"queue empty"<<endl;
        out = NULL;
    }
    else
    {
        out = ary[start];
        start = (start+1)%ary_siz;
    }
    cout<<"current start: "<<start<<" ,current rear: "<<rear<<endl;
    return out;

}

int main()
{
    int wsize,rsize,in,out;
    int i;
    cout<<"input the size your queue need: ";
    cin>>wsize;
    rsize = wsize+1;//��ڪ�arraysize�n��i�Ϊ��h�@�A�]���Qstart���쪺���椣�s��data
    int ary[rsize];
    string cmd;
    cout<<"input [enqueue X] for put X in the rear of queue and [dequeue] for delete the data from the front of queue."<<endl;
    while(cin>>cmd)
    {
        if(cmd == "enqueue")
        {
            cin>>in;
            enqueue(ary,in,rsize);
            print_queue(ary, rsize);
            cout<<"current queue length: "<<queue_length(rsize)<<endl;
        }
        else if(cmd == "dequeue")
        {
            out = dequeue(ary,rsize);
            print_queue(ary, rsize);
            cout<<"current queue length: "<<queue_length(rsize)<<endl;
        }
        else cout<<"wrong cmd"<<endl;
    }

    return 0;
}
