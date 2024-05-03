#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

const int maxn = 100001;

const int inf = 1e9;
string pre[1000];
vector <long long> d;

struct Graph
{
    map <string, set <pair<string, int>>> adjList;
    int V, E;
};

void Input(Graph &G)
{

    cin >> G.V >> G.E;
    for (int i = 0; i < G.E; i++)
    {
        string U, V;
        int w;
        cin >> U >> V >> w;
        G.adjList[U].insert({V, w});
        G.adjList[V].insert({U, w});
    }
}


void Dijkstra(Graph G, string S, string E)
{
    int s = S[0] - 'A';
    d = vector<long long>(G.V, inf);
    d[s] = 0;
    
    priority_queue <pair<int, string> , vector <pair<int, string>>, greater <pair<int, string>>> Q;
    
    Q.push({0, S});
    
    while (!Q.empty())
    {
        pair <int, string> temp;
        
        temp = Q.top();
        Q.pop();
        
        string U = temp.second;
        int u = U[0] - 'A';
        int len = temp.first;
        
        if (len > d[u])
            continue;
        
        for (auto it : G.adjList[U])
        {
            string V = it.first;
            int v = V[0] - 'A';
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], V});
                pre[v] = U;
            }
        }
    }
    
   
}

void Output_Dijkstra(Graph G, string S, string E)
{
    vector <string> path;
    int e = E[0] - 'A';
    while (true)
    {
        path.push_back(E);
        if (S == E)
            break;
        E = pre[E[0] - 'A'];
        
    }
    reverse(path.begin(), path.end());
    
    cout << "Duong di: ";
    for (auto it : path)
        cout << it << " ";

    cout << "\nDo dai: " << d[e] << endl;
    
    cout << "Do dai den cac dinh con lai: ";
    for (int i = 1; i < G.V; i++)
        cout << d[i] << " ";
    cout << endl;

}


int main()
{
    Graph G;
    Input(G);
    string Start, End;
    cin >> Start >> End;
    Dijkstra(G, Start, End);
    Output_Dijkstra(G, Start, End);
}

/*
 int s = S[0] - 'A';
 vector <ll> d(G.V + 1, 10e9);
 d[s] = 0;
 
 priority_queue < pair <int, string> , vector <pair <int, string>>, greater<pair<int, string>>> Q;
 
 Q.push({0, S});
 
 while (!Q.empty())
 {
     pair <int, string> top = Q.top();
     Q.pop();
     
     string U = top.second;
     int u = U[0] - 'A';
     int length = top.first;
     
     if (length < d[u])
         continue;
     
     for (auto it : G.adjList[U])
     {
         string V = it.first;
         int w = it.second;
         int v = V[0] - 'A';
         int u = U[0] - 'A';
         if (d[v] > d[u] + w)
         {
             d[v] = d[u] + w;
             Q.push({d[v], V});
             pre[v] = U;
         }
     }
 }
 for (int i = 0; i < G.V; i++)
     cout << d[i] << " ";
 cout << endl;
 cout << d[E[0] - 'A'] << endl;
 */
