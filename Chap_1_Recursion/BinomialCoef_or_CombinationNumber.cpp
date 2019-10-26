#include<iostream>
using namespace std;

long long int BinCoef(int n, int m)
{
    if(n<=m)return 1;
    else if(m==0)return 1;
    else
        return BinCoef(n-1,m-1)+BinCoef(n-1,m);//n中固定一物討論拿or不拿之情況
}

int main()
{
    int n,m;
    long long int ans;
    cout<<"input n,m for C(n,m): ";
    while(cin>>n>>m)
    {
        ans = BinCoef(n,m);
        cout<<"C("<<n<<","<<m<<") is: "<<ans<<endl;
        cout<<"input n,m for Cnm: ";
    }
    return 0;
}
