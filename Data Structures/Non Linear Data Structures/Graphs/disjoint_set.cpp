#include <iostream>
using namespace ::std;
class DisjointSet
{
private:
    int *parent, *rank, *size, vertices;

public:
    DisjointSet(int vert)
    {
        this->vertices = vert;
        parent = new int[vertices];
        rank = new int[vertices];

        // at start all vertices are parent of themselves and have size of 1
        for (int i = 0; i < vertices; i++)
        {
            parent[i] = i;
            // size[i] = 1;
            rank[i] = 0;
        }
    }

    // find the ultimate parent of a vertex by compressing the path to the ultimate parent from the given vertex
    int findUltParent(int vertex)
    {
        if (parent[vertex] == vertex)
            return vertex;

        return parent[vertex] = findUltParent(parent[vertex]);
    }

    // merge the disjoint subsets of the two vertices according to their size
    void unionBySize(int vertex1, int vertex2)
    {
        int ultParentV1 = findUltParent(vertex1), ultParentV2 = findUltParent(vertex2);

        // belong to same subset
        if (ultParentV1 == ultParentV2)
            return;

        if (size[ultParentV1] > size[ultParentV2])
        {
            parent[ultParentV2] = ultParentV1;
            size[ultParentV1] += size[ultParentV2];
        }
        else if (size[ultParentV2] > size[ultParentV1])
        {
            parent[ultParentV1] = ultParentV2;
            size[ultParentV2] += size[ultParentV1];
        }
        else
        {
            parent[ultParentV1] = ultParentV2;
            size[ultParentV2] += size[ultParentV1];
        }
    }

    // merge the disjoint subsets of the two vertices according to their rank
    void unionByRank(int vertex1, int vertex2)
    {
        int ultParentV1 = findUltParent(vertex1), ultParentV2 = findUltParent(vertex2);

        if (ultParentV1 == ultParentV2)
            return;

        // setting ultimate parent of the vertex with lower rank as the parent of the vertex with higher rank
        if (rank[ultParentV1] > rank[ultParentV2])
            parent[ultParentV2] = ultParentV1;
        else if (rank[ultParentV2] > rank[ultParentV1])
            parent[ultParentV1] = ultParentV2;
        // if both have same rank, then anyone can be parent of other
        else
        {
            parent[ultParentV1] = ultParentV2;
            // rank of the parent of the vertex with which the vertex is attached is increased by 1
            rank[ultParentV2]++;
        }
    }
};

// int main()
// {
//     DisjointSet ds(5);
//     ds.unionByRank(0, 2);
//     ds.unionByRank(4, 1);
//     ds.unionByRank(3, 1);
//     if (ds.findUltParent(4) == ds.findUltParent(2))
//         cout << "Belong to same disjoint subset\n";
//     else
//         cout << "No, they don't belong to same disjoint subset\n";

//     if (ds.findUltParent(4) == ds.findUltParent(2))
//         cout << "Belong to same disjoint subset\n";
//     else
//         cout << "No, they don't belong to same disjointsub set\n";
//     return 0;
// }