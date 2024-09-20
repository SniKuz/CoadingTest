#include <stdio.h>
#include <memory.h>

void check(char word[], int v[])
{
    memset(v, 0, sizeof(int)*26);
    for(int i = 0; word[i]; i++) v[word[i] - 'A']++;
}

int main()
{
    int n, v[26], f[26], ans=0;
    char word[12];
    scanf("%d%s", &n, word);
    check(word, v);
    while(--n)
    {
        scanf("%s", word);
        check(word, f);
        int plus = 0, minus = 0;
        for(int i = 0; i < 26; i++)
        {
            if(f[i] > v[i]) plus += f[i] - v[i];
            else if(f[i] < v[i]) minus += v[i] - f[i];
        }
        if(plus <= 1 && minus <= 1) ans++;
    }
    printf("%d\n", ans);
}