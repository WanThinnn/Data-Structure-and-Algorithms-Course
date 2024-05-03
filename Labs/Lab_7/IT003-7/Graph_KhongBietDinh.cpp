#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct Graph
{
    map <string, set < pair <string, int> > > adjList;
};

// Thêm cạnh vào danh sách kề của đồ thị
void addEdge(Graph& graph,  string& u,  string& v, int& weight)
{
    graph.adjList[u].insert({v, weight});
//    graph.adjList[v].insert({u, weight}); // Với đồ thị vô hướng, ta cần thêm cả hai chiều
}

// Hàm nhập thông tin đồ thị từ input
void inputGraph(Graph& graph, int numEdges)
{
    for (int i = 0; i < numEdges; i++)
    {
        string u, v;
        int weight;
        cin >> u >> v >> weight;
        addEdge(graph, u, v, weight);
    }
}

int main()
{
    int numEdges;
    cin >> numEdges;

    Graph graph;
    inputGraph(graph, numEdges);

    // In danh sách kề của đồ thị
    for (auto entry : graph.adjList)
    {
         string u = entry.first;
         set<pair<string, int>> neighbors = entry.second;

        cout << "Đỉnh " << u << ": ";
        for (auto neighbor : neighbors)
        {
            cout << neighbor.first << "(" << neighbor.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
