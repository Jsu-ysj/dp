/**
题目描述
辰辰是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

如果你是辰辰，你能完成这个任务吗？

输入格式
第一行有 22 个整数 TT（1 \le T \le 10001≤T≤1000）和 MM（1 \le M \le 1001≤M≤100），用一个空格隔开，TT 代表总共能够用来采药的时间，MM 代表山洞里的草药的数目。

接下来的 MM 行每行包括两个在 11 到 100100 之间（包括 11 和 100100）的整数，分别表示采摘某株草药的时间和这株草药的价值。

输出格式
输出在规定的时间内可以采到的草药的最大总价值。

输入输出样例
70 3
71 100
69 1
1 2

输出 ：3
 **/
 
 //这就是一个简单的0/1dp, 很简单的！！！

//核心代码：
​
for(int i = 1; i <= m; i ++){
		for(int j = t; j >= tmp[i].time; j --){
			dp[j] = max(dp[j], dp[j - tmp[i].time] + tmp[i].value);
		}
	}
​

//具体代码：
​
#include<bits/stdc++.h>
using namespace std;

struct node{
	int value;
	int time;
}tmp[1001];
int dp[1001] = {0};
int main()
{
	int t, m;
	cin >> t >> m;
	for(int i = 1; i <= m; i ++){
		cin >> tmp[i].time >> tmp[i].value;
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= m; i ++){
		for(int j = t; j >= tmp[i].time; j --){
			dp[j] = max(dp[j], dp[j - tmp[i].time] + tmp[i].value);
		}
	}
	cout << dp[t] << endl;

}

​
