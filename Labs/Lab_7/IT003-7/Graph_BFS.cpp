#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
        BFS(G, "A");
//    A B
//    B C
//    B D
//    C A
//    C D
//    D A
    //
}
