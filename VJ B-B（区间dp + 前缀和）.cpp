/**
题目简介：：
　zuojiliuchang与yejinmingcuc在玩一个游戏。
　他们先各自写下一串字符，然后互相展示。展示过后，他们再从自己写的那串字符中依次挑出若干字符（保持原有顺序不变），组成新的一串。
  他们希望自己新组成的字符串与对方新组成的完全相同，并且尽可能长。

　　例如，zuojiliuchang写下abcde，yejinmingcuc写下aeiou，然后zuojiliuchang挑出自己那串里的第1和第5个字符组成新串ae，
     yejinmingcuc挑出自己那串中的第1、2个字符，也组成字符串ae。ae就是他们能共同挑出的最长串。
　　现在，zuojiliuchang和yejinmingcuc分别写出了自己的字符串，请帮他们算一下他们能共同挑出组成的字符串最长有多长。

Input
　　输入包含多组数据，处理至文件结尾。
　　每组数据占一行，包括以空格分隔的两个字符串，分别是zuojiliuchang和yejinmingcuc写下的字符串。两个字符串长度都在1000以内。
Output
　　对于每组输入，输出一个整数，即他们能共同挑出组成的字符串的最大长度。
  
  样例：
  abcfbc abfcab
  programming contest 
  abcd mnp
  答案：
  4
  2
  0
**/

/**
思路：
题目比较简单，就是一个区间dp模板：
1.用一个Hash[maxn]数组来存前缀和， 方便计算、Hash[i] = Hash[i-1] + tmp;
2.找到动态转移方程：min_dp[i][i+k] = min(min_dp[i][i+k], min_dp[i][j]+min_dp[j+1][i+k] + Hash[i+k]-Hash[i-1]);
3.最大相同与上差不多：max_dp[i][i+k] = max(max_dp[i][i+k], max_dp[i][j]+max_dp[j+1][i+k] + Hash[i+k]-Hash[i-1]);
4.节省时间，可以把优化与dp方在一起，把求小于求大放在一起：
for(int k = 1; k < n; k ++ ){ //更新合并的组数
			for(int i = 1; i <= n - k; i ++){ // 更新每一列
				 min_dp[i][i+k] = inf;
				 max_dp[i][i+k] = -1;
				/**
				将他们初始化， 方便比较更新值
				**/  
				for(int j = i; j + 1 <= i + k; j ++){//遍历更新中间值
					min_dp[i][i+k] = min(min_dp[i][i+k], min_dp[i][j]+min_dp[j+1][i+k] + Hash[i+k]-Hash[i-1]);
					max_dp[i][i+k] = max(max_dp[i][i+k], max_dp[i][j]+max_dp[j+1][i+k] + Hash[i+k]-Hash[i-1]);
				} 
			}
		}
**/
  
  // 具体代码：
  #include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int inf = 1e9;
int min_dp[maxn][maxn];
int max_dp[maxn][maxn];
int Hash[maxn];

int main()
{
	int n;
	while(cin >> n){
		memset(Hash, 0, sizeof(Hash));
		for(int i = 1; i <= n; i ++){
			int tmp;
			cin >> tmp;
			Hash[i] = Hash[i-1] + tmp;
		} // 利用类似哈希来存值
			
		for(int k = 1; k < n; k ++ ){ //更新合并的组数
			for(int i = 1; i <= n - k; i ++){ // 更新每一列
				 min_dp[i][i+k] = inf;
				 max_dp[i][i+k] = -1;
				/**
				将他们初始化， 方便比较更新值
				**/  
				for(int j = i; j + 1 <= i + k; j ++){//遍历更新中间值
					min_dp[i][i+k] = min(min_dp[i][i+k], min_dp[i][j]+min_dp[j+1][i+k] + Hash[i+k]-Hash[i-1]);
					max_dp[i][i+k] = max(max_dp[i][i+k], max_dp[i][j]+max_dp[j+1][i+k] + Hash[i+k]-Hash[i-1]);
				} 
			}
		}
		cout << min_dp[1][n] << " " << max_dp[1][n] << endl;
	}
	return 0;
}
