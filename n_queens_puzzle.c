#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int counter = 0;

int check_conditions(char **table,int x,int y,int n)
{
    int i = 0;
    int k = 0;
    char checkChar = table[x][y];

    while (i < n)
    {
        if ((table[x][i] == checkChar && i!= y) || (table[i][y] == checkChar && i != x))
        {
            return 0;
        }  
        i++;  
    }
    i = x;
    k = y;

    while (i < n && k < n)
    {
        if (table[i][k] == checkChar && i != x && k != y)
        {
            return 0;
        }
        k++;
        i++;
    }

    i = x;
    k = y;

    while (i >= 0 && k >= 0)
    {
        if (table[i][k] == checkChar && i != x && k != y)
        {
            return 0;
        }
        i--;
        k--;
    }

    i = x;
    k = y;

    while (i >= 0 && k < n)
    {
        if (table[i][k] == checkChar && i != x && k != y)
        {
            return 0;
        }
        i--;
        k++;
    }

    i = x;
    k = y;

    while (i < n && k >= 0)
    {
        if (table[i][k] == checkChar && i != x && k != y)
        {
            return 0;
        }
        i++;
        k--;
    }
    return 1;   
}

char    **createTable(int n)
{
    char **table = (char **)malloc(n * sizeof(char *));
    int i = 0;
    int k = 0;
    while (i < n)
    {
        table[i] = (char *)malloc(n * sizeof(char));
        i++;
    }
    i = 0;
    while (i < n)
    {
        k = 0;
        while (k < n)
        {
            table[i][k] = '.';
            k++;
        }
    i++;    
    }
    return table;
}

void    solve(char **table,int x,int y,int n,int skip)
{
    if (x == n)
    {
        return;
    }
    if (x == skip)
    {
        counter++;
        solve(table,x + 1,0,n,skip);
        return;
    }
    while (y < n)
    {
        table[x][y] = 'Q';
        if (check_conditions(table,x,y,n))
        {
            counter++;
            solve(table,x + 1,0,n,skip);
        }
        else 
        {
            table[x][y] = '.';
        }

        if (counter != n)
        {
            counter = x;
            table[x][y] = '.';
        }
        else {
            break;
        }
        y++;
    }
}

void    queensTable(int n,int x,int y)
{
    counter = 0;
    char **table = createTable(n);
    table[n - y][x - 1] = 'Q';

    solve(table,0,0,n,n - y);
    int count = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (table[i][k] == 'Q')
            {
                count++;
            }
        }
    }

    if (count != n)
    {
        printf("Puzzle is not solvable \n");
    }
    else
    {
        printf("Your Solution \n");
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                printf("%c",table[i][k]);
                printf(" ");
            }
        printf("\n");
        } 
    }

    for (int j = 0; j < n; j++)
    {
        free(table[j]);
    }
    free(table);
}

int main()
{
    queensTable(20,20,3);
    return 0;
}