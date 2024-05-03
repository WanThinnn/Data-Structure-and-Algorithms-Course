#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
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
    set<string> visited;
    visited.insert(startVertex);
    DFS(graph, startVertex, visited);
}




int main()
{
        Graph G;
        int n;
        inputGraph(G, n);
        outputGraph(G);
        DFS(G, "1");
//    A B
//    B C
//    B D
//    C A
//    C D
//    D A
    //
}
