#include <bits/stdc++.h>
using namespace std;

// Defined a class for the graph
class Graph
{
    int numVertices;     // Number of vertices in the graph
    list<int> *adjLists; // Adjacency lists for each vertex
    bool *visited;       // Array to store the visited nodes

public:
    Graph(int vertices);             // Constructor
    void addEdge(int src, int dest); // Function to add an edge
    void BFS(int startVertex);       // Function to perform BFS
};

// Initialized the graph with the given number of vertices
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

// Added an edge from source to destination
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// Performed BFS starting from the given vertex
void Graph::BFS(int startVertex)
{
    // Created a queue and add the start vertex
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    // Loop until the queue is empty
    while (!q.empty())
    {
        // Dequeue a vertex from the queue
        int front = q.front();
        q.pop();

        // Printed the vertex
        cout << front << " ";

        // Visited all the adjacent nodes of the vertex
        for (int i : adjLists[front])
        {
            if (!visited[i])
            {
                // Mark the node as visited and enqueue it
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// Main function
int main()
{
    // Created a graph with 5 vertices
    Graph g(5);

    // Add some edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Performed BFS from vertex 0
    cout << "BFS from vertex 0: ";
    g.BFS(0);

    return 0;
}
