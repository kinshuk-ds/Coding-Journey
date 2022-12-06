// All pair Shortest Path

#include <bits/stdc++.h>
using namespace std;

#include <stdio.h>
int min(int, int);
void floyds(int p[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

int main()
{
    int p[10][10], w, n, e, u, v, i, j;
    ;
    cout << "\n Enter the number of vertices:";
    cin >> n;
    cout << "\n Enter the number of edges:\n";
    cin >> e;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            p[i][j] = 999;
    }
    for (i = 1; i <= e; i++)
    {
        cout << "\n Enter the end vertices of edge" << i << " with its weight \n";
        cin >> u >> v >> w;
        p[u][v] = w;
    }
    cout << "\n Matrix of input data:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << p[i][j];
        cout << "\n";
    }
    floyds(p, n);
    cout << "\n Transitive closure:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << p[i][j];
        cout << "\n";
    }
    cout << "\n The shortest paths are:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (i != j)
                cout << "\n " << i << j << p[i][j];
        }
}