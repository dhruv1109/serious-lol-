#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter a message less than 65536 (16 bits)";
    int M;
    cin>>M;
    int keys[16]; // for 16 rounds
    for(int i=0;i<=15;i++)
    {
        keys[i]=rand()%256;
    }
    int Lt,Rt;
    Lt=M;
    int Bin[16];
    for(int i=0;i<16;i++)
    {
        Bin[i]=0;
    }
    int curr=0;
    while(Lt>0)
    {
        if(Lt%2==1)
        {
            Bin[curr]=1;
        }
        Lt=Lt/2;
        curr++;
    }
    Lt=0;Rt=0;
    // divide in l & r (each 8 bit)
    int power=1;
    for(int i=0;i<8;i++)
    {
        if(Bin[i])
        {
            Rt+=power;
        }
        power*=2;
    }
    power=1;
    for(int i=8;i<16;i++)
    {
        if(Bin[i])
        {
            Lt+=power;
        }
        power*=2;
    }
    //Encryption Logic
    for(int i=0;i<=15;i++)
    {
        int temp=Rt;
        int f1=Rt^keys[i];
        Rt=f1^Lt;
        Lt=temp;
    }
    int enc=0;
    power=1;
    int l=Rt;int r=Lt;
    swap(Lt,Rt); 
    // making no 16 bit again
    while(r>0)
    {
        if(r%2==1)
        {
            enc+=power;
        }
        power*=2;
        r/=2;
    }
    while(l>0)
    {
        if(l%2==1)
        {
            enc+=power;
        }
        power*=2;
        l/=2;
    }
    cout<<"Encrypted number: "<<enc<<'\n';
    for(int i=15;i>=0;i--)
    {
        int temp=Rt;
        int f1=Rt^keys[i];
        Rt=f1^Lt;
        Lt=temp;
    }
    int dec=0;
    power=1;
    l=Rt;r=Lt;
    swap(Lt,Rt);
    while(r>0)
    {
        if(r%2==1)
        {
            dec+=power;
        }
        power*=2;
        r/=2;
    }
    while(l>0)
    {
        if(l%2==1)
        {
            dec+=power;
        }
        power*=2;
        l/=2;
    }
    cout<<"Decrypted number: "<<dec<<'\n';
    return 0;
}
