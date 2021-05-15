/**
题目简介：
As a part of the mission ‘Beautification of Dhaka City’, the government has decided to replace all the
old lampposts with new expensive ones. Since the new ones are quite expensive and the budget is not
up to the requirement, the government has decided to buy the minimum number of lampposts required
to light the whole city.
Dhaka city can be modeled as an undirected graph with no cycles, multi-edges or loops. There are
several roads and junctions. A lamppost can only be placed on junctions. These lampposts can emit
light in all the directions, and that means a lamppost that is placed in a junction will light all the roads
leading away from it.
The ‘Dhaka City Corporation’ has given you the road map of Dhaka city. You are hired to find
the minimum number of lampposts that will be required to light the whole city. These lampposts can
then be placed on the required junctions to provide the service. There could be many combinations of
placing these lampposts that will cover all the roads. In that case, you have to place them in such a
way that the number of roads receiving light from two lampposts is maximized.

Input
There will be several cases in the input file. The first line of input will contain an integer T (T ≤ 30)
that will determine the number of test cases. Each case will start with two integers N (N ≤ 1000)
and M (M < N) that will indicate the number of junctions and roads respectively. The junctions are
numbered from 0 to N − 1. Each of the next M lines will contain two integers a and b, which implies
there is a road from junction a to b, (0 ≤ a, b < N) and a ̸= b. There is a blank line separating two
consecutive input sets.

Output
For each line of input, there will be one line of output. Each output line will contain 3 integers, with
one space separating two consecutive numbers. The first of these integers will indicate the minimum
number of lampposts required to light the whole city. The second integer will be the number of roads
that are receiving lights from two lampposts and the third integer will be the number of roads that are
receiving light from only one lamppost.

Sample Input
2
4 3
0 1
1 2
2 3
5 4
0 1
0 2
0 3
0 4
Sample Output
2 1 2
1 0 4
**/

/**
思路：
这是一个与A_A题相似的题；
每个点有两种状态：
1.放灯 
2.不放灯
但是题目还有一个要求：还要求被两盏灯照亮的灯最多
即： 上面点放灯，下面点也放灯的情况要多；
因此还要一点特殊才处理： 满足放灯的点初始值为> 1000即可
这样数组大得到的要求的路越多；最后在除一下就好：
void dfs(int node){
	vis[node] = 1;
	dp[node][0] = 0;
	dp[node][1] = N;
	int len = G[node].size();
	for(int i = 0; i < len; i ++){
		int son = G[node][i];
		if(vis[son])
			continue;
		dfs(son);
		dp[node][0] += dp[son][1]+1;
		if(dp[son][1]>dp[son][0]){
			dp[node][1] += dp[son][0]+1;
		}else{
			dp[node][1] += dp[son][1];
		}
	}
}
**/

// 具体代码：
#include<bits/stdc++.h>
using namespace std;
const int N  = 1000 + 10;
vector<int > G[N];
int dp[N][2];
int vis[N];

void dfs(int node){
	vis[node] = 1;
	dp[node][0] = 0;
	dp[node][1] = N;
	int len = G[node].size();
	for(int i = 0; i < len; i ++){
		int son = G[node][i];
		if(vis[son])
			continue;
		dfs(son);
		dp[node][0] += dp[son][1]+1;
		if(dp[son][1]>dp[son][0]){
			dp[node][1] += dp[son][0]+1;
		}else{
			dp[node][1] += dp[son][1];
		}
	}
}
int main(){
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i ++){
			dp[i][0] = dp[i][1] = vis[i] = 0;
			G[i].clear();				
		}
		for(int i = 1; i <= m; i ++){
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int ans = 0;
		for(int i = 0; i < n; i ++){
			if(!vis[i]){
				dfs(i);
				ans += min(dp[i][0],dp[i][1]);
			}
		}
		printf("%d %d %d\n", ans/N, m-ans%N, ans%N);
	}
	return 0;
}
