#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "disjoint_set.cpp"
using namespace ::std;

struct Edge
{
    int weight;
    char source, dest;
};

class Graph
{
private:
    int vertices;
    vector<vector<pair<char, int>>> adjList;

    // utility method
    char toLowerCase(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
            return (ch += 32);
        return ch;
    }

    int getIndex(char ch)
    {
        return ch - 'a';
    }

public:
    Graph()
    {
        this->vertices = -1;
    }
    Graph(int vert)
    {
        vertices = vert;
        adjList.resize(vertices);
    }

    int getTotalVertices()
    {
        return vertices;
    }

    void addEdge(char source, char dest, int weight)
    {
        int sourceIndex = getIndex(toLowerCase(source)), destIndex = getIndex(toLowerCase(dest));

        adjList[sourceIndex].push_back({dest, weight});
        adjList[destIndex].push_back({source, weight});
    }

    void removeEdge(char source, char dest)
    {
        int sourceIndex = getIndex(toLowerCase(source)), destIndex = getIndex(toLowerCase(dest));

        for (int i = 0; i < adjList[sourceIndex].size(); i++)
        {
            if (adjList[sourceIndex][i].first == dest)
            {
                adjList[sourceIndex].erase(adjList[source].begin() + i);
                break;
            }
        }
        for (int i = 0; i < adjList[destIndex].size(); i++)
        {
            if (adjList[destIndex][i].first == source)
            {
                adjList[destIndex].erase(adjList[dest].begin() + i);
                break;
            }
        }
    }

    bool exists(char vertex)
    {
        int index = getIndex(toLowerCase(vertex));

        if (index <= adjList.size() - 1)
            return true;
        return false;
    }

    void displayAdjacencyList()
    {
        if (vertices == -1)
        {
            cout << "Graph is empty" << endl;
            return;
        }

        for (int i = 0; i < vertices; i++)
        {
            cout << char(i + 'a') << ": ";
            for (pair neighbour : adjList[i])
            {
                cout << " --> " << neighbour.first << " (" << neighbour.second << ")";
            }
            endl(cout);
        }
    }

    void displayEdges()
    {
        if (vertices == -1)
        {
            cout << "Graph is empty" << endl;
            return;
        }

        for (int i = 0; i < vertices; i++)
        {
            for (pair neighbour : adjList[i])
            {
                if (i < getIndex(neighbour.first))
                    cout << char(i + 'a') << " -- " << neighbour.first << " (" << neighbour.second << ")" << endl;
            }
        }
    }

    void breathFirstSearch(char start)
    {
        if (!exists(start))
        {
            cout << "Vertex doesn't exists in the Graph" << endl;
            return;
        }

        // get the correct index
        int startIndex = getIndex(toLowerCase(start));

        // start the traversal work
        bool isVisited[vertices] = {false};
        queue<char> q;
        q.push(startIndex);
        isVisited[startIndex] = true;

        int vertex;
        while (!q.empty())
        {
            vertex = q.front();
            q.pop();
            cout << char(vertex + 'a') << " ";

            for (pair<char, int> e : adjList[vertex])
            {
                int node = getIndex(e.first);
                if (!isVisited[node])
                {
                    q.push(node);
                    isVisited[node] = true;
                }
            }
        }
        cout << endl;
    }

    void depthFirstSearch(char start)
    {
        if (!exists(start))
        {
            cout << "Vertex doesn't exists in the Graph" << endl;
            return;
        }
        int startIndex = getIndex(toLowerCase(start));
        bool isVisited[vertices] = {false};
        stack<char> s;
        s.push(startIndex);
        isVisited[startIndex] = true;

        while (!s.empty())
        {
            char vertex = s.top();
            s.pop();
            cout << vertex << " ";

            for (pair<char, int> e : adjList[vertex - 'a'])
            {
                char node = e.first;
                if (!isVisited[node - 'a'])
                {
                    s.push(node);
                    isVisited[node - 'a'] = true;
                }
            }
        }
        cout << endl;
    }

    pair<int, Graph> kruskalMinimumSpanningTree()
    {
        if (vertices == -1)
        {
            cout << "Graph is empty" << endl;
            return {-1, Graph()};
        }

        int mstWeight = 0;
        Graph mst(vertices);
        // sort the edges based on their weights
        // source, destination, weight
        vector<Edge> edges;
        for (int i = 0; i < vertices; i++)
        {
            for (pair<char, int> p : adjList[i])
                edges.push_back({p.second, char(i + 'a'), p.first});
        }

        // sort the edges based on their weights
        for (int i = 0; i < edges.size(); i++)
        {
            for (int j = 0; j < edges.size() - i - 1; j++)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        DisjointSet ds(vertices);

        // adding the edges to the MST
        for (int i = 0; i < edges.size(); i++)
        {
            int source = getIndex(edges[i].source), dest = getIndex(edges[i].dest);
            if (ds.findUltParent(source) != ds.findUltParent(dest))
            {
                mstWeight += edges[i].weight;
                ds.unionByRank(source, dest);
                mst.addEdge(edges[i].source, edges[i].dest, edges[i].weight);
            }
        }
        return {mstWeight, mst};
    }
};

void displayMST(pair<int, Graph> mst)
{
    cout << "Minimal Spanning Tree Weight: " << mst.first << endl;
    mst.second.displayEdges();
}
int main()
{
    Graph g(5);
    g.addEdge('a', 'b', 2);
    g.addEdge('a', 'd', 3);
    g.addEdge('b', 'c', 3);
    g.addEdge('b', 'd', 6);
    g.addEdge('c', 'd', 5);
    g.addEdge('d', 'e', 5);
    // g.display();
    // g.breathFirstSearch('a');

    pair<int, Graph> mst = g.kruskalMinimumSpanningTree();
    displayMST(mst);
    return 0;
}