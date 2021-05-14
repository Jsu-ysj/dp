/**
思路： 这个题是一个简单的模板题；
       1.建立一个动态二维数组存下每一个人的上司
       2.遍历每一个人的每一个上司情况：
       无一有两种情况：去或不去， 有时候有个人去了，那么他的上司就不能能去，就只有一种境况，
       用dp[maxn][2]，第二个数用下标0/1来表示去或不去；
       for(int i = 0; i < len; i ++){
		     int v = g[u][i];
		     dp(v);
		     f[u][1] += f[v][0];
		     f[u][0] += max(f[v][1], f[v][0]);
	      }
**/


//具体代码：
#include<bits/stdc++.h>
using namespace std;
const int maxn = 6000 + 100;
vector <int > g[maxn];
int f[maxn][2];
int p[maxn];
int a[maxn];
int n, rt;

void dp(int u){
	int len = g[u].size();
	f[u][1] = a[u];
	for(int i = 0; i < len; i ++){
		int v = g[u][i];
		dp(v);
		f[u][1] += f[v][0];
		f[u][0] += max(f[v][1], f[v][0]);
	}
}
int main(){
	while(cin >> n){
		for(int i = 1; i <= n; i ++){
			f[i][1] = f[i][0] = 0;
			p[i] = 0;
			g[i].clear();
		}
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 1; i < n; i ++){
			int v, u;
			cin >> v >> u;
			p[v] = u;
			g[u].push_back(v);
		}
		int end1, end2;
		cin >> end1 >> end2;
		for(int i = 1; i <= n; i ++){
			if(!p[i]){
				rt = i;
				break;
			}
		}
		dp(rt);
		cout << max(f[rt][1], f[rt][0]) << endl;
	}
	return 0;
}
