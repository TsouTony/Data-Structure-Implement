#include<vector>
#include<iostream>
#include<string>
using namespace std;
vector<char> BT;

void preorder(int r)
{
    if(r<BT.size())
    {
        cout<<BT[r]<<" ";
        preorder(2*r);
        preorder(2*r+1);
    }
}
void inorder(int r)
{
    if(r<BT.size())
    {
        inorder(2*r);
        cout<<BT[r]<<" ";
        inorder(2*r+1);
    }
}
void postorder(int r)
{
    if(r<BT.size())
    {
        postorder(2*r);
        postorder(2*r+1);
        cout<<BT[r]<<" ";
    }
}
int main()
{
    string in;
    int i,type;

    BT.push_back('r');
    getline(cin,in);
    for(i=0; i<in.size(); i++)
        if(in[i]!=' ')
            BT.push_back(in[i]);
    for(i=0; i<BT.size(); i++)
        cout<<BT[i]<<" ";
    cout<<endl;
    cout<<"1: preorder"<<endl;
    cout<<"2: inorder"<<endl;
    cout<<"3: postorder"<<endl;

    while(1)
    {
        cout<<"input the type of traversal: ";
        cin>>type;
        switch(type)
        {
        case 1:
            preorder(1);
            cout<<endl;
            break;
        case 2:
            inorder(1);
            cout<<endl;
            break;
        case 3:
            postorder(1);
            cout<<endl;
            break;
        }
    }
    return 0;
}
