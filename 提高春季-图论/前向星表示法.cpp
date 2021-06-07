#include <bits/stdc++.h>
using namespace std;
struct tu {
  int u,v,w;
  int next;
} a[100010];
int b[100010];
int main() {
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++) {
    cin>>a[i].u>>a[i].v>>a[i].w;
    a[i].next=b[a[i].u];
    b[a[i].u]=i;
  }
  for(int i=1;i<=n;i++) {
    cout<<i;
    for(int j=b[i];j!=0;j=a[j].next) {
      cout<<"->"<<a[j].v<<"("<<a[j].w<<")";
    }
    cout<<endl;
  }
  return 0;
}