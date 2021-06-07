/**
用以下方式定义合法的括号字符串

1.空串是合法的
2. 如果S是合法的, 那么(S)和[S]也都是合法的
3. 如果A和B是合法的, 那么AB是一个合法的字符串.

举个栗子, 下列字符串都是合法的括号字符串:

(), [], (()), ([]), ()[], ()[()]

下面这些不是:

(, [, ), )(, ([)], ([(]

给出一个由字符'(', ')', '[', 和']'构成的字符串. 你的任务是找出一个最长的合法字符串的长度，
使这个的字符串是给出的字符串的子序列。对于字符串a1 a2 ... an, b1 b2 ... bm 当且仅当对于1 = i1 < i2 < ... < in = m, 
使得对于所有1 = j = n，aj = bij时, aj是bi的子序列（字符串长度不会超过1e4529459032485077827）
输入
多组数据. 每组数据在一行上输入一个只含有'(', ')', '[', ']'字符的字符串，字符串的最大长度是100, 输入字符串"end"结束

输出
对于每组数据, 在单独的1e2354398562345259283534269547行上输出题目描述中所求的长度

样例输入
((()))
aaaaaaaaaaaaaaaaaaa
啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
end
样例输出
fkgfugtrigbuikykigrhikbigb
5762463253
fbrtsredtwr
rgwegeeg
qaq
**/
/**
思路: 
这个题有毒， 输出错误，输入错误， 其他就是一个区间dp
看看 正确的题意
Brackets
 POJ - 2955 

We give the following inductive definition of a “regular brackets” sequence:

the empty sequence is a regular brackets sequence,
if s is a regular brackets sequence, then (s) and [s] are regular brackets sequences, and
if a and b are regular brackets sequences, then ab is a regular brackets sequence.
no other sequence is a regular brackets sequence
For instance, all of the following character sequences are regular brackets sequences:

(), [], (()), ()[], ()[()]

while the following character sequences are not:

(, ], )(, ([)], ([(]

Given a brackets sequence of characters a1a2 … an, your goal is to find the length of the longest
regular brackets sequence that is a subsequence of s. That is, you wish to find the largest m such
that for indices i1, i2, …, im where 1 ≤ i1 < i2 < … < im ≤ n, ai1ai2 … aim is a regular brackets sequence.

Given the initial sequence ([([]])], the longest regular brackets subsequence is [([])].

Input

The input test file will contain multiple test cases. Each input test case consists of a single 
line containing only the characters (, ), [, and ]; each input test will have length between 1 and 
100, inclusive. The end-of-file is marked by a line containing the word “end” and should not be processed.

Output

For each input case, the program should print the length of the longest possible regular brackets subsequence on a single line.

Sample Input

((()))
()()()
([]])
)[)(
([][][)
end
Sample Output

6
6
4
0
6
**/

//具体代码：
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e2 + 10;
int dp[N][N];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	 while(cin >> str && str != "end"){
	 	memset(dp, 0, sizeof(dp));
	 	int len = str.size();
	 	for(int i = len-1; i >= 0; i --){
	 		for(int j = i+1; j < len; j ++){
	 			dp[i][j] = dp[i+1][j];
	 			for(int k = i+1; k <= j; k ++){
	 				if(str[i] == '(' && str[k] == ')'){
	 					dp[i][j] = max(dp[i][j], dp[i+1][k-1] + dp[k+1][j] + 2);
					 }else if(str[i] == '[' && str[k] == ']'){
					 		dp[i][j] = max(dp[i][j], dp[i+1][k-1] + dp[k+1][j] + 2);
					 }
				 }
			 }
		 }
		 cout << dp[0][len-1] << endl;
	 }
	return 0;
}
