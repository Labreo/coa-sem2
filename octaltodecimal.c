#include <stdio.h>
#include <math.h>
int x=0;int sum=0;
int num=0;int arr[32];
int otod(int b);
int dtoo(int b);
int main(){
     printf("Enter the octal no:");
    scanf("%d",&x);
    int y=otod(x);
    printf("The decimal no is:%d\n",y);
    int z = dtoo(y);
    printf("The octal no is:%d\n",z);
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

int dtoo(int b){
    int k=0;int i = 0;int divide=0;
        while(b>0){
        divide=b%8;
        b=b/8;
        arr[i]=divide;
        ++i;
}
int j;
for(j=i-1;j>=0;j--){
       k=k*10+arr[j];
}
return k;
}