#include<iostream>
using namespace std;

int fib_iteration(int n)
{
    int i,temp;
    //initialize f(0) and f(1)
    int a=0,b=1;
    for(i=2; i<=n; i++)
    {
        temp = a+b;
        a=b;
        b=temp;
    }
    if(n==0)return 0;
    else if(n==1)return 1;
    else
        return b;
}

int fib_recursive(int n)
{
    if(n==0)return 0;
    else if(n==1)return 1;
    else
        return fib_recursive(n-1)+fib_recursive(n-2);
}


int main()
{
    int in,out_iteration,out_recursive;
    cout<<"input n for fib(n): ";
    while(cin>>in)
    {
        out_iteration = fib_iteration(in);
        cout<<"Ans of iteration edition: "<<out_iteration<<endl;
        out_recursive = fib_recursive(in);
        cout<<"Ans of recursive edition: "<<out_recursive<<endl;
        cout<<"input n for fib(n): ";
    }

    return 0;
}
