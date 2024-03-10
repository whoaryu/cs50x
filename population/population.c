#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pre,post,n=0;
    do
    {
        pre=get_int("Enter the first population:\n");
    }
    while(pre<9);
    do
    {
        post=get_int("Enter the final populations \n");
    }
    while(post<pre);
    if(pre==post)
    {
        printf("Years: 0\n");
        return 0;
    }
    while(pre<post)
    {
        pre=pre+(pre/3)-(pre/4);
        n++;
    }
    printf("Years: %d \n",n);
}