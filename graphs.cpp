/*graph adjancey matr adj list ecentricity diameter radius travesals 01*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void displayAdjacencyList() {
        cout << "Adjacency List is:\n";
        for (int i = 0; i < V; ++i) {
            cout << i << " -> ";
            for (int j = 0; j < V; ++j) {
                if (adj[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix is:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfsTraversal(int start) {
        cout << "BFS Traversal starting from vertex " << start << ":\n";
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int i = 0; i < V; ++i) {
                if (adj[current][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        cout << endl;
    }

    void dfsTraversal(int start) {
        cout << "DFS Traversal starting from vertex " << start << ":\n";
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty()) {
            int current = s.top();
            cout << current << " ";
            s.pop();

            for (int i = 0; i < V; ++i) {
                if (adj[current][i] && !visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }

        cout << endl;
    }

    int bfs(int start, int& eccentricity) {
        vector<int> distance(V, INT_MAX);
        queue<int> q;
        q.push(start);
        distance[start] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < V; ++i) {
                if (adj[current][i] && distance[i] == INT_MAX) {
                    distance[i] = distance[current] + 1;
                    q.push(i);
                    eccentricity = max(eccentricity, distance[i]);
                }
            }
        }

        return eccentricity;
    }

    void findEccentricityAndCenter() {
        cout << "The eccentricities of the vertices are:\n";

        int minEccentricity = INT_MAX;
        vector<int> eccentricities(V, 0);

        for (int i = 0; i < V; ++i) {
            int eccentricity = 0;
            bfs(i, eccentricity);
            eccentricities[i] = eccentricity;
            minEccentricity = min(minEccentricity, eccentricity);
            cout << i << " = " << eccentricity << endl;
        }

        cout << "\nThe center of the graph is: ";
        for (int i = 0; i < V; ++i) {
            if (eccentricities[i] == minEccentricity) {
                cout << i << " ";
            }
        }

        cout << "\n\n";
        displayAdjacencyList();
        cout << "\n";
        displayAdjacencyMatrix();

        // Additional code to print diameter and radius
        int diameter = findDiameter();
        int radius = findRadius();

        cout << "\nDiameter of the graph: " << diameter << endl;
        cout << "Radius of the graph: " << radius << endl;

        // Additional code to print BFS and DFS traversals
        for (int i = 0; i < V; ++i) {
            bfsTraversal(i);
            dfsTraversal(i);
            cout << endl;
        }
    }

    int findDiameter() {
        int diameter = 0;

        for (int i = 0; i < V; ++i) {
            int eccentricity = 0;
            bfs(i, eccentricity);
            diameter = max(diameter, eccentricity);
        }

        return diameter;
    }

    int findRadius() {
        int radius = INT_MAX;

        for (int i = 0; i < V; ++i) {
            int eccentricity = 0;
            bfs(i, eccentricity);
            radius = min(radius, eccentricity);
        }

        return radius;
    }
};

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (e.g., 0 1 for an edge between vertices 0 and 1):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findEccentricityAndCenter();

    return 0;
}



/*graph adjancey matr adj list ecentricity diameter radius travesals ab*/


#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void displayAdjacencyList() {
        cout << "Adjacency List is:\n";
        for (int i = 0; i < V; ++i) {
            cout << (char)('A' + i) << " -> ";
            for (int j = 0; j < V; ++j) {
                if (adj[i][j] == 1) {
                    cout << (char)('A' + j) << " ";
                }
            }
            cout << endl;
        }
    }

    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix is:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfsTraversal(int start) {
        cout << "BFS Traversal starting from vertex " << (char)('A' + start) << ":\n";
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            cout << (char)('A' + current) << " ";
            q.pop();

            for (int i = 0; i < V; ++i) {
                if (adj[current][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        cout << endl;
    }

    void dfsTraversal(int start) {
        cout << "DFS Traversal starting from vertex " << (char)('A' + start) << ":\n";
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty()) {
            int current = s.top();
            cout << (char)('A' + current) << " ";
            s.pop();

            for (int i = 0; i < V; ++i) {
                if (adj[current][i] && !visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }

        cout << endl;
    }

   
    int bfs(int start, int& eccentricity) {
        vector<int> distance(V, INT_MAX);
        queue<int> q;
        q.push(start);
        distance[start] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < V; ++i) {
                if (adj[current][i] && distance[i] == INT_MAX) {
                    distance[i] = distance[current] + 1;
                    q.push(i);
                    eccentricity = max(eccentricity, distance[i]);
                }
            }
        }

        return eccentricity;
    }

    void findEccentricityAndCenter() {
        cout << "The eccentricities of the vertices are:\n";

        int minEccentricity = INT_MAX;
        vector<int> eccentricities(V, 0);

        for (int i = 0; i < V; ++i) {
            int eccentricity = 0;
            bfs(i, eccentricity);
            eccentricities[i] = eccentricity;
            minEccentricity = min(minEccentricity, eccentricity);
            cout << (char)('A' + i) << " = " << eccentricity << endl;
        }

        cout << "\nThe center of the graph is: ";
        for (int i = 0; i < V; ++i) {
            if (eccentricities[i] == minEccentricity) {
                cout << (char)('A' + i) << " ";
            }
        }

        cout << "\n\n";
        displayAdjacencyList();
        cout << "\n";
        displayAdjacencyMatrix();

        // Additional code to print diameter and radius
        int diameter = findDiameter();
        int radius = findRadius();

        cout << "\nDiameter of the graph: " << diameter << endl;
        cout << "Radius of the graph: " << radius << endl;

        // Additional code to print BFS and DFS traversals
        for (int i = 0; i < V; ++i) {
            bfsTraversal(i);
            dfsTraversal(i);
            cout << endl;
        }

       
    }

    int findDiameter() {
        int diameter = 0;

        for (int i = 0; i < V; ++i) {
            int eccentricity = 0;
            bfs(i, eccentricity);
            diameter = max(diameter, eccentricity);
        }

        return diameter;
    }

    int findRadius() {
        int radius = INT_MAX;

        for (int i = 0; i < V; ++i) {
            int eccentricity = 0;
            bfs(i, eccentricity);
            radius = min(radius, eccentricity);
        }

        return radius;
    }
};

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (e.g., AB for an edge between A and B):\n";
    for (int i = 0; i < numEdges; ++i) {
        string edge;
        cin >> edge;
        int u = edge[0] - 'A';
        int v = edge[1] - 'A';
        g.addEdge(u, v);
    }

    g.findEccentricityAndCenter();

    return 0;
}

