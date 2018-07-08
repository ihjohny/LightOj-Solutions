    #include<stdio.h>
    #include<math.h>
    int main()
    {
        int q,w;
        scanf("%d",&q);
        for(w=1;w<=q;w++)
        {
     
            int ax,ay,bx,by,cx,cy,dx,dy,area;
            scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
           
            dx=cx-(bx-ax);
            dy=ay+(cy-by);
           
            area=.5*(((ax*by)+(bx*cy)+(cx*dy)+(dx*ay))-((ay*bx)+(by*cx)+(cy*dx)+(dy*ax)));         
            if(area<0)
            {
                area=area*-1;
            }
            printf("Case %d: %d %d %d\n",w,dx,dy,area);
        }
    return 0;  
    }
