#include<iostream>
using namespace std;


int Ack(int m,int n)
{
    if(m==0)return n+1;
    else if(n==0)return Ack(m-1,1);
    else return Ack(m-1,Ack(m,n-1));
}

int main()
{
    int m,n;
    int ans;
    cout<<"input m,n for Ack(m,n): ";
    while(cin>>m>>n)
    {
        ans = Ack(m,n);
        cout<<"Ack("<<m<<","<<n<<") is: "<<ans<<endl;
        cout<<"input m,n for Ack(m,n): ";
    }
    return 0;
}
