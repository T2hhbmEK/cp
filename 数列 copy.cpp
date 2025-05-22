#include<bits/stdc++.h>
using namespace std;
#define e7 10000005
int arry[e7]; 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&arry[i]);
	}
	int l=arry[1],r=0;
	for(int i=1;i<=n;i++){
		if(arry[i]>=l)l=arry[i];
		else if(arry[i]>r)r=arry[i];
	}
	int flag=0,ans=0;
	for(int i=1;i<=n;i++){
		if(arry[i]<r)ans++;
		else if(arry[i]==r){
			flag++;
		}
	}
	int i=1;
	while(arry[i]>r&&i<=n){if(arry[i]==r)flag--;i++;}
	cout<<ans+flag;
	return 0;
}
