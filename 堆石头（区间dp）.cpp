/**
题目简介：一条直线上摆放着一行共n堆的石子。现要将石子有序地合并成一堆。规定每次只能选相邻的两堆合并成新的一堆，并将新的一堆石子数                    记为该次合并的得分。请编辑计算出将n堆石子合并成一堆的最小得分和将n堆石子合并成一堆的最大得分。

  输入：       

                    输入有多组测试数据。

                     每组第一行为n(n<=100)，表示有n堆石子，。

                     二行为n个用空格隔开的整数，依次表示这n堆石子的石子数量ai（0<ai<=100）

  输出：

                       每组测试数据输出有一行。输出将n堆石子合并成一堆的最小得分和将n堆石子合并成一堆的最大得分。

                       中间用空格分开。 
                       
**/

/**
 思路：1.分析该题是简单的区间dp，dp[i][j]表示从i~j区间所得的最大最小分，类似于邻接表。

           2.首先存下输入数据的前缀和， 方便去区间值。

           3.初始化两个邻接表， 最小与最大的存值，利用存下来的数据hash[]，来更新邻接表，思路与dp类似。

           4.以几个例子推导公式 dp[1][2] = dp[1][1]+dp[2][2]+hash[2]-hash[0];

           5.推导出核心公式， dp[i][j]=max/min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]); 开始改进完成代码。


**/

//具体代码：
​
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

​

