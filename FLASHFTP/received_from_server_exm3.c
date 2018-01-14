#include <stdio.h>
long int A[1000000];
int main()
{
   long long int T,i=1,j,r,S,sum;
    long long int p;
scanf("%lld",&T);
while(i<=T)
{
  scanf("%lld %lld %lld",&r, &S, &p);
  A[1]=1;
   sum=1;
  for(j=2;j<=p;j++)
     {
       A[j]=(((A[j-1]*r)%p)%p);
       sum=(((sum+A[j])%p)%p);
         if(sum==S)
           break;  
        }
   if(j<=p)
   printf("%lld\n",j);
    else
    printf("-1");
 i++;
  }
    return 0;
}

