#include <stdio.h>

int main()
{  int arr[1000000];
   int brr[1000000];
   int crr[1000000];
   int T,N,i,k,j,l,m,n,p,q,s,t,u,v,tot,sum,temp;
     scanf("%d",&T);
     while(T--)
     {   int i=0;
     p=0;
     s=0;
         scanf("%d",&N);
         while(i<N){
           scanf("%d", &arr[i] );
             i++;}
         for(j=0;j<N-1;j++){
           for(k=0;k<N-j-1;k++){
              if(arr[k+1]<arr[k])
                {
                    temp=arr[k+1];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }}}
          for(l=0;l<N/2;l++)
             {if(arr[N-l-1]-arr[l]>=0)
             brr[p++]=arr[N-l-1]-arr[l];
               else
              brr[p++]=-1*(arr[N-l-1]-arr[l]);
               }
          for(q=0;q<N-1;q+=2){
             if(arr[q+1]-arr[q]>=0)
             crr[s++]=arr[q+1]-arr[q];
             else
             crr[s++]=-1*(arr[q+1]-arr[q]);
                   }
                   sum=0;
          for(t=0;t<p;t++)
            sum=sum+brr[t];
                   tot=0;
          for(u=0;u<s;u++)
            tot=tot+crr[u];
         printf("%d %d",sum,tot);
         
     }
    return 0;
}

