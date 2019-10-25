#include<iostream>
using namespace std;


int GCD(int n,int m)
{
    if(n%m==0)return m;
    else return GCD(m,n%m);
}

int main()
{
    int n,m;
    int ans;
    cout<<"input n,m for GCD(m,n): ";
    while(cin>>n>>m)
    {
        ans = GCD(n,m);
        cout<<"GCD("<<n<<","<<m<<") is: "<<ans<<endl;
        cout<<"input n,m for GCD(m,n): ";
    }
    return 0;
}
