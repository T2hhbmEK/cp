#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110;
int dp1[N][N*N],dp2[N][N*N];
int a[N],b[N],c[N];
int n;
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=n;i>=1;i--){
        memset(dp2,-0x3f,sizeof(dp2));
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=j*n;k++){
                if(dp1[j][k]>=0){
                dp2[j+1][k+i]=max(dp2[j+1][k+i],dp1[j][k]+a[i]);
                dp2[j][k]=max(dp2[j][k],dp1[j][k]+1ll*(k-j*i)*b[i]);
                dp2[j][k]=max(dp2[j][k],dp1[j][k]+1ll*j*c[i]);
                }
            }
        }
        swap(dp1,dp2);
    }
    int ans=-1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n*n;j++){
            ans=max(ans,dp1[i][j]);
        }
    }
    cout<<ans;
    return 0;
}