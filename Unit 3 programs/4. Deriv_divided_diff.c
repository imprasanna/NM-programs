//program to implement derivation using newton's Divided divided difference

#include <stdio.h>
int main()
{
    float x[10],fx[10],value,sum,h,s,xp,dd[10],factor,term;
    int i,j,n,k;
    printf("Enter number of data points : ");
    scanf("%d",&n);
   
    for(i=0;i<n;i++)
    {
      printf("Enter x[%d]: ",i);
        scanf("%f",&x[i]);
        printf("Enter y[%d]: ",i);
        scanf("%f",&fx[i]);
    }
    printf("Enter the point at which derivative is to be calculated : ");
    scanf("%f",&xp);
    
    
    for(i=0;i<n;i++)
    {
        dd[i] = fx[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            dd[j] = ((dd[j] - dd[j-1])/(x[j]-x[j-1-i]));
        }
    }

    value = dd[1];
    for(i=2;i<n;i++)                                        
    {
        term = 0;
        for(j=0;j<i;j++)                                   
        {
            factor = 1;
            for(k=0;k<i;k++)                               
            {
                if(j!=k)
                {
                    factor = factor * (xp-x[k]);
                }
            }
            term += factor;
        }
        value += dd[i] * term ;
    }
    
    printf("\nValue of derivative at %.2f is %.2f\n",xp,value);
}
// Enter number of data points : 5
// Enter the data points  

// 3  -13
// 5   23
// 11  899
// 27  17315
// 34   35606
// Enter the point at which derivative is to be calculate  10
// 233
