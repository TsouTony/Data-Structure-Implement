#include<iostream>
using namespace std;


long long int Pow(int x,int y)
{
    if(y==1)return x;
    else return x*Pow(x,y-1);
}

int main()
{
    int x,y;
    long long int ans;
    cout<<"input x,y for x^y: ";
    while(cin>>x>>y)
    {
        ans = Pow(x,y);
        cout<<x<<"^"<<y<<" is: "<<ans<<endl;
        cout<<"input x,y for x^y: ";
    }
    return 0;
}
