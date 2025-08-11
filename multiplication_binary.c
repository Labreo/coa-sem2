#include <stdio.h>
void binadd(int x[4], int y[4], int result[4],int c[1]);
void shiftright(int c[1],int a[4],int q[4]);
int main(){
    int c[1] ={0};
    int a[4]= {0,0,0,0};
    int binresult[4]= {0,0,0,0};
    char multplicand[5];
    char multplier[5];
    int count = 4;
    int m[4],q[4];
    printf("Enter multiplicand number: ");
     scanf("%s", multplicand);
    
    printf("Enter multiplier number: ");
        scanf("%s", multplier);
    
        for (int i = 0; i < 4; i++) {
        m[i] = multplicand[i] - '0';
        q[i] = multplier[i] - '0';
    }
    
    while(count!=0){
    if(q[3]==1){
       // addbinary(a+m); to c,a
       binadd(a,m,binresult,c);
       for (int i = 3; i >= 0; i--){
        a[i]=binresult[i];
       }
       shiftright(c,a,q);
    }
    else{
        shiftright(c,a,q);
        //shift
    }
    count=count-1;
}
    printf("\nResult addition (4-bit binary): ");
     for (int i = 0; i < 4; i++)
      {printf("%d", a[i]);}
    for (int i = 0; i < 4; i++)
     {printf("%d", q[i]);}
    return 0;
}

void binadd(int x[4], int y[4], int result[4],int c[1])
{
   int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = x[i] + y[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
    c[0] = carry; 
}

void shiftright(int c[1],int a[4],int q[4]){
    int last_a = a[3]; 
     for (int i = 3; i > 0; i--) {
        q[i] = q[i-1];
    }
      q[0]=last_a;
      int temp_a0 = c[0];  
     for (int i = 3; i > 0; i--) {
        a[i] = a[i-1];
    }
    a[0] = temp_a0;  
    c[0]=0;
}
// c=0,a=0,ocount user c,a binaey take m q q=1 c,a have function for additio have function for shifitng