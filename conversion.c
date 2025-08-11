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

int main() {
    int decimal, binary, octal;
    char hex[20];

    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimal);
    printf("Binary representation: %d\n", dtob(decimal));

    printf("\nEnter a binary number to convert to decimal: ");
    scanf("%d", &binary);
    printf("Decimal representation: %d\n", btod(binary));

    printf("\nEnter a decimal number to convert to octal: ");
    scanf("%d", &decimal);
    printf("Octal representation: %d\n", dtoo(decimal));

    printf("\nEnter an octal number to convert to decimal: ");
    scanf("%d", &octal);
    printf("Decimal representation: %d\n", otod(octal));

    printf("\nEnter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimal);
    dtoh(decimal);

    printf("\nEnter a hexadecimal number to convert to decimal: ");
    scanf("%s", hex);
    printf("Decimal representation: %d\n", htod(hex));

    return 0;
}

/*get the digit do %8 that will give remainder which is the represnetation
 then do divide 8 till greater than 0*/
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

//Similar process with 2 now
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
//multiply ecer single single digit from right to left with 2^ thier index
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
//similar with power of 8
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

/*have array with hexdigits hex char array which is empty then mod 16
assign whatever rem you get as index for hex digits and then set to hex array*/
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

/*get char then start from right to left then:*/
int htod(char hex[]) {
    int len = 0, base = 1, decimal = 0;
    while (hex[len] != '\0') {
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        char ch = hex[i];
        /*characters '0' to '9' represent values 0–9.
        eg '3' - '0' = 51 - 48 = 3 then 10-16 is by a to f multiply with 
        resp base 16*/
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