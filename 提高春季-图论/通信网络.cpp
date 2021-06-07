#include <bits/stdc++.h>  
using namespace std;  
int n,root,son,indexx;  
int dfn[110],low[110];  
bool cut[110];  
vector<int>Map[110];  
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
        if(low[v]>=dfn[u]) { //是>=,不是>  
          cut[u]=true;  
        }  
      }  
    } else {  
      low[u]=min(low[u],dfn[v]);  
    }  
  }  
}  
int main() {  
  freopen("Network.in","r",stdin);      
  freopen("Network.out","w",stdout);      
  while(cin>>n&&n!=0) {  
    for(int i=0;i<110;i++) {  
      Map[i].clear();  
      cut[i]=dfn[i]=0;  
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
    son=0;  
    tarjan(root);  
    if(son>1) cut[root]=true;  
    int ans=0;  
    for(int i=1;i<=n;i++) {  
      ans+=cut[i];  
    }  
    cout<<ans<<endl;  
  }  
  return 0;  
}  