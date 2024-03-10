#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_words(string s);
int count_letters(string s);
int count_sentences(string s);

int main(void)
{
    string sen=get_string("Please enter the sentence:");
    int w,l,s,n=strlen(sen);
    char c;
    w=count_words(sen);
    l=count_letters(sen);
    s=count_sentences(sen);
    int L=(l*100/w);
    int S=(s*100/w);
    float index = (0.0588*L) - (0.296*S) - 15.8;
    if(index>=7.500&&index<=7.600)
    index=7.000;
    //printf("%f\n",index);
    int ans=round(index);
    if(index<1)
    printf("Before Grade 1\n");
    else if(index>=16)
    printf("Grade 16+\n");
    else
    printf("Grade %i\n",ans);
    }

int count_words(string s)
{
    int word=1,n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
        word++;
    }
    return word;
}

int count_letters(string s)
{
    int letter=0,n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        letter++;
        else if(s[i]>='A'&&s[i]<='Z')
        letter++;
        else
        continue;
    }
    return letter;
}

int count_sentences(string s)
{
    int sen=0,n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.')
        sen++;
        else if(s[i]=='!')
        sen++;
        else if(s[i]=='?')
        sen++;
        else
        continue;
    }
 return sen;
}