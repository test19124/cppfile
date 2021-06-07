// 线性筛 2021/2/20
#include <bits/stdc++.h>
using namespace std;
bool flag[10010];
int zhishu[10010],tot=0;
void init(int n) {
  for(int i=2;i<=n;i++) {
    if(flag[i]==false) zhishu[tot++]=i;
    for(int j=0;j<tot;j++) {
      if(i*zhishu[j]>n) break;
      flag[i*zhishu[j]]=true;
      if(i%zhishu[j]==0) /*整除*/ break;
    }
  }
}
int main() {
  init(10000);
  for(int i=0;i<tot;i++) cout<<zhishu[i]<<" ";
  return 0;
}