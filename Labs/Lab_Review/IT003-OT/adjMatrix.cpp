//
//  adjMatrix.cpp
//  IT003-OT
//
//  Created by Thinnn on 27/06/2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Graph
{
    int V, E;
    int **maxtrixList;
};

void Input(Graph &G, int n, int m)
{
    cin >> n >> m;
    G.V = n;
    G.E = m;
    
    G.maxtrixList = new int*[G.V];
    
    for (int i = 1; i <= n; i++)
    {
        G.maxtrixList[i] = new int[G.V];
        for (int j = 1; j <= n; j++)
            G.maxtrixList[i][j] = 0;
    }
    
    for (int i = 1; i <= m; i++)
    {
        int U, V;
        cin >> U >> V;
        G.maxtrixList[U][V] = 1;
        G.maxtrixList[V][U] = 1;
    }
}
void OutputG(Graph G)
{
    cout << "Danh sach ke tuong ung voi Danh sach canh: " << endl;
    for (int i = 1; i <= G.V; i++)
    {
        for (int j = 1; j <= G.V; j++)
            cout << G.maxtrixList[i][j] << " ";
    cout << endl;
    }
}
int main()
{
    Graph G;
    int n = 0, m = 0;
    Input(G, n, m);
    OutputG(G);
}
