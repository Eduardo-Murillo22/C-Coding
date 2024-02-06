#include <iostream>
#include <limits.h>
using namespace std;

// Number of vertices in the graph
#define V 7

int minDistance(int dist[], bool sptSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array

void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// an adjacency matrix

int dijkstra(int graph[V][V], int src, int Find) {
    int dist[V]; // The output array. dist[i] will hold the
    // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
    // included in the shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and the total
            // weight of the path from src to v through u is
            // smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    //    printSolution(dist);
    return dist[Find];
}

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in the minimum spanning tree
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight" << endl;
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Function that implements Prim's algorithm to find the minimum spanning tree
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE, set mstSet[] as false
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include the first vertex in MST.
    key[0] = 0; // Make the key 0 so that this vertex is
                // picked as the first vertex

    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    int totalWeight =0;
    for (int i = 1; i < V; i++) {
        totalWeight += graph[i][parent[i]];
    }

    // Print the constructed MST and total weight
    printMST(parent, graph);
    cout << totalWeight << endl;
}

int main() {

    int graph[V][V] = {
        {0, 1465, 2703, 1847, 0, 0, 338},
        {1465, 0, 0, 803, 0, 1124, 1234},
        {2703, 0, 0, 868, 189, 1257, 0},
        {1847, 803, 868, 0, 743, 0, 0},
        {0, 0, 189, 743, 0, 1093, 0},
        {0, 1124, 1257, 0, 1093, 0, 2341},
        {338, 1234, 0, 0, 0, 2341, 0}
    };

    // Function call
    int LAXtoORD = dijkstra(graph, 3, 6);
    cout << "a) Find the shortest distance between ORD(3) and LAX(6): " << LAXtoORD << endl;
    int JFRtoSFO = dijkstra(graph, 4, 0);
    cout << "b) Find the shortest distance between JFK(4) and SFO(0): " << JFRtoSFO << endl;
    cout << "c) Find the minimum spanning tree:";
    primMST(graph);

    return 0;
}
