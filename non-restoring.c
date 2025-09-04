#include <stdio.h>
#include <string.h>
void shiftleft(int a[4],int q[4]);
void compliment1(int arr[4], int result[4]);
void compliment2(int arr[4], int result[4]);
void binadd(int x[4], int y[4], int result[4]);
void binsubtract(int x[4], int y[4], int result[4]);
int main(){
    char Divisor[5];
     char Dividend[5];
    int n = 4;
    int m[4], q[4];
    int binresult[4];
     int a[4]={0,0,0,0};
    printf("Enter Divisor(M) number: ");
    scanf("%s", Divisor);
    printf("Enter  Dividend(Q) number: ");
    scanf("%s",  Dividend);
    for (int i = 0; i < 4; i++) {
        m[i] = Divisor[i] - '0';
        q[i] = Dividend[i] - '0';
    }
   
 
    while (n!=0){
       if(a[0]==0){
         shiftleft(a,q);
         binsubtract(a,m,binresult);
          for (int i = 3; i >= 0; i--) {
                a[i] = binresult[i];
          }
       }
       else{
        shiftleft(a,q);
         binadd(a,m,binresult);
          for (int i = 3; i >= 0; i--) {
                a[i] = binresult[i];
            }
       }
       if(a[0]==0){
        q[0]=1;
       }else{
        q[0]=0;
       }
       n=n-1;

    }
    if(a[0]==1){
                 binadd(a,m,binresult);
          for (int i = 3; i >= 0; i--) {
                a[i] = binresult[i];
            }
        }

      printf("\nResult: ");
      printf("\nThe Remainder is : ");
    for (int i = 0; i < 4; i++) printf("%d", a[i]);
    printf("\nThe Quotient is : ");
    for (int i = 0; i < 4; i++) printf("%d", q[i]);
    printf("\n");
 
    return 0;
}

void shiftleft(int a[4],int q[4]){
    
    for(int i=0;i<2;++i){
       a[i]=a[i+1];
    }
    a[3]=q[0];
    for(int i=0;i<2;++i){
        q[i]=q[i+1];

    }
    q[3]=0;
}
void binsubtract(int x[4], int y[4], int result[4]) {
    int negy[4];
    compliment2(y, negy);    
    binadd(x, negy, result); 
}

void compliment1(int arr[4], int result[4]) {
    for (int i = 0; i < 4; i++) {
        result[i] = arr[i] == 0 ? 1 : 0;
    }
}


void compliment2(int arr[4], int result[4]) {
    int one[4] = {0, 0, 0, 1};
    int temp[4];
    compliment1(arr, temp);
    binadd(temp, one, result);
}


void binadd(int x[4], int y[4], int result[4]) {
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = x[i] + y[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}
