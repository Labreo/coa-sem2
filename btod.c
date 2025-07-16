#include <stdio.h>
#include <math.h>
int arr[32];
 int x=0;
int main(){    
    printf("Enter the binary no:");
    scanf("%d",&x);
    int i=0;int num=0;int sum=0;
    while(x>0){
     num=x%10;
     sum=sum+num*pow(2,i);
     x=x/10;
     ++i;
    }
    printf("The number is:%d",sum);
    return 0;
}