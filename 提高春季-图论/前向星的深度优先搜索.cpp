#include <bits/stdc++.h>
using namespace std;
struct tu {
  int u,v,next;
} a[10010];
int b[10010];//b[i]:启点是i的点的(最大)编号
bool c[10010];//c[i]:true-走过这个点,false-没走过这个点
int tot;
void add(int u,int v) {
  tot++;
  a[tot].u=u;
  a[tot].v=v;
  a[tot].next=b[u];
  b[u]=tot;
}
int zhan[10010],ding;
void ru(int x) { //入栈
  zhan[++ding]=x;
  c[x]=true;
  cout<<x<<endl;
  return ;
}
int cu() { //出栈
  return zhan[ding--];
}
void dfs(int u/*u点*/) {
  if(c[u]) return;
  ru(u);
  for(int i=b[u];i!=-1;i=a[i].next)
    dfs(a[i].v);
}
int main() {
  for(int i=0;i<10010;i++) b[i]=-1;
  int n,m;
  cin>>n>>m;
  int u,v;
  for(int i=1;i<=m;i++) {
    cin>>u>>v;
    add(u,v);add(v,u);
  }
  dfs(1);
  return 0;
}