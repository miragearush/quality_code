//LCM -> Least common multiple.
#include<stdio.h>
int main(){
    int a,b;
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    int L; // For bigger number.
    for (L = a>b?a:b;L<=a*b; L++) 
    {
        if (L%a==0 && L%b==0) // common multiple form L 
        {
            printf("LCM = %d",L);
            break;
        }
    }
    return 0;
}