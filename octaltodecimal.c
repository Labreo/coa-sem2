#include <stdio.h>
#include <math.h>
int x=0;int sum=0;
int num=0;
int otod(int b);
int main(){
     printf("Enter the octal no:");
    scanf("%d",&x);
    int y=otod(x);
    printf("%d\n",y);
    return 0;
}

int otod(int b){
    int f=0;
    while(b>0){
     num=b%10;
     sum=sum+num*pow(8,f);
     b=b/10;
     ++f;
    }
     return sum;
}
