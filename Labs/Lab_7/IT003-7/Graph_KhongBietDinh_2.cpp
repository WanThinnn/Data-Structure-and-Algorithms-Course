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
//    graph.adjList[v].insert(u);
}

// Hàm nhập thông tin đồ thị từ input
void inputGraph(Graph& graph, int numEdges)
{
    for (int i = 0; i < numEdges; i++)
    {
        string u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }
}

void depthFirstSearch(Graph graph, string start)
{
    set <string> visited;
    stack <string> stack;
    stack.push(start);

    while (!stack.empty())
    {
        string current = stack.top();
        stack.pop();

        if (visited.find(current) == visited.end())
        {
            visited.insert(current);
            cout << current << " ";
        
            for (string neighbor : graph.adjList[current])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    stack.push(neighbor);
                }
            }
        }
    }
    cout << endl;
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
         set<string> neighbors = entry.second;

        cout << "Đỉnh " << u << ": ";
        for (auto neighbor : neighbors)
        {
            cout << neighbor << "  ";
        }
        cout << endl;
    }
    
    depthFirstSearch(graph, "A");


    return 0;
}
