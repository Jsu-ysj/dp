/**
题目背景
现在乐斗有活动了！每打一个人可以获得5倍经验！absi2011却无奈的看着那一些比他等级高的好友，想着能否把他们干掉。干掉能拿不少经验的。

题目描述
现在absi2011拿出了x个迷你装药物(嗑药打人可耻….)，准备开始与那些人打了
由于迷你装一个只能管一次，所以absi2011要谨慎的使用这些药，悲剧的是，没到达最少打败该人所用的属性药了他打人必输>.
<所以他用2个药去打别人，别人却表明3个药才能打过，那么相当于你输了并且这两个属性药浪费了。
现在有n个好友，有输掉拿的经验、赢了拿的经验、要嗑几个药才能打过。求出最大经验（注意，最后要乘以5）.

输入格式
第一行两个数，n和x
后面n行每行三个数，分别表示输了拿到的经验(lose[i])、赢了拿到的经验(win[i])、打过要至少使用的药数量(use[i])。

输出格式
一个整数，最多获得的经验

样例1：            答案： 1060
6 8
21 52 1
21 70 5
21 48 2
14 38 3
14 36 1
14 36 2
**/

/**
  思路， 首先判断这是一种0/1背包题目。 但你有一点不同的是，可能会打赢也会打输，所以就要加个判断：
        1.能打赢
        if(j >= use[i]){
				dp[j] = max(dp[j]+lose[i], dp[j-use[i]] + win[i]);} 
        要看打赢好还是故意输好；
        2.打不赢
        dp[j] += lose[i];
        
        然后就是还要注意要开long long 型， 答案还要*5倍；
**/

//具体代码：
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
typedef long long ll;
ll lose[maxn], win[maxn], use[maxn], dp[maxn];
int main()
{
	int n, x;
	cin >> n >> x;
	for(int i = 1; i <= n; i ++){
		cin >> lose[i] >> win[i] >> use[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = x; j >= 0; j --){
			if(j >= use[i]){
				dp[j] = max(dp[j]+lose[i], dp[j-use[i]] + win[i]);
			}else{
				dp[j] += lose[i];
			}
		}
	}
	cout << 5*dp[x] << endl;
	return 0;
}