/*topological path bfs indegree outdegree*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

// Function to find in-degree and out-degree of all vertices
void findDegree(map<int, vector<int>>& adjacencyList) {
    map<int, pair<int, int>> degrees;

    // Initialize degrees
    for (auto& entry : adjacencyList) {
        degrees[entry.first] = {0, 0};
    }

    // Calculate in-degree and out-degree
    for (auto& entry : adjacencyList) {
        int vertex = entry.first;
        for (int neighbor : entry.second) {
            degrees[vertex].second++; // Out-degree
            degrees[neighbor].first++; // In-degree
        }
    }

    // Print the result
    for (auto& entry : degrees) {
        cout << entry.first << ": " << entry.second.first << "," << entry.second.second << endl;
    }
}

// Function to print adjacency matrix
void printAdjacencyMatrix(map<int, vector<int>>& adjacencyList) {
    int maxVertex = 0;

    // Find the maximum vertex to determine the size of the matrix
    for (auto& entry : adjacencyList) {
        maxVertex = max(maxVertex, entry.first);
        for (int neighbor : entry.second) {
            maxVertex = max(maxVertex, neighbor);
        }
    }

    // Create a matrix with all elements initialized to 0
    vector<vector<int>> matrix(maxVertex + 1, vector<int>(maxVertex + 1, 0));

    // Fill the matrix based on the adjacency list
    for (auto& entry : adjacencyList) {
        int vertex = entry.first;
        for (int neighbor : entry.second) {
            matrix[vertex][neighbor] = 1;
        }
    }

    // Print the matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i <= maxVertex; ++i) {
        for (int j = 0; j <= maxVertex; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if there is a path between two vertices
bool isPath(map<int, vector<int>>& adjacencyList, int source, int destination, vector<int>& path) {
    set<int> visited;
    queue<int> q;

    q.push(source);
    visited.insert(source);

    map<int, int> parent;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjacencyList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    // Reconstruct the path
    int current = destination;
    while (parent.find(current) != parent.end()) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());

    return visited.find(destination) != visited.end();
}

// Function for BFS traversal
void BFSTraversal(map<int, vector<int>>& adjacencyList, int source) {
    queue<int> q;
    set<int> visited;

    q.push(source);
    visited.insert(source);

    cout << "The BFS sequence starting from vertex " << source << " is: ";

    while (!q.empty()) {
        int current = q.front();
        cout << current << "→";
        q.pop();

        for (int neighbor : adjacencyList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    cout << endl;
}

// Function for topological sort using DFS
void DFSUtil(int vertex, map<int, vector<int>>& adjacencyList, set<int>& visited, stack<int>& s) {
    visited.insert(vertex);

    for (int neighbor : adjacencyList[vertex]) {
        if (visited.find(neighbor) == visited.end()) {
            DFSUtil(neighbor, adjacencyList, visited, s);
        }
    }

    s.push(vertex);
}

void topologicalSort(map<int, vector<int>>& adjacencyList, int source) {
    stack<int> s;
    set<int> visited;

    for (auto& entry : adjacencyList) {
        int vertex = entry.first;
        if (visited.find(vertex) == visited.end()) {
            DFSUtil(vertex, adjacencyList, visited, s);
        }
    }

    cout << "Topological sort starting from vertex " << source << " is: ";

    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (!s.empty()) cout << " → ";
    }

    cout << endl;
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    map<int, vector<int>> adjacencyList;

    cout << "Enter the edges (format: vertex1 vertex2):" << endl;

    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adjacencyList[vertex1].push_back(vertex2);
    }

    findDegree(adjacencyList);

    printAdjacencyMatrix(adjacencyList);

    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    vector<int> path;
    if (isPath(adjacencyList, source, destination, path)) {
        cout << "Path exists from " << source << " to " << destination << " and the path is: ";
        for (int vertex : path) {
            cout << vertex;
            if (vertex != destination) cout << "→";
        }
        cout << endl;
    } else {
        cout << "No path exists from " << source << " to " << destination << "." << endl;
    }

    BFSTraversal(adjacencyList, source);

    topologicalSort(adjacencyList, source);

    return 0;
}





/*topological path bfs indegree outdegree character*/


