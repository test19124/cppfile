#include<bits/stdc++.h>
using namespace std;
struct xxx {
  int a,b;
} a[1010];
bool cmp(xxx x,xxx y) {
  if(x.a==y.a) return x.b>y.b;
  return x.a<y.a;
}
int main()
{
  for(int k=1;k<=1000;k++) {
    a[k].a=0;
    a[k].b=k;
    for(int i=1;i<=k;i++)
      if(k%i==0)
        a[k].a++;
  }
  sort(&a[1],&a[1001],cmp);
  for(int k=1;k<=1000;k++) {
    cout<<k<<" "<<a[k].a<<" "<<a[k].b<<"\n";
  }
  int T,n;
  cin>>T;
  for(int i=1;i<=T;i++) {
    cin>>n;
    cout<<"Case "<<i<<": "<<a[n].b<<endl;
  }
  return 0;
}