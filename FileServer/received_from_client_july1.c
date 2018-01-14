#include <stdio.h>
#include<string.h>
int main()
{  int i,k,j,count=0,fake=0,p,q,var;
  char str[100000];
  char btr[100000];
    scanf("%s",str);
    for(p=0;p<strlen(str);p++)
      btr[p]=str[p];
    k=strlen(str);
    //printf("%d\n",k);
  //  printf("%s\n",str);
    for(i=0,j=k-1;i<=j;i++,j--)
      {   if(i==0 && j==k-1)
        {
          if(str[i]==str[j])
            {count=0;
             continue;
             }
          else if(str[i+1]==str[j])
              {str[j+1]=str[i];
                count=count+1;
                i=i+1;
               continue;
              }
           else
           {
            str[j]=str[i];
            count=count+1;
            continue;
           }
        }
        else if(str[i]==str[j])
         continue;
         str[j]=str[i]; 
         count=count+1;
          //  printf("%d\n",count);
          }
    for(i=0,j=k-1;i<=j;i++,j--)
      {  if(i==0 && j==k-1)
        {
          if(btr[i]==btr[j])
            {fake=0;
             continue;
             }
         else
          { var=0;
            while(btr[i+var] != btr[j] && var<k){
                var++;}
           for(q=var;q>0;q--){
             btr[j+q]=btr[i++]; 
              fake=fake+1;}
               i=i-1; 
                j=j+1;
            continue;
            //printf("%d\n",i);  
          }
  
         /* else if(btr[i+1]==btr[j])
              {btr[j+1]=btr[i];
                fake=fake+1;
                i=i+1;
               continue;
              }
           else
           {
            btr[j+1]=btr[i];
            fake=fake+1;
            j=j+1;
            continue;
           }*/
        }
        else if(btr[i]==btr[j]){
        // printf("%c\t%c",btr[i],btr[j]);
         continue;}
         btr[j]=btr[i]; 
         fake=fake+1;
        // printf("%d\n",fake);
          //  printf("%d\n",count);
          }
   // if(count<fake)
     //printf("%d",count);
    //else
     printf("%d",fake);
    return 0;
}

