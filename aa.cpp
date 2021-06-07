#include <bits/stdc++.h>
using namespace std;

vector<int> G1[210],G2[210],x;
bool a[210],vis[210];
int ii[210],t;

void dfs1(int u)
{
  if(vis[u])
  {
    return;
  }
  vis[u]=1;
  for(int i=0; i<G1[u].size(); i++)
  {
    dfs1(G1[u][i]);
  }
  x.push_back(u);
}

void dfs2(u)
{
  if(ii[u])
  {
    return ;
  }
  ii[u]=t;
  for(int i=0; i<G2[u].size(); i++)
  {
    dfs(G2[u][i]);
  }
}

int main()
{
  int n,to;
  cin>>n;
  for(int i=0; i<n; i++)
  {
    while(cin>>to,to)
    {
      G1[i].push_back(to-1);
      G2[to-1].push_back(i);
    }
  }
  for(int i=0; i<n; i++)
  {
    dfs1(i);
  }
  t=0;
  for(int i=n-1; i>=0; i--)
  {
    if(a[x[i]]==0)
    {
      t++;
      dfs2(x[i]);
    }
  }
  for(int u=0; u<n; u++)
  {
    for(int i=0; i<G1[u].size(); i++)
    {
      if(a[u]!=a[G1[u][i]])
      {
        ii[a[G1[u][i]]]==true;
      }
    }
  }
  int ans=0;
  for(int i=1; i<=x; i++)
  {
    if(ii[i]==0)
    {
      ans++;
    }
  }
  if(x==1) cout<<0<<endl;
  else cout<<ans<<endl;
  return 0;
}
