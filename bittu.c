#include<stdio.h>
void main()
{
    int T,R,c=0; 
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&R);
        if(R<8)
        {
            printf("0");
        }
        else
        {
            for(int z=1;z<(R/4);z++)
            {
                for(int y=1;y<(R/3);y++)
                {
                    for(int x=1;(x+3*y+4*z)<R;x++)
                    {
                        if(x+3*y+4*z==R)
                        {
                            c++;
                        }
                    }   
                    
                }
            }
            printf("%d",c);
        }
    }
}