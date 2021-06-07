#include <bits/stdc++.h>
using namespace std;
int n;
int x[200010],c[200010],s[200010];
int l[200010],r[200010];
int main() {
  cin>>n;
  for(int i=1;i<=n;i++) {
    cin>>x[i]>>c[i]>>s[i];
    l[i]=x[i]-s[i];
    r[i]=x[i]+s[i];
  }
  //for()
  return 0;
}