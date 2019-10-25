#include<iostream>
using namespace std;

int steps;
void Hainoi(int n,char from,char mid,char to)
{
    if(n==1)
    {
        cout<<"move the top from "<<from<<" to "<<to<<endl;
        steps++;
    }
    else
    {
        Hainoi(n-1,from,to,mid);
        Hainoi(1,from,mid,to);
        Hainoi(n-1,mid,from,to);
    }
}

int main()
{
    int n;
    char from,mid,to;
    cout<<"input n,from,mid,to to show the stop of moving Hainoi Tower: ";
    while(cin>>n>>from>>mid>>to)
    {
        steps = 0;
        Hainoi(n,from,mid,to);
        cout<<"Total steps: "<<steps<<endl;
        cout<<"input n,from,mid,to to show the stop of moving Hainoi Tower: ";
    }
    return 0;
}
