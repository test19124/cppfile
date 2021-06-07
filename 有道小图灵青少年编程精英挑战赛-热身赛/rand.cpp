#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(0));
  int n=rand()*rand()%1000001,m=rand()*rand()%1000001;
  cout<<n<<" "<<m<<"\n";
  for(int i=0;i<m;i++)
    cout<<rand()*rand()%1000000001<<" ";
  cout<<"\n";
  for(int i=0;i<n;i++)
    cout<<rand()*rand()%1000000001<<" "<<rand()*rand()%m<<"\n";
  return 0;
}