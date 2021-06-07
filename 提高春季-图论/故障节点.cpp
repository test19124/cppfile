#include <bits/stdc++.h>
using namespace std;
vector<int>Map[1010];
int dfn[1010],low[1010],a[1010];
int n,xxx,indexx,root,son;
void tarjan(int u) {  
  indexx++;  
  dfn[u]=low[u]=indexx;  
  for(int i=0;i<Map[u].size();i++) {  
    int v=Map[u][i];  
    if(dfn[v]==0) {  
      tarjan(v);  
      if(u==root) {  
        son++;  
      } else {  
        low[u]=min(low[u],low[v]);  
        if(low[v]>=dfn[u]) {
          a[u]++;
        }  
      }  
    } else {  
      low[u]=min(low[u],dfn[v]);  
    }  
  }  
}  
int main() { 
  //freopen("SPF.in","r",stdin);      
  //freopen("SPF.out","w",stdout);      
  while(cin>>n&&n!=0) {  
    indexx=0;son=0;  
    for(int i=0;i<110;i++) {  
      Map[i].clear();  
      a[i]=dfn[i]=0;  
    }  
    int u,v;  
    while(cin>>u&&u!=0) {  
      while(getchar()!='\n') {  
        cin>>v;  
        Map[u].push_back(v);  
        Map[v].push_back(u);  
      }  
    }  
    root=1;
    tarjan(root);  
    cout<<"Network #"<<++xxx<<endl;
    if(son>1) a[root]=true;  
    int ans=0;
    for(int i=0;i<1010;i++) {  
      if(a[i]) cout<<"  SPF node "<<i<<" leaves "<<a[i]+1<<" subnets"<<endl;
      ans+=a[i];
    }  
    if(!ans) cout<<"   No SPF nodes"<<endl;  
  }  
  return 0;
}