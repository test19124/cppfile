#include <bits/stdc++.h>
using namespace std;

int main() {
  int t,s;
  cin>>t;
  for(int i=1;i<=t;i++) {
    cin>>s;
    int x=sqrt(s);
    int y=x*(x-1)+1;
    if(x*x==s) {
      if(x%2==1) cout<<"Case "<<i<<": "<<"1 "<<x<<endl;
      else cout<<"Case "<<i<<": "<<x<<" 1"<<endl;
    } else {
			if(s<y) {
        if(x%2==1) cout<<"Case "<<i<<": "<<x+1<<" "<<x+1+y-s<<endl;
        else cout<<"Case "<<i<<": "<<x+1+y-s<<" "<<x+1<<endl;
      }
			else {
        if(x%2==1) cout<<"Case "<<i<<": "<<x+1-y+s<<" "<<x+1<<endl;
        else cout<<"Case "<<i<<": "<<x+1<<" "<<x+1-y+s<<endl;
      }
    }
  }
  return 0;
}
