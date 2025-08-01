#include <stdio.h>
#include <math.h>

int carry=0;int num=0;
void binadd(int x[4],int y[4],int result[4]);
void compliment1(int arr[4]);
void compliment2(int arr[4]);
int main(){
    
    int a[4];int b[4];
    int result[4]={0,0,0,0};
     
    
     printf("Enter first digit:");
    for(int i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
    }
     printf("Enter second digit:");
    for(int i = 0; i < 4; i++) {
        scanf("%d", &b[i]);
    }
    
    binadd(a,b,result);
    /* compliment1(a);
    printf("\n1's Complement: ");
    for (int i = 0; i < 4; i++) printf("%d", a[i]);*/
    printf("\nResult: ");
    for (int i = 0; i < 4; i++) printf("%d", result[i]);
    return 0;
}



void binadd(int x[4],int y[4],int result[4]){
    carry=0;
    for(int i=3;i>=0;i--){
     if(x[i]+y[i]+carry==0){
       result[i]=0;
        carry=0;
     }else if(x[i]+y[i]+carry==1){
        result[i]=1;
        carry=0;
     }else if(x[i]+y[i]+carry==2){
        result[i]=0;
        carry=1;
     }else if(x[i]+y[i]+carry==3){
        result[i]=1;
        carry=1;
     }
    }
}
    
void compliment2(int arr[4]){
 for (int i = 0; i < 4; i++) {
        arr[i] = arr[i] == 0 ? 1 : 0;
    }
    
}

void compliment1(int arr[4]){
 for (int i = 0; i < 4; i++) {
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