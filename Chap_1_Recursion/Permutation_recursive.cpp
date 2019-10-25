#include<iostream>
using namespace std;

char abc[4]={'0','a','b','c'};
void SWAP(int i,int j)
{
    int temp;
    temp = abc[i];
    abc[i] = abc[j];
    abc[j] = temp;
}
void Permutation(int i,int n)
{
    int j;
    if(i==n)
    {
        for(j=1;j<=n;j++)
            cout<<abc[j];
        cout<<endl;
    }
    else
    {
        for(j=i;j<=n;j++)
        {
            SWAP(i,j);//abc[j] as head, i.e.,swap(abc[i],abc[j])
            Permutation(i+1,n);//head is determined, so the problem become permutation of abc[i+1]~abc[n]
            SWAP(i,j);//swap again to get back to origin list
        }
    }
    //after every single Permutation process is ended, it will return to it's caller Permutation process
}

int main()
{
    cout<<"All the possible permutation of abc:"<<endl;
    Permutation(1,3);
    return 0;
}
