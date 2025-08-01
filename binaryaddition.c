#include <stdio.h>
#include <math.h>

int num1=0;int sum=0;int num2=0;int carry=0;int num=0;
void binadd(int x,int y);
void compliment1(int arr[8]);
int main(){
    
    int a[8];int b[8];
     
     
    
     printf("Enter first digit:");
    for(int i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
    }
     /*printf("Enter second digit:");
     scanf("%d",&b);*/
    compliment1(a);
    printf("\n1's Complement: ");
    for (int i = 0; i < 8; i++) printf("%d", a[i]);
    return 0;
}



/*void binadd(int x,int y){
    num1=0;
    sum=0;
    num2=0;
    i=0;
    carry=0;
    while(x>0){
     num1=x%10;
     x=x/10;
     num2=y%10;
     y=y/10;
     if(num1+num2+carry==0){
       sum=sum+0*pow(10,i);
        carry=0;
     }else if(num1+num2+carry==1){
        sum=sum+1*pow(10,i);
        carry=0;
     }else if(num1+num2+carry==2){
        sum=sum+0*pow(10,i);
        carry=1;
     }else if(num1+num2+carry==3){
        sum=sum+1*pow(10,i);
        carry=1;
     }
     ++i;
    }
    printf("%d",sum);
}
    */

void compliment1(int arr[8]){
 for (int i = 0; i < 8; i++) {
        arr[i] = arr[i] == 0 ? 1 : 0;
    }
    
}
/*111+101= users enter convert dec to binary 4)additon subtraction 1's compliment 2's compliment 2's complimwnt 8 bit represemtatipn  accept 2 compliment 4bit 5 bit pass 2 compliment
pass to 1's compliment 
add 2 no'a funciton 
subtract 2's no
call 2nd second pass to 2's compliment of it
call 1's compliment in 2's compliment


*/