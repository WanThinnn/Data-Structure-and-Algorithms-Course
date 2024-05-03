#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

const int maxn = 100001;
const int inf = 1e9;
int* pre;
struct Graph
{
    map <int, set <pair<int, int>>> adjList;
    int V, E;
};

void Input(Graph &G)
{

    cin >> G.V >> G.E;
    for (int i = 0; i < G.E; i++)
    {
        int U, V;
        int w;
        cin >> U >> V >> w;
        G.adjList[U].insert({V, w});
        G.adjList[V].insert({U, w});
    }
}



void Dijkstra(Graph G, int S, int E)
{
    pre = new int[G.V+1];
    
    vector <long long> d(G.V + 1, inf);
    
    priority_queue <pair<int, int> , vector <pair<int, int>>, greater <pair<int, int>>> Q;
    
    d[S] = 0;
    
    Q.push({0, S});
    
    while (!Q.empty())
    {
        pair <int, int> temp;
        temp = Q.top();
        Q.pop();
        
        int U = temp.second;
        int len = temp.first;
        
        if (len > d[U])
            continue;
        
        for (auto it : G.adjList[U])
        {
            int V = it.first;
            int w = it.second;
            
            if (d[V] > d[U] + w)
            {
                d[V] = d[U] + w;
                Q.push({d[V], V});
                pre[V] = U;
            }
            
        }
    }
    
    
    for (int i = 0; i < G.V; i++)
        cout << d[i] << " ";
    cout << endl;
    cout << d[E] << endl;
}

void Output_Dijkstra(int S, int E)
{
    vector <int> path;
    
    while (true)
    {
        path.push_back(E);
        if (S == E)
            break;
        E = pre[E];
        
    }
    
    reverse(path.begin(), path.end());
    
    for (auto it : path)
        cout << it << " ";
    
    cout << endl;
}


int main()
{
    Graph G;
    Input(G);
    int Start, End;
    cin >> Start >> End;
    Dijkstra(G, Start, End);
    Output_Dijkstra(Start, End);
}

