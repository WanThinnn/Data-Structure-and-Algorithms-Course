#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

struct Graph
{
    map <string, set <string>> adjList;
};

struct Dothi
{
    vector <vector <int>> adjMatrix;
};

void InputG(Graph &G)
{
    int n;
    cout << "Danh sach canh: ";
    cin >> n;
    string u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        G.adjList[u].insert(v);
    }
}

void OutputG(Graph G)
{
    for (auto u : G.adjList)
    {
        cout << "Dinh " << u.first << ": ";
        for (auto v : u.second)
            cout << v << " ";
        cout << endl;
    }
}

void DFS(Graph G, string u, set <string> &visited)
{
    cout << u << " ";
    for (auto v : G.adjList[u])
    {
        if (visited.find(v) == visited.end())
        {
            visited.insert(v);
            DFS(G, v, visited);
        }
    }
}

void DFS(Graph G, string u)
{
    set <string> visited;
    visited.insert(u);
    DFS(G, u, visited);
}





int main()
{
    Graph A;
    InputG(A);
    OutputG(A);
    cout << endl;
    DFS(A, "A");
}
