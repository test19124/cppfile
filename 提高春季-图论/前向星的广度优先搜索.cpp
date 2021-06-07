#include <bits/stdc++.h>
using namespace std;
#define MAXX 10010
struct tu {
  int to,next;
} a[MAXX];
int b[MAXX],tot;
bool c[MAXX];
void add(int u,int v) {
  tot++;
  a[tot].to=v;
  a[tot].next=b[u];
  b[u]=tot;
}
int main() {
  for(int i=0;i<MAXX;i++) {
    b[i]=-1;
  }
  int n,m;
  cin>>n>>m;
  int u,v;
  for(int i=1;i<=m;i++) {
    cin>>u>>v;
    add(u,v);add(v,u);
  }
  for(int i=1;i<=n;i++) { //小错误2：是1~n不是0~n
    if(!c[i]) {           //小错误3: 忘记走过的是不能走的
      c[i]=true;          //小错误4: 走过的忘记标记
      queue<int> x;
      x.push(i);
      while(!x.empty()) {
        int y=x.front();
        x.pop();
        cout<<y<<endl;
        for(int j=b[y];j!=-1;j=a[j].next) {
          if(!c[a[j].to]) { //小错误1：这里是a[j].to不是j
            c[a[j].to]=true;
            x.push(a[j].to);
          }
        }
      }
    }
  }
  return 0;
}