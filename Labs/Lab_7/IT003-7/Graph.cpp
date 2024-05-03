#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Graph
{
    map <string, set<string>> adjList;
};

// Thêm cạnh vào danh sách kề của đồ thị
void addEdge(Graph& graph,  string& u,  string& v)
{
    graph.adjList[u].insert(v);
}

// Hàm nhập thông tin đồ thị từ input
void inputGraph(Graph& graph, int& n)
{
    string u, v;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
//        neu la do thi vo huong thi viet them dong duoi:
//        addEdge(graph, v, u);
    }
}


void outputGraph(Graph& graph)
{
    for (auto x : graph.adjList)
    {
        cout << "Đỉnh " << x.first << ": ";
        for (auto y : x.second)
            cout << y << "  ";
        cout << endl;
    }
}


void DFS(Graph graph, string u, set<string>& visited)
{
    cout << u << " ";
    for (auto v : graph.adjList[u])
    {
        if (visited.find(v) == visited.end())
        {
            visited.insert(v);
            DFS(graph, v, visited);
        }
    }
}

void DFS(Graph graph, string startVertex)
{
    set <string> visited;
    visited.insert(startVertex);
    DFS(graph, startVertex, visited);
}

void TimDuongDi_DFS(Graph graph, string u, string U, vector <string>& visited)
{
    if (u == U)
        return;
    for (auto v : graph.adjList[u])
    {
        auto it = find(visited.begin(), visited.end(), v);
        if (it == visited.end())
        {
            visited.push_back(v);
            TimDuongDi_DFS(graph, v, U, visited);
        }
    }
}

void TimDuongDi_DFS(Graph graph, string startVertex, string endVertex)
{
    vector <string> visited;
    visited.push_back(startVertex);
    TimDuongDi_DFS(graph, startVertex, endVertex, visited);
    auto it = find(visited.begin(), visited.end(), endVertex);
    if (it == visited.end())
        cout << "Khong co duong di\n";
    else
        for (auto i : visited)
        {
            if (i != endVertex)
                cout << i << " ";
            else if (i == endVertex)
            {
                cout << i << " ";
                break;
            }
        }
   
}

void BFS(Graph graph, string u, set<string>& visited)
{
    queue <string> q;
    q.push(u);
    while (q.empty() == false)
    {
        string v = q.front();
        q.pop();
        cout << v << " ";
        for (auto x : graph.adjList[v])
        {
            if (visited.find(x) == visited.end())
            {
                visited.insert(x);
                q.push(x);
            }
        }
    }
}

void BFS(Graph graph, string startVertex)
{
    set <string> visited;
    visited.insert(startVertex);
    BFS(graph, startVertex, visited);
}


int main()
{
    Graph G;
    int n;
    inputGraph(G, n);
    outputGraph(G);
    DFS(G, "1");
    cout << endl;
    TimDuongDi_DFS(G, "1", "6");
//    cout << endl;
//    BFS(G, "U");
//    A B
//    B C
//    B D
//    C A
//    C D
//    Đỉnh M: Q  U
//    Đỉnh Q: I  M
//    Đỉnh U: K  Q  W
//    U K Q I
//    D A
    //M Q M U Q I Q M U K U Q U W

}
