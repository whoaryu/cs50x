#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n=get_int("Height: \n");
    }
    while(n<1||n>8);
    for(int i=1;i<=n;i++)
    {
        for(int m=n-i;m>0;m--)
            printf(" ");

        for(int l=0;l<i;l++)
            printf("#");

        for(int k=0;k<2;k++)
            printf(" ");

        for(int j=0;j<i;j++)
            printf("#");
        printf("\n");
    }
}