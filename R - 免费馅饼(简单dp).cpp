/**
最近阿彭的股票一片绿，本着大跌就是加仓信号的原则，阿彭急需一大笔资金投入股票市场。

上帝可能可怜阿彭的不切实际想法，给了他一场白日梦，即白日做梦之捡钞票游戏。

捡钞票游戏是这样的，钞票从天上往下掉，且只会掉在 [0, 10] 范围内，具体的坐标范围如下图所示。


阿彭初始站在位置5上，且每秒只能在移动不超过1米的范围内接住掉落的钞票，如果没有接住，钞票就会消失。
例如，在刚开始的一秒内，阿彭 只能接到4、5、6这三个位置其中一个位置的钞票。

阿彭想要接住尽可能多的钞票（钞票面额相同），你能帮帮他吗？

Input
多组样例。每组样例输入一个 m (0 < m < 100000)，表示有 m 张钞票。

在接下来的 m 行中，每行有两个整数 a b (0 < b < 100000)，表示在第 b 秒的时候有一张钞票掉落在 a 点上。

注意，同一个点上同一秒可能掉落多张钞票。m = 0 时输入结束。

C++ 注意文件头不能使用 bits/stdc++.h，G++可以使用

java 类名 注意使用成 Main

Output
输出一个整数 x，表示阿彭 可能接住的最多的钞票数。

Sample Input
6
5 1
4 1
6 1
7 2
7 2
8 3
0
Sample Output
4
**/

/**
思路 ：
这道题目是数塔的变形_总共有有三种状态
当在最边上时则单独考虑就可以了
**/

//具体代码：
#include<bits/stdc++.h>
using namespace std;
int dp[11][100005];
int Map[11][100005];
int main() {
	int n;
	while(cin >> n && n != 0) {
		memset(dp,0,sizeof(dp));
		memset(Map,0,sizeof(Map));
		int m=0;
		int id,t;
		for(int i=0; i<n; i++) {
			cin >> id >> t;
			Map[id][t]++;
			m=max(m,t);
		}
		int k,ans=-1;
		for(int i=1; i<=m; i++) {
			for(k=0; k<=10; k++) {
				dp[k][i]=dp[k][i-1];
				if(k>=1){
					dp[k][i]=max(dp[k][i],dp[k-1][i-1]);	
				}
				if(k<=9){
					dp[k][i]=max(dp[k][i],dp[k+1][i-1]);
				} 
				if(i>=abs(k-5))
					dp[k][i]+=Map[k][i];
			}
		}
		for(int k=0; k<=10; k++)
			ans=max(dp[k][m],ans);
		cout << ans << endl;
	}
	return 0;
}
