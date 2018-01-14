#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{ vector<int> pre,post;
  vector<int>::iterator it,it1,it2,it3,it4;
  int T,res,p,neto,r,s,t,tot,sum,N,k,j,i=1;
  cin>>T;
  while(i<=T){
  cin>>N;
   vector<int> v;
  for(j=0;j<N;j++)
   {
     cin>>k;
     v.push_back(k);
   }
  s=0;
   while(s<N){
   tot=0; 
   sum=0; 
   //vector<int> v;
  for(it=v.begin(),r=0;r<=s;it++,r++)
   sum=sum+(*it);
   pre.push_back(sum);
  for(it=v.end(),r=N;r>=s;it--,r--)
   {if(it==v.end())
     continue;
    else
      tot=tot+(*it);
   }
   post.push_back(tot);
  s++;
  }neto=0;
  for(it3=post.begin();it3!=post.end();it3++)
    cout<<(*it3)<<"\t";
   cout<<"\n";
   for(it4=pre.begin();it4!=pre.end();it4++)
    cout<<(*it4)<<"\t";
  vector<int> net;
  for(it1=pre.begin(),it2=post.begin(),t=0;t<v.size();t++,it1++,it2++)
    {
      neto=neto+(*it1)+(*it2);
      net.push_back(neto);
    }
  res=min_element(net.begin(),net.end())-net.begin()+1;
  cout<<res<<"\n"; 
  pre.erase(pre.begin(),pre.end());
  post.erase(post.begin(),post.end());
  net.erase(net.begin(),net.end());
   //v.erase(v.begin(),v.end());
  i++;
  }
  return 0;}
