#include<iostream>
using namespace std;

long long int fac_iteration(int n)
{
    int i;
    //initialize
    long long int ans=1;
    for(i=2; i<=n; i++)
        ans*=i;
    if(n == 0)return 1;
    else return ans;
}

long long int fac_recursive(long long int n)
{
    if(n==0)return 1;
    else return n*fac_recursive(n-1);
}


int main()
{
    int in;
    long long int out_iteration,out_recursive;
    cout<<"input n for fac(n): ";
    while(cin>>in)
    {
        out_iteration = fac_iteration(in);
        cout<<"Ans of iteration edition: "<<out_iteration<<endl;
        out_recursive = fac_recursive(in);
        cout<<"Ans of recursive edition: "<<out_recursive<<endl;
        cout<<"input n for fac(n): ";
    }


    return 0;
}
