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
void dtoh(int decimal);
int htod(char hex[]);

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
  dtoh(b);
  
  char hex[20];
  printf("Enter hexadecimal to convert to decimal: ");
  scanf("%s", hex);
  int hextodecimal = htod(hex);
  printf("Decimal from hexadecimal: %d\n",hextodecimal);
  return 0;
}

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

void dtoh(int decimal) {
    char hexDigits[] = "0123456789ABCDEF";
    char hex[32];
    int i = 0;

    if (decimal == 0) {
        printf("Hexadecimal representation: 0\n");
    }
   else{
    while (decimal > 0) {
        int rem = decimal % 16;
        hex[i++] = hexDigits[rem];
        decimal /= 16;
    }
 
    printf("Hexadecimal representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
  }
}

int htod(char hex[]) {
    int len = 0, base = 1, decimal = 0;
    while (hex[len] != '\0') {
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        char ch = hex[i];
        if (ch >= '0' && ch <= '9') {
            decimal += (ch - '0') * base;
        } else if (ch >= 'A' && ch <= 'F') {
            decimal += (ch - 'A' + 10) * base;
        } else if (ch >= 'a' && ch <= 'f') {
            decimal += (ch - 'a' + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}