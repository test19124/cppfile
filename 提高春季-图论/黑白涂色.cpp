#include <iostream>
using namespace std;
int a[110][110],b[10010],c[10010];
int n,k,tot,maxx;
void dfs(int x) {
  if(x>n) {
    maxx=tot;
    for(int i=0;i<10010;i++) 
      b[i]=c[i];
    return ;
  }
  bool flag=true;
  for(int i=1;i<x;i++) {
    if(c[i]==1&&a[i][x]==0) {
      flag=false;
      break;
    }
  }
  if(flag) {
    c[x]=1;tot++;
    dfs(x+1);
    c[x]=0;tot--;
  }
  if(tot+n-x>maxx) {
    dfs(x+1);
  }
  return ;
}
int main() {
  //freopen("color.in","r",stdin);
  //freopen("color.out","w",stdout);
  int N;
  cin>>N;
  while(N--) {
    cin>>n>>k;
    for(int i=0;i<10010;i++) b[i]=c[i]=0;
    for(int i=0;i<110;i++) {
      for(int j=0;j<110;j++) {
        a[i][j]=1;
      }
    }
    maxx=tot=0;
    int u,v;
    for(int i=1;i<=k;i++) {
      cin>>u>>v;
      a[u][v]=a[v][u]=0;
    }
    dfs(1);
    cout<<maxx<<endl;
    for(int i=1,l=0;i<=n;i++) {
      if(b[i]==1) {
        if(l!=0) cout<<" ";
        cout<<i;
        l++;
      }
    }
    cout<<endl;
  }
  return 0;
}