/** 题目简介:
有N个学生合影，站成左对齐的k排，每行分别有N1,N2…NK个人，第一排站最后，第k排站之前。
学生身高依次是1…N。在合影时候要求每一排从左到右递减，每一列从后面到前也递减，一共有多少总方案
Input
输入
每组测试数据包含两行。第一行给出行数k
第二行包含从后到前（n1，n2，…，nk）的行的长度，作为由单个空格分隔的十进制整数。
问题数据以0结束。
N<=30, k<=5;
Output
输出
输出每组数据的方案数
Sample Input
1
30
5
1 1 1 1 1
3
3 2 1
4
5 3 3 1
5
6 5 4 3 2
2
15 15
0
Sample Output
1
1
16
4158
141892608
9694845
**/

/**思路：
这个题就是一个比较麻烦的线性dp
初始化：f[0][0][0][0][0]=1
动态转移方程:
可以从（line[1],line[2],line[3],line[4],line[5]）转移到（line[1]+1,line[2],line[3],line[4],line[5]），（line[1],line[2]+1,line[3],line[4],line[5]）…（line[1],line[2],line[3],line[4],line[5]+1）;
然后就是巧妙的开个数组, 防止超限
**/


// 具体代码:
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
long long int dp[31][17][12][9][7];
int line[6];
int main() {
	int n;
	while(cin >> n && n) {
		memset(dp, 0, sizeof(dp));
		memset(line, 0, sizeof(line));
		for (int i=1; i<=n; i++) {
			cin >> line[i];
		}
		dp[0][0][0][0][0]=1;
		for (int a=0; a<=line[1]; a++) {
			for (int b=0; b<=line[2]; b++) {
				for (int c=0; c<=line[3]; c++) {
					for (int d=0; d<=line[4]; d++) {
						for (int e=0; e<=line[5]; e++) {
							if (a+1<=line[1]) dp[a+1][b][c][d][e]+=dp[a][b][c][d][e];
							if (b+1<=line[2]&&b<a) dp[a][b+1][c][d][e]+=dp[a][b][c][d][e];
							if (c+1<=line[3]&&c<a&&c<b) dp[a][b][c+1][d][e]+=dp[a][b][c][d][e];
							if (d+1<=line[4]&&d<a&&d<b&&d<c) dp[a][b][c][d+1][e]+=dp[a][b][c][d][e];
							if (e+1<=line[5]&&e<a&&e<b&&e<c&&e<d) dp[a][b][c][d][e+1]+=dp[a][b][c][d][e];
						}
					}
				}
			}
		}
		cout << dp[line[1]][line[2]][line[3]][line[4]][line[5]] << endl;
	}

	return 0;
}

