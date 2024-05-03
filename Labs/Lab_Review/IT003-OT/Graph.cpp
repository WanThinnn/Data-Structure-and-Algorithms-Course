//
//  Graph.cpp
//  IT003-OT
//
//  Created by Thinnn on 23/06/2023.
//

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
    vector <int, vector <int>> adjMatrix;
};

void InputG(Graph &G, int &n)
{
    cout << "Danh sach canh: ";
    cin >> n;
    string u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        G.adjList[u].insert(v);
//        G.adjList[v].insert(u);
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

void mapDFS(Graph G, string u, string v, vector <string> &visited)
{
    if (u == v)
        return;
    for (auto x : G.adjList[u])
    {
        auto it = find(visited.begin(), visited.end(), x);
        auto temp = find(visited.begin(), visited.end(), v);
        if (it == visited.end() and temp == visited.end())
        {
            visited.push_back(x);
            mapDFS(G, x, v, visited);
        }
        if (x == v)
            break;
    }
    
}

void mapDFS(Graph G, string u, string v)
{
    vector <string> visited;
    visited.push_back(u);
    mapDFS(G, u, v, visited);
    
    auto it = find(visited.begin(), visited.end(), v);
    
    if (it == visited.end())
        cout << "khong co duong di!\n";
    else
        for (auto i : visited)
            cout << i << " ";
}

void BFS(Graph G, string u, set <string> &visited)
{
    queue <string> q;
    q.push(u);
    while (!q.empty())
    {
        string v;
        v = q.front();
        q.pop();
        cout << v << " ";
        for (auto x : G.adjList[v])
        {
            if (visited.find(x) == visited.end())
            {
                visited.insert(x);
                q.push(x);
            }
        }
    }
}

void BFS(Graph G, string u)
{
    set <string> visited;
    visited.insert(u);
    BFS(G, u, visited);
}

void mapBFS(Graph G, string u, string v, vector <string> &visited)
{
    if (u == v)
        return;
    queue <string> q;
    q.push(u);
    while (!q.empty())
    {
        string k = q.front();
        q.pop();
        for (auto x : G.adjList[k])
        {
            
            auto it = find(visited.begin(), visited.end(), x);
            
            if (it == visited.end())
            {
                visited.push_back(x);
                q.push(x);
                if (x == v)
                    return;
            }
        }
    }
}

void mapBFS(Graph G, string u, string v)
{
    vector <string> visited;
    visited.push_back(u);
    mapBFS(G, u, v, visited);
    auto it = find(visited.begin(), visited.end(), v);
    if (it == visited.end())
        cout << "Khong co duong di!";
    else
        for (auto i : visited)
            cout << i << " ";
}

int main()
{
    Graph G;
    int n;
    InputG(G, n);
    OutputG(G);
    cout << "DFS\n";
    DFS(G, "a");
    cout << endl;
    mapDFS(G, "a", "d");
    cout << endl;
    
    cout << "BFS\n";
    BFS(G, "a");
    cout << endl;
    mapBFS(G, "a", "d");
    cout << endl;

    /*
     A B A C A F B D B C C E C D D F E F E G
     */
}
