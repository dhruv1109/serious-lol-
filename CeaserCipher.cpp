#include<bits/stdc++.h>
using namespace std;

int NegMod(int x,int m)
{
    int q=2;
    int r=x+m;
    while(r<0)
    {
        r=x+(q*m);
        q++;
    }
    return r;
}

int main()
{
    string pt;
    cout<<" Enter Plain Text ";
    cin>>pt;
    string ct="";
    string dec="";
    int m=26;
    cout<<"Plain Text is "<<pt<<endl;
    
    map<int,char> d;
    char x=65;
    for(int i=0;i<26;i++)
    {
        d.insert({i,x});
        x++;
    }
    for(int i=0;pt[i]!='\0';i++)
    {
        char x;
        x=pt[i];
        int n=x-65;
        n=(n+3)%m;
        ct=ct+d[n];
    }
    cout<<"Encripted Text is "<<ct<<endl;
    for(int i=0;ct[i]!='\0';i++)
    {
        char x;
        x=ct[i];
        int n=x-65;
        if(n-3<0)
        {
            n=NegMod(n-3,m);
        }
        else
        {
            n=(n-3)%m;
        }
        dec=dec+d[n];
    }
    cout<<"Decripted Text is "<<dec<<endl;
    return 0;
}