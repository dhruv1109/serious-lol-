#include<bits/stdc++.h>
using namespace std;

int pow(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;

    int ans=pow(a,b/2);
    if(b%2==0)
        return ans*ans;
    else
        return a*ans*ans;
}

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

int main()
{
    int m,p,q;
    cin>>m>>p>>q;
    cout<<"Message "<<m<<endl;
    cout<<"p : "<<p<<" "<<"q : "<<q<<endl;
    int n=p*q;
    int fi=(p-1)*(q-1);
    int e=2;
    while(e<fi)
    {
        if(gcd(e,fi)==1)
            break;
        else
            e++;
    }
    cout<<"e "<<e<<endl;
    int e_inv=0;
    for(int i=0;i<fi;i++)
    {
        if((e*i)%fi==1)
            e_inv=i;
    }
    int d=e_inv%fi;  
    cout<<"d "<<d<<endl;
    int c=pow(m,e);
    c=c%n;
    cout<<"CIPHER TEXT IS "<<c<<endl;
    int pt=pow(c,d);
	pt=pt%n;
    cout<<"PLAIN TEXT IS "<<pt<<endl;   
}
