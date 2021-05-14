/**
猪猪侠 决定祝他来自黑色玫瑰的朋友生日快乐，并给他的朋友寄明信片。为了让礼物更神秘，猪猪侠 决定制作一个 连环套。
这里的连环套表示一系列的信封 A = {a1,  a2,  ...,  an}，其中第 i 个信封的宽度和高度，分别严格大于第 (i  -  1) 个信封的宽度和高度。
连环套的尺寸是指连环套中的信封数目。
猪猪侠想要从自己拥有的信封制作出最大尺寸的连环套，使得该连环套能够放入一张明信片。
如果名信片的宽度和高度分别小于连环套中最小信封的宽度和高度，则表示名信片可以被放入连环套。禁止旋转名信片和信封。
猪猪侠 拥有很多信封，但时间很有限，他还要节约时间去泡妹子，因此将这一困难的任务委托给您完成。

输入
第一行包含整数 n, w, h (1  ≤ n ≤ 5000, 1 ≤ w,  h  ≤ 106) — 猪猪侠 拥有的信封编号，以及相应的明信片宽度和高度。
接下来的 n 行，每行包含两个整数 wi 和 hi — 表示第 i 个信封的宽度和高度 (1 ≤ wi,  hi ≤ 106)。

输出
在第一行中，打印连环套的最大尺寸。在第二行中，打印信封的编号 (以空格间隔)，构成所要求的连环套，以最小信封的编号开始。
请记住，名信片应当能够放入最小的信封。如果最大尺寸的连环套不唯一，则打印所有答案中的任意一种。
如果名信片无法放入任何一个信封，则在单一的行中打印数字 0 。

样例：
输入
2 1 1
2 2
2 2
输出
1
1 
输入
3 3 3
5 4
12 11
9 8
输出
3
1 3 2 
**/

/**
错误思路：首先认为这是一个嵌套矩形；
          用二维数组模拟；
          dfs+dp配合即可：
**/

// 内存超限错误解：
#include<bits/stdc++.h>
using namespace std;
const int N = 5000;
int G[N][N];
int x[N], y[N],dp[N];
int n, w, h;
int dfs(int i){
	if(dp[i] > 0){
		return dp[i];
	}
	dp[i] = 1;
	for(int j = 1; j <= n; j ++){
		if(G[i][j]){
			dp[i] = max(dp[i], dfs(j)+1);
		}
	}
	return dp[i];
}

void print_road(int i){
	cout << i << " ";
	for(int j = 1; j <= n; j ++){
		if(G[i][j] && dp[i] == dp[j]+1){
			print_road(j);
			break;
		}
	}
}
int main(){
	cin >> n >> w >> h;
	for(int i = 1; i <= n; i ++){
		cin >> x[i] >> y[i];
	}
	memset(G, 0, sizeof(G));
	int flag = 0;
	for(int i = 1; i <= n; i ++){
		if(x[i] <= w || y[i] <= h){
			continue;
		}else{
			flag = 1;
			for(int j = 1; j <= n; j ++){
				if(x[i] < x[j] && y[i] < y[j]){
					G[i][j] = 1;
				}
			}
		}
		
		
	}
	if(!flag){
		cout << "0" << endl;
	}else{
		int ans = 0;
		int best = 0;
		for(int i = 1; i <= n; i ++){
			if(ans < dfs(i)){
				ans = dfs(i);
				best = i;
			}
		}
		cout << ans << endl;
		print_road(best);
		cout << endl;
	}
	
	// for(int i = 1; i <= n; i ++){
	// 	for(int j = 1; j <= n; j ++){
	// 		cout << G[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}

//答案错误解：
#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
vector<int >G[N];
int x[N], y[N],dp[N];
int n, w, h;
int dfs(int i){
	if(dp[i] > 0){
		return dp[i];
	}
	dp[i] = 1;
	int len = G[i].size();
	for(int j = 0; j < len; j ++){
		int v = G[i][j];
		dp[i] = max(dp[i], dfs(v)+1);
	}
	return dp[i];
}

void print_road(int i){
	cout << i << " ";
	int len = G[i].size();
	for(int j = 0; j < len; j ++){
		int v = G[i][j];
		if(dp[i] == dp[v]+1){
			print_road(v);
			break;
		}
	}
}
int main(){
	cin >> n >> w >> h;
	for(int i = 1; i <= n; i ++){
		cin >> x[i] >> y[i];
	}
	memset(G, 0, sizeof(G));
	int flag = 0;
	for(int i = 1; i <= n; i ++){
		if(w < x[i] && h < y[i]){
			flag = 1;
				for(int j = 1; j <= n; j ++){
		 		if(x[i] < x[j] && y[i] < y[j]){
		 			G[i].push_back(j);
		 		}
		 	}
		}
	}
	if(!flag){
		cout << "0" << endl;
	}else{
		int ans = 0;
		int best = 0;
		for(int i = 1; i <= n; i ++){
			if(ans < dfs(i)){
				ans = dfs(i);
				best = i;
			}
		}
		cout << ans << endl;
		print_road(best);
		cout << endl;
	}
	return 0;
}

/**
最后发现是回溯是输出错误；
于是该进了一下，用一个f[maxn]数组来存下；
以方便来输出放信的顺序；
用结构体代替二位数组，防止内存超限；
**/

//正解：
#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
struct node{
	int x, y;
}G[N];
int f[N], dp[N];
int n, w, h;

int dfs(int node){
	if(dp[node] > 0){
		return dp[node];
	}
	dp[node] = 1;
	for(int i = 1; i <= n; i ++){
		if(G[i].x > G[node].x && G[i].y > G[node].y){
			if(dp[node] < dfs(i)+1){
				dp[node] = dfs(i)+1;
				f[node] = i; 
			}
		}
	}
	return dp[node];
}

void print_road(int i){
	cout << i << " ";
	if(f[i] != 0){
		print_road(f[i]);
	}
}
int main(){
	cin >> n >> w >> h;
	for(int i = 1; i <= n; i ++){
		cin >> G[i].x >> G[i].y; 
	}
	int ans = 0;
	int best = 0;
	for(int i = 1; i <= n; i ++){
		if(G[i].x > w && G[i].y > h){
			dfs(i);
			if(ans < dp[i]){
				best = i;
				ans = dp[i];
			}
		}
	}
	cout << ans << endl;
	if(ans != 0){
		print_road(best);
		cout << endl;
	}
	return 0;
}
