/*
#include<iostream>
#include<vector>
using namespace std;
int n,m,indexx;
int dfn[1010],low[1010],a[1010];
vector<int>Map[1010];
int tarjan(int u,int fa) {
  indexx++;
  low[u]=dfn[u]=indexx;
  for(int i=0;i<Map[u].size();i++) {
    int v=Map[u][i];
    if(v!=fa) {
      if(!dfn[v]) {
        low[u]=min(low[u],tarjan(v,u));
      } else if(dfn[u]>=dfn[v]) {
        low[u]=min(low[u],dfn[v]);
      }
    }
  }
  return low[u];
}
int main() {
  cin>>n>>m;
  int u,v;
  for(int i=1;i<=m;i++) {
    cin>>u>>v;
    Map[u].push_back(v);
    Map[v].push_back(u);
  }
  tarjan(1,-1);
  for(int i=1;i<=n;i++) {
    for(int j=0;j<Map[i].size();j++) {
      int k=Map[i][j];
      if(low[i]!=low[k]) {
        a[low[k]]++;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++) {
    if(a[i]==1) {
      ans++;
    }
  }
  cout<<(ans+1)/2<<endl;
  return 0;
}
*/






#include <bits/stdc++.h>
using namespace std;
struct G {
  int to,next;
} tu[1010];
int indexx,cnt,top;
int dfn[1010],low[1010],a[1010];
int zhan[1010],c[1010];
bool vis[1010];
int n,r;
void add(int u,int v) {
  tu[cnt].to=v;
  tu[cnt].next=a[u];
  a[u]=cnt;
  cnt++;
}
void tarjan(int u,int fa) {
  ++indexx;
  dfn[u]=low[u]=indexx;
  vis[u]==true;
  zhan[top++]=u;
  for(int i=a[u]; i!=1; i=tu[i].next) {
    int v=tu[i].to;
    if(v!=fa) {
      tarjan(v,u);
      low[u]=min(low[u],low[v]);
    } else {
      low[u]=min(low[u],dfn[v]);
    }
  }
  if(dfn[u]==low[u]) {
    while(a[top]!=u&&&top>0) {
      low[zhan[top-1]]=low[u];
      top--;
      vis[zhan[top]]=false;
    }
  }
}a
int main() {
  freopen("island.in","r",stdin);        
  freopen("island.out","w",stdout); 
  for(int i=0;i<1010;i++) {
    a[i]=-1;
  }
  cin>>n>>r;
  int v,w;
  for(int i=0;i<r;i++) {
    cin>>v>>w;
    v--;w--;
    add(w,v);
    add(v,w);
  }
  tarjan(0,-1);
  for(int i=0;i<n;i++) {
    for(int j=a[i];j!=-1;j=tu[j].next) {
      if(low[i]!=low[tu[j].to]) {
        c[low[tu[j].to]]++;
      }
    }
  }
  int ans=0;
  for(int i=0;i<n;i++) {
    if(c[i]==1) {
      ans++;
    }
  }
  cout<<(ans+1)/2<<endl;
  return 0;
}