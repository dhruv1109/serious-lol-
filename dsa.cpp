#include<bits/stdc++.h>  
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{   int n,m;
	    int a[n],b[m];
	    cin>>n>>m;
	    vector <int> v;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	         bool present = binary_search(v.begin(),v.end(),a[i]);
	         if(!present)
	         v.push_back(a[i]);
	    }
	    for(int i=0;i<m;i++)
	    {
	        cin>>b[i];
	         bool present = binary_search(v.begin(),v.end(),b[i]);
	         if(!present)
	         v.push_back(b[i]);
	    }
	     cout<<v.size()<<endl;
         
	}
	return 0;
}
