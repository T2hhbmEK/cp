#include<bits/stdc++.h>
//"www.luogu.com.cn/problem/P1167" 
using namespace std;
#define int long long
struct date_time{
	int year,month,day,hour,minute;
	bool is_leap(int Nian){
		if(Nian%4==0&&Nian%100!=0) return true;
		if(Nian%400==0) return true;
		return false;
	}
	int getMonthDay(int Year,int Month){
		if(Month==2){
			if(is_leap(Year)) return 29;
			else return 28;
		}
		if(Month==4||Month==6||Month==9||Month==11){
			return 30;
		}
		return 31; 
	}
	int f(int year,int month,int day,int hour,int minute){
		int ans=0;
		for(int i=1;i<year;i++){
			if(is_leap(i)) ans+=366*24*60;
			else ans+=365*24*60;
		}
		for(int i=1;i<month;i++){
			ans+=getMonthDay(year,i)*24*60;
		}
		ans+=(day-1)*24*60;
		ans+=hour*60+minute*1;
//        return ans;
	}
}bg,ed;
int n,a[5010],T,ans;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	scanf("%lld-%lld-%lld-%lld:%lld",&bg.year,&bg.month,&bg.day,&bg.hour,&bg.minute);
	scanf("%lld-%lld-%lld-%lld:%lld",&ed.year,&ed.month,&ed.day,&ed.hour,&ed.minute);
//	cout<<ed.f(ed.year,ed.month,ed.day,ed.hour,ed.minute)<<' '<<bg.f(bg.year,bg.month,bg.day,bg.hour,bg.minute)<<endl;
	T=ed.f(ed.year,ed.month,ed.day,ed.hour,ed.minute)-bg.f(bg.year,bg.month,bg.day,bg.hour,bg.minute);
//	cout<<T<<endl;
	for(int i=1;i<=n;i++){
		if(T>=a[i]){
			ans++;
			T-=a[i];
		}else{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

