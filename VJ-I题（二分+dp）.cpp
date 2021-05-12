/**
从列中删除任意数量的任意整数，并获取该数字列的最大长度，以创建单调增加的数列。
‎约束‎
1≤N≤100000;
样例 1
5
3 1 5 4 2
答案1
2
**/

/**
错误思路：
    这一看就是最长上升子序列，非常简繁单：      
**/
#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int dp[maxn];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i ++){
		dp[i]=1;
		for(int j = i-1; j >= 1; j --){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n ; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans  << endl;
	return 0;
}

//但是后面时间超限几次， 发现没有这么简单了：

/**
正确思路：
  要用到二分+dp才可以过；
  很简单，把dp数组看成是一个栈就好了；
  当然还有一点其他操作：
   k = lower_bound(dp+1, dp+top+1, a[i])-dp;
   替换元素：
**/

//正确代码：
#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int dp[maxn];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
	}
	int top = 1;
	dp[top] = a[1];
	for(int i = 2; i <= n; i ++){
		if(a[i] > dp[top]){
			dp[++top] = a[i];
		}else{
			int k = lower_bound(dp+1, dp+top+1, a[i])-dp;
			dp[k] = a[i];
		}
	}
	cout << top  << endl;
	return 0;
}
