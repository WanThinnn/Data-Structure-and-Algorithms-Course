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
    map <string, set <string>> adjList;
};

// Thêm cạnh vào danh sách kề của đồ thị
void addEdge(Graph& graph,  string& u,  string& v)
{
    graph.adjList[u].insert(v);
}

// Hàm nhập thông tin đồ thị từ input
void inputGraph(Graph& graph, int& n, int &m)
{
    string u, v;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
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
            cout << y << " ";
        cout << endl;
    }
}



int main()
{
    Graph G;
    int n, m;
    inputGraph(G, n, m);
    outputGraph(G);
    cout << endl;

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
