#include<iostream>
#include<vector> 
#include<queue>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	vector<int> a;
	a.resize(n);
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x)
		{
			x = a[i];
		}
		else
		{
			y = i - 1;
			break;
		}
	}
	int max = 0;
	for (int i = y + 1; i < n; i++)
	{
		if (a[i] < x)
		{
			ans++;
			if(a[i] > max)
			{
				max = a[i];
			}
		}
	}
	if(y!=0)
	{
		for (int i = 0; i < y; i++)
		{
			if (a[i] < max)
			{
				ans++;
			}
		}
	}
	cout <<ans<< endl;
}
