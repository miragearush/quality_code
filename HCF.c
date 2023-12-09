// HCF -> Highest commom factor
#include<stdio.h>
int main(){
    int a,b;
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    int F;
    for (F = a<b?a:b;F>1;F--)
    {
        if (a%F==0 && b%F==0)
        {
            printf("HCF = %d",F);
            break;
        }
        
    }
    return 0;
}