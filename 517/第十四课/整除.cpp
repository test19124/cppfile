#include <bits/stdc++.h>
using namespace std;
struct sint {
  int a[200]; //数
  int b;      //标记正负
  int len;    //长度
};
int mod(sint a,int b) {
  int yushu=0;//余数
  for(int i=a.len-1;i>=0;i--) {
    yushu=(yushu*10+a.a[i])%b;
  }
  return yushu;
}
int main() {
  int t;
  cin>>t;
  for(int k=1;k<=t;k++) {
    sint a;
    string _a;
    int b;
    cin>>_a>>b;
    a.len=_a.length();
    if(_a[0]=='-') {
      a.b=-1;
      for(int i=1;i<=a.len;i++) {
        a.a[i-1]=int(_a[a.len-i]-'0');
      }
      a.len--;
    } else {
      a.b=1;
      for(int i=0;i<a.len;i++) {
        a.a[i]=int(_a[a.len-i-1]-'0');
      }
    }
    /*
    for(int i=a.len-1;i>=0;i--) {
      cout<<a.a[i];
    }
    cout<<endl;
    */
    int x=mod(a,b);
    cout<<"Case "<<k<<": ";
    if(!x) cout<<"divisible\n";
    else cout<<"not divisible\n";
  }
  return 0;
}