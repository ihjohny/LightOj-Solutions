    #include<stdio.h>
    int main()
    {
        int t=0,j,m,i,k,a[125],b[125],n,array[125];
        int s[125];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
        scanf("%d%d/n",&a[i],&b[i]);
        }
       
        for(j=0;j<n;j++){
           
        s[j]=a[j]+b[j];
       
        }
     
       
        for(k=0;k<n;k++){
       
        printf("Case %d: %d\n",k+1,s[k]);
       
        }
       
        return 0;
    }
