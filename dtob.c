#include <stdio.h>
#include <math.h>
int divide = 0;
int x = 0;
int i = 0;
int k = 0;
int num = 0;
int f = 0;
int arr[32];
int fixed[32];

int dtob(int b);
int btod(int c);
int dtoo(int b);
int otod(int b);


int main()
{

  printf("Enter the decimal no:");
  scanf("%d", &x);
  int y = dtob(x);
  printf("Binary representation:%d\n", y);
  int z = btod(y);
  printf("Decimal representation:%d\n", z);
  int a = dtoo(z);
  printf("Octal representation:%d\n", a);
  int b = otod(a);
  printf("Decimal representation:%d\n", b);
  return 0;
}
/* while(x>0) {
     divide=x%2;
     x=x/2;
     arr[i]=divide;
     ++i;
   }
int j;
for(j=i-1;j>=0;j--){
 printf("%d",arr[j]);

}*/
int dtoo(int b)
{
  int k = 0;
  int i = 0;
  int divide = 0;
  while (b > 0)
  {
    divide = b % 8;
    b = b / 8;
    arr[i] = divide;
    ++i;
  }
  int j;
  for (j = i - 1; j >= 0; j--)
  {
    k = k * 10 + arr[j];
  }
  return k;
}

int dtob(int b)
{
  while (b > 0)
  {
    divide = b % 2;
    b = b / 2;
    arr[i] = divide;
    ++i;
  }
  int j;
  int l;
  for (j = i - 1; j >= 0; j--)
  {
    k = k * 10 + arr[j];
  }

  return k;
}

int btod(int c)
{
  int sum = 0;
  while (c > 0)
  {
    num = c % 10;
    sum = sum + num * pow(2, f);
    c = c / 10;
    ++f;
  }
  return sum;
}

int otod(int b)
{
  int sum = 0;
  int f = 0;
  while (b > 0)
  {
    num = b % 10;
    sum = sum + num * pow(8, f);
    b = b / 10;
    ++f;
  }
  return sum;
}