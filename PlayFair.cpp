#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pt,key;
    cout<<"Enter Plain Text ";
    cin>>pt;
    cout<<"Enter key ";
    cin>>key;
    char pf[5][5];
    int length=0;
    set<char> taken;
    int row=0,col=0;
    while(length<key.size())
    {
        if(col==5)
        {
            col=0;
            row++;
        }        
        char temp=key[length++];
        if(temp=='J')
            temp='I';
        if(taken.count(temp)==0)
        {
            pf[row][col++]=temp;
            taken.insert(temp);
        }      
    }
    int i=row;
    int j=col;
    for(char c='A';c<='Z';c++)
    {
        if(c=='J' || taken.count(c)>0)
            continue;
        else
        {
            if(j==5)
            {
                i++;
                j=0;
            }
            pf[i][j++]=c;
        }
    }
    cout<<"Cipher matrix is "<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<pf[i][j]<<" ";

        }
        cout<<endl;
    }
    
    vector<pair<char,char>>op;
    length=0;
    int id=0;
    while(length!=pt.size())
    {
        char curr=pt[length++];
        if(curr=='J')
            curr='I';

        if(length==pt.size())
        {
            op.push_back({curr,'X'});
            break;
        }
        char next=pt[length];
        if(next=='J')
            next='I';
        
        if(curr!=next)
        {
            op.push_back({curr,next});
            length++;
        }
        else
        {
            op.push_back({curr,'X'});
        }
    }
    cout<<"The pairs of plain text are"<<endl;
    for(auto x:op)
        cout<<x.first<<" "<<x.second<<endl;

    int pos[26][2];
    bool out=false;
    for(int i=0;i<26;i++)
    { 
        out=false;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                char x =65;
                x=x+i;
                if(pf[j][k]==x)
                {
                    pos[i][0]=j;
                    pos[i][1]=k;
                    out=true;
                    break;
                }
            }
            if(out)
                break;
        }
    }

    string ct="";
    for(auto x : op)
    {
        int x1=(int)(x.first)-65;
        int x2=(int)(x.second)-65;
        if(pos[x1][0]==pos[x2][0])
        {
            int col1=(pos[x1][1]+1)%5;
            int col2=(pos[x2][1]+1)%5;
            ct = ct + pf[pos[x1][0]][col1];
            ct = ct + pf[pos[x1][0]][col2];
        }
        else if(pos[x1][1]==pos[x2][1])
        {
            int row1=(pos[x1][0]+1)%5;
            int row2=(pos[x2][0]+1)%5;
            ct = ct + pf[row1][pos[x1][1]];
            ct = ct + pf[row2][pos[x2][1]];
        }
        else
        {
            int r1=pos[x1][0];
            int r2=pos[x2][0];
            int c1=pos[x1][1];
            int c2=pos[x2][1];
            ct = ct + pf[r1][c2];
            ct = ct + pf[r2][c1];
        }
    }
    cout<<"Encripted Text is "<<ct<<endl;

    string dec="";
    for(int i=0;i<ct.length();i=i+2)
    {
        char a=ct[i];
        char b=ct[i+1];
        int x1=a-65;
        int x2=b-65;
        if(pos[x1][0]==pos[x2][0])
        {
            int col1=(pos[x1][1]-1)%5;
            if(col1<0)
                col1+=5;
            int col2=(pos[x2][1]-1)%5;
            if(col2<0)
                col2+=5;
            dec = dec + pf[pos[x1][0]][col1];
            dec = dec + pf[pos[x1][0]][col2];
        }
        else if(pos[x1][1]==pos[x2][1])
        {
            int row1=(pos[x1][0]-1)%5;
            if(row1<0)
                row1+=5;
            int row2=(pos[x2][0]-1)%5;
            if(row2<0)
                row2+=5;
            dec = dec + pf[row1][pos[x1][1]];
            dec = dec + pf[row2][pos[x2][1]];
        }
        else
        {
            int r1=pos[x1][0];
            int r2=pos[x2][0];
            int c1=pos[x1][1];
            int c2=pos[x2][1];
            dec = dec + pf[r1][c2];
            dec = dec + pf[r2][c1];
        }
    }
    cout<<"Decripted Text is "<<dec<<endl;
}