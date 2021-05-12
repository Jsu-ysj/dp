/**
一棵树的直径就是这棵树上存在的最长路径。现在有一棵n个节点的树，现在想知道这棵树的直径包含的边的个数是多少？

如图所示的数据，这棵树的直径为(1-2-3-6-9)这条路径，包含的边的个数为4，所以答案是4。
Input
第1行：一个整数n，表示树上的节点个数。(1<=n<=100000) ;
第2-n行：每行有两个整数u,v,表示u与v之间有一条路径。(1<=u,v<=n)
Output
输出一个整数，表示这棵树直径所包含的边的个数。
样例：    答案： 4
10
1 2
2 3
3 4
3 5
3 6
3 7
3 10
6 8
6 9
**/

/**
  思路：建立一个动态二维数组， 把每个节点的子节点存进去：
  for(int i = 1; i < n; i ++){
        int a, b;
        cin >> a >> b;
        p[b] = a;
        g[a].push_back(b);
    }
    顺便把根节点找出来；
    让后， dfs 收索每一个点的sum1,与sum2 ，当两个最大时相加最长：
    int dfs(int k){ 
    dp[k]= 0;
    int sz = g[k].size();
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < sz; i ++){
        int son = g[k][i];
        dfs(son);
        if(dp[son]+1 > sum1){
            sum2 = sum1;
            sum1 = dp[son] + 1;
        }else if(dp[son]+1 > sum2){
            sum2 = dp[son]+1;
        }
    }
    dp[k] = max(sum1, sum2);
   return sum1+sum2;
}

**/

//具体代码：
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
int dp[maxn];
int p[maxn];
vector<int > g[maxn];
int n, rt;

int dfs(int k){ 
    dp[k]= 0;
    int sz = g[k].size();
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < sz; i ++){
        int son = g[k][i];
        dfs(son);
        if(dp[son]+1 > sum1){
            sum2 = sum1;
            sum1 = dp[son] + 1;
        }else if(dp[son]+1 > sum2){
            sum2 = dp[son]+1;
        }
    }
    dp[k] = max(sum1, sum2);
   return sum1+sum2;
}
int main(){
    cin >> n;
    for(int i = 1; i < n; i ++){
        int a, b;
        cin >> a >> b;
        p[b] = a;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i ++){
        if(!p[i]){
            cout << dfs(i) << endl;
            break;
        }
    }
    return 0;
}
