#include <bits/stdc++.h>

#define MAX 1012345
char s[MAX];
char cc;
int c, max;

int main()
{
    scanf("%s", s);
    
    cc=s[0];
    c=1;
    max=1;

    for(int i = 1; s[i] != '\0'; i++)
    {
        if(s[i] == cc)
        {
            c++;
        }
        else{
            max = (max > c) ? max : c;
            cc = s[i];
            c = 1;
        }
    }
    max = (max > c) ? max : c;

    printf("%d", max);
}