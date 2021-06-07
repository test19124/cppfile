#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010],b[1000010],c[1000010];
int f[1000010];
int main() {
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++) scanf("%d",&b[i]);
  for(int i=0;i<n;i++) scanf("%d%d",&a[i],&c[i]);
  while(1) {
    //cout<<1<<z" | "; for(int i=1;i<=m;i++) {cout<<b[i]<<" ";} cout<<endl; //打印当前粮食储备
    if(b[c[f[0]%n]]>=a[f[0]%n]) { //剩下的食材够吃
      b[c[f[0]%n]]-=a[f[0]%n]; //吃掉
      f[0]++; //下一天
    } else { //不够吃了
      break; //结束
    }
  }
  for(int k=1;k<n;k++) { //第k天开始吃
    b[c[(k-1)%n]]+=a[(k-1)%n];//从第几天开始要加上前一天的食物
    f[k]=f[k-1];
    while(1) {
      //cout<<k+1<<"天 | 粮食储备："; for(int i=1;i<=m;i++) {cout<<i<<"粮食:"<<b[i]<<" ";} cout<<endl;
      if(b[c[f[k]%n]]>=a[f[k]%n]) { //剩下的食材够吃
        b[c[f[k]%n]]-=a[f[k]%n]; //吃掉
        //cout<<k+1<<"天 | 吃掉"<<c[f[k]%n]<<"粮食"<<a[f[k]%n]<<"份"; cout<<endl;
        f[k]++; //下一天
      } else { //不够吃了
        break; //结束
      }
    }
  }
  for(int k=0;k<n;k++) printf("%d ",f[k]-k);
  return 0;  
}