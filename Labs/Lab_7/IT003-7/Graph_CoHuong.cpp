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

// Hàm khởi tạo đồ thị với n đỉnh
Graph* CreateGraph(int n)
{
	Graph* graph = new Graph();
	graph->V = n;

	// Tạo mảng danh sách kề có n phần tử
	graph->arr = new List[n];

	// Khởi tạo danh sách kề của mỗi đỉnh
	for (int i = 0; i < n; i++)
	{
		graph->arr[i].Head = NULL;
	}

	return graph;
}

//Them dinh V vao danh sach lien ket tai vi tri i
void AddNext(Graph* graph, Node* head, string V, int i)
{
    Node* newNode = CreateNode(V);
    if (head == NULL)
    {
        graph->arr[i].Head = newNode;
    }
    else
    {
        while (head->Next != NULL)
        {
            head = head->Next;
        }
        head->Next = newNode;
    }
}

// Hàm thêm cạnh vào đồ thị
void AddEdge(Graph* graph, string start, string end)
{
	// Tạo một cạnh từ start - end
    int i = start[0] - 'A';
	Node* head = graph->arr[i].Head;
    AddNext(graph, head, end, i);
}

// Hàm xuất đồ thị
void PrintGraph(Graph* graph)
{
	for (int i = 0; i < graph->V; i++)
	{
		Node* head = graph->arr[i].Head;
		cout << "Đỉnh " << char('A' + i) << ": ";

		while (head != NULL)
		{
			cout << head->Vertex << " ";
			head = head->Next;
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
	int n = 4; // Số lượng đỉnh của đồ thị
	Graph* G = CreateGraph(n);

	// Thêm các cạnh vào đồ thị
    AddEdge(G, "A", "B");
    AddEdge(G, "B", "C");
    AddEdge(G, "B", "D");
    AddEdge(G, "C", "A");
    AddEdge(G, "C", "D");
    AddEdge(G, "D", "A");

	// Xuất đồ thị
    PrintGraph(G);

    cout << "Duyet do thi: " << endl;
    DFS(G, 0);
	return 0;
}