#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

// Function to find in-degree and out-degree of all vertices
void findDegree(map<char, vector<char>>& adjacencyList) {
    map<char, pair<int, int>> degrees;

    // Initialize degrees
    for (auto& entry : adjacencyList) {
        degrees[entry.first] = {0, 0};
    }

    // Calculate in-degree and out-degree
    for (auto& entry : adjacencyList) {
        char vertex = entry.first;
        for (char neighbor : entry.second) {
            degrees[vertex].second++; // Out-degree
            degrees[neighbor].first++; // In-degree
        }
    }

    // Print the result
    for (auto& entry : degrees) {
        cout << entry.first << ": " << entry.second.first << "," << entry.second.second << endl;
    }
}

// Function to check if there is a path between two vertices
bool isPath(map<char, vector<char>>& adjacencyList, char source, char destination, vector<char>& path) {
    set<char> visited;
    queue<char> q;

    q.push(source);
    visited.insert(source);

    map<char, char> parent;

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        for (char neighbor : adjacencyList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    // Reconstruct the path
    char current = destination;
    while (parent.find(current) != parent.end()) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());

    return visited.find(destination) != visited.end();
}

// Function for BFS traversal
void BFSTraversal(map<char, vector<char>>& adjacencyList, char source) {
    queue<char> q;
    set<char> visited;

    q.push(source);
    visited.insert(source);

    cout << "The BFS sequence starting from vertex " << source << " is: ";

    while (!q.empty()) {
        char current = q.front();
        cout << current << "→";
        q.pop();

        for (char neighbor : adjacencyList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    cout << endl;
}

// Function for topological sort using DFS
void DFSUtil(char vertex, map<char, vector<char>>& adjacencyList, set<char>& visited, stack<char>& s) {
    visited.insert(vertex);

    for (char neighbor : adjacencyList[vertex]) {
        if (visited.find(neighbor) == visited.end()) {
            DFSUtil(neighbor, adjacencyList, visited, s);
        }
    }

    s.push(vertex);
}

void topologicalSort(map<char, vector<char>>& adjacencyList, char source) {
    stack<char> s;
    set<char> visited;

    for (auto& entry : adjacencyList) {
        char vertex = entry.first;
        if (visited.find(vertex) == visited.end()) {
            DFSUtil(vertex, adjacencyList, visited, s);
        }
    }

    cout << "Topological sort starting from vertex " << source << " is: ";

    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (!s.empty()) cout << " → ";
    }

    cout << endl;
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    map<char, vector<char>> adjacencyList;

    cout << "Enter the edges (format: vertex1 vertex2):" << endl;

    for (int i = 0; i < numEdges; ++i) {
        char vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adjacencyList[vertex1].push_back(vertex2);
    }

    findDegree(adjacencyList);

    char source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    vector<char> path;
    if (isPath(adjacencyList, source, destination, path)) {
        cout << "Path exists from " << source << " to " << destination << " and the path is: ";
        for (char vertex : path) {
            cout << vertex;
            if (vertex != destination) cout << "→";
        }
        cout << endl;
    } else {
        cout << "No path exists from " << source << " to " << destination << "." << endl;
    }

    BFSTraversal(adjacencyList, source);

    topologicalSort(adjacencyList, source);

    return 0;
}




/*minimum spanning tree*/




#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int a,w,b;
};
edge arr[1000000];
int parent[10001];

// function for compare the weight for sorting
bool compare(edge a,edge b)
{
    if(a.w<b.w)
     return true;
    return false;
}

// function for find the parent
int find(int a)
{
    if(parent[a]==-1)
     return a;
    else
     return find(parent[a]);
}

// function for merge two nodes
void merge(int a,int b)
{
    parent[a]=b;

}

// driver function
int main()
{
    int n,m;
    int a,b,w,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      parent[i]=-1;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i].a>>arr[i].b>>arr[i].w;

    }

    // sort the array on the basis of weight
    sort(arr,arr+m,compare);

    for(int i=0;i<m;i++)
    {
        a=find(arr[i].a);
        b=find(arr[i].b);

        // if parents of both the nodes are not same
        if(a!=b)
        {
            sum=sum+arr[i].w;
            // merge both nodes means create a edge between both node
            merge(a,b);
        }
    }
    cout<<sum;
}
