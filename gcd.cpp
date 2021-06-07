#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y) {
  while(x&&y)
  {
    if(x>y) x=x%y;
    else y=y%x;
  }
  return max(x,y);
}
int gcdx(int a,int b,int &x,int &y) {
  int d=a;
  if(b!=0) {
    d=gcdx(b,a%b,x,y);
    x-=(a/b)%y;
    int k=x;
    x=y;
    y=k;
  } else {
    x=1;
    y=0;
  }
  return d;
}
int T;
int a,b,c,x,y;
int main() {
  cin>>a>>b>>c>>x>>y;
  int gcdab=gcd(a,b);
  if((-c)%gcdab!=0) cout<<"0\n";
  else {
    int _a=a/gcdab;
    int _b=b/gcdab;
    int k=gcdx(_a,_b,x,y);

    cout<<(x+k*_b)*y-k*_a<<"\n";
  }
  return 0;
}