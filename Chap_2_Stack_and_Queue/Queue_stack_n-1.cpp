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
    rsize = wsize+1;//實際的arraysize要比可用的多一，因為被start指到的那格不存放data
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
