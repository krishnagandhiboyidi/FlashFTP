#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ref -100000
#define val 200000
	int arr[1000000];
	int brr[1000000];
	int crr[1000000];
int main() {
	
        int n,i=0,j,q,p,s,t,u,v,temp,k,res,fake;
        for(j=0;j<1000000;j++)
          arr[j]=0;
      scanf("%d",&n);
    for(v=0;v<=val+1;v++)
    {crr[v]=v+ref;
     //printf("%d\t",crr[v]);
    }
      while(i<n)
      {   //int k,res,fake;
          scanf("%d", &k );
          res=ref-k;
         // printf("%d\n",res);
          if(res>=0){
          arr[res]=arr[res]+1;
              printf("%d\n",arr[res]);}
          else
          {
          fake=-1*res;
          arr[fake]=arr[fake]+1;
          printf("%d\n",arr[fake]);
          }
        i++;
        }
      printf("\n\n");
        scanf("%d",&q);
         for(p=0;p<q;p++){
          	scanf("%d",&brr[p]);
                 printf("p=%d ",p);
			 }

        printf("out of p\n");
 
        for(p=0;p<q;p++)
          {
		printf("p=%d\t",p);
                printf("brr[%d] = %d\n",p,brr[p]);
	  }
	
	printf("out of p\n");

         for(s=0;s<=val;s++){
		printf("inside s = %d\n",s);
           for(t=0;t<=val-s;t++){
		printf("inside t = %d\n",t);

               if(arr[t]<arr[t+1])
               {
		printf("inside if \n");
                   temp=arr[t];
                   arr[t]=arr[t+1];
                   arr[t+1]=temp;
                   crr[t]=t+1;
                   crr[t+1]=t;
               }
			    }
	}
       for(u=0;u<q;u++)
       {
           printf("%d\n",crr[brr[u]]);
       }
    return 0;
}

