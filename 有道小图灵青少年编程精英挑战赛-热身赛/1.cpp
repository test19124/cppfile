#include <bits/stdc++.h>
using namespace std;
int x[100010],y[100010];
int n,m;
int main() {
  cin>>n>>m;
  char ch;
  int xx,yy;
  for(int i=1;i<=m;i++) {
    cin>>xx>>yy;
    x[xx]++;
    y[yy]++;
  }
  int ans=0;
  for(int i=1;i<=n;i++) {
    ans+=max(0,x[i]-2);
    ans+=max(0,y[i]-2);
  }
  cout<<ans<<endl;
  return 0;
}