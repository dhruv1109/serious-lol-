#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

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
    int a,b,m=26;
    cout<<" Enter value of a and b ";
    cin>>a>>b;
    cout<<"Plain Text is "<<pt<<endl;
    if(gcd(a,m)==1)
    {
        cout<<"a and m are coprime"<<endl;
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
            n=((a*n)+b)%m;
            ct=ct+d[n];
        }
        cout<<"Encripted Text is "<<ct<<endl;
        int a_inv=0;
        for(int i=0;i<26;i++)
        {
            if((a*i)%26==1)
                a_inv=i;
        }
        for(int i=0;ct[i]!='\0';i++)
        {
            char x;
            x=ct[i];
            int n=x-65;
            if(n-b<0)
            {
                int a=NegMod(n-b,m);
                n=(a_inv*a)%m;
            }
            else
            {
                n=(a_inv*((n-b)%m))%m;
            }
            dec=dec+d[n];
        }
        cout<<"Decripted Text is "<<dec<<endl;
    }
    else
    {
        cout<<"ERROR !! a and m must be coprime";
    }
    return 0;
}