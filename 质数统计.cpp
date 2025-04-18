#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e9+7;
const int N=1e6+10;
int p[4010],cnt[N*10];
bool book[N*10];
int n,a[N],tot,m,maxx=-1;
void pre(int x){
    book[1]=1;
    for(int i=2;i<=x;i++){
        if(!book[i]){
            p[++tot]=i;
        }
        for(int j=1;j<=tot&&i*p[j]<=x;j++){
            book[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    for(int i=1;i<=tot;i++){
        for(int j=1;j<=n;j++){
            if(a[j]%p[i]==0){
                cnt[p[i]]++;
            }
        }
    }
//for(int i=1;i<=x;i++)cout<<cnt[i]<<" ";
//    cout<<endl;
    for(int i=1;i<=x;i++){
        cnt[i]+=cnt[i-1];
        cnt[i]%=P;
    }
       
}
signed main(){
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    std::ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    pre(maxx);
    while(m--){
        int l,r;
        cin>>l>>r;
        if(r>maxx){
            r=maxx;
        }
        cout<<cnt[r]-cnt[l-1]<<"\n";
    }
    return 0;
}
