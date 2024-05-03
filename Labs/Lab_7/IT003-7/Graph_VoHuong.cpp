#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
    string Vertex;
    Node* Next;
};

struct List
{
    Node* Head;
};

struct Graph
{
    int V;
    List* arr;
};


// Hàm tạo một đỉnh mới
Node* CreateNode(string Vertex)
{
    Node* newNode = new Node();
    newNode->Vertex = Vertex;
    newNode->Next = NULL;
    return newNode;
}

// Khởi tạo đồ thị với n đỉnh
Graph* createGraph(int n)
{
    Graph* graph = new Graph;
    graph->V = n;
    graph->arr = new List[n];
    for (int i = 0; i < n; i++)
    {
        
        graph->arr[i].Head = nullptr;
    }
    return graph;
}

//Them canh V vao danh sach lien ket tai vi tri i
void AddNext(Graph* graph, Node* Head, string V, int i)
{
    Node* newNode = CreateNode(V);
    if (Head == NULL)
    {
        graph->arr[i].Head = newNode;
    }
    else
    {
        while (Head->Next != NULL)
        {
            Head = Head->Next;
        }
        Head->Next = newNode;
    }
}


// Thêm cạnh vào đồ thị vô hướng
void AddEdge(Graph* graph, string start, string end)
{
    Node* Head;
    // Thêm cạnh từ đỉnh start - end
    int i = start[0] - 'A';
    Head = graph->arr[i].Head;
    AddNext(graph, Head, end, i);
    
    //Thêm cạnh từ đỉnh end - start
    int j = end[0] - 'A';
    Head = graph->arr[j].Head;
    AddNext(graph, Head, start, j);
}

// Xuất đồ thị
void PrintGraph(Graph* graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        Node* temp = graph->arr[i].Head;
        cout << "Đỉnh " << static_cast<char>('A' + i) << ": ";
        while (temp != NULL)
        {
            cout << temp->Vertex << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
}


void DFS(Graph* graph, int i, bool* visited)
{
    stack <int> stk;
    
    stk.push(i);
    visited[i] = true;
    cout << static_cast<char>('A' + i) << " ";
    
    while (stk.empty() == false)
    {
        int v = stk.top();
        Node* temp = graph->arr[v].Head;
        while (temp != NULL)
        {
            int j = temp->Vertex[0] - 'A';
            if (visited[j] == false)
            {
                stk.push(j);
                visited[j] = true;
                cout << static_cast<char>('A' + j) << " ";
                break;
            }
            else
                temp = temp->Next;
        }
        if (temp == NULL)
            stk.pop();
    }
}

void DFS(Graph* graph, int startVertex)
{
    bool* visited = new bool[graph->V];
    for (int i = 0; i < graph->V; i++)
    {
        visited[i] = false;
    }
    
    DFS(graph, startVertex, visited);
    
    delete[] visited;
}

int main()
{
    int n = 10; // Số lượng đỉnh trong đồ thị
    Graph* G = createGraph(n);

    // Thêm các cạnh vào đồ thị
    AddEdge(G, "A", "C");
    AddEdge(G, "A", "D");
    AddEdge(G, "A", "E");
    AddEdge(G, "A", "F");
    AddEdge(G, "F", "G");
    AddEdge(G, "F", "I");
    AddEdge(G, "I", "B");
    AddEdge(G, "B", "K");
    AddEdge(G, "K", "H");
    AddEdge(G, "H", "C");
    AddEdge(G, "D", "E");
    AddEdge(G, "E", "I");
    AddEdge(G, "K", "E");
    AddEdge(G, "D", "H");



    // Xuất đồ thị
    PrintGraph(G);

    cout << "Duyệt đồ thị theo chiều sâu (DFS) từ đỉnh A: ";
    DFS(G, 0);
    return 0;
}
