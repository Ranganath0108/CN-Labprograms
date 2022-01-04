// distance vector algorithm is based onthe belman-ford algorithm
//  Dx(y) = min { C(x,v) + Dv(y)} for each node y ∈ N
#include <stdio.h>
#include <stdlib.h>

// creating a node datatype each stores hop and cost of neighbouring nodes here rt represents routing table of that node
struct node
{
    unsigned from[20];
    unsigned dist[20];
} rt[10];

int main(int argc, char const *argv[])
{
    int i, j, cost_matrix[100][100], k, noOfNodes, count;
    printf("\n enter the number of nodes\n");
    scanf("%d", &noOfNodes);
    printf("\n Enter the costmatrix\n");
    for (i = 0; i < noOfNodes; i++)
    {
        for (j = 0; j < noOfNodes; j++)
        {
            // accepting the cosmatrix
            scanf("%d", &cost_matrix[i][j]);
            // principal diagnol eements in costmatrix is zero i.e distance from same to that is zero
            cost_matrix[i][i] = 0;
            // entering the data to the routing table
            rt[i].from[j] = j;
            rt[i].dist[j] = cost_matrix[i][j];
        }
    }

    do
    {
        count = 0;                              // if the nodes are nodes get completed count is assigned to zero hence get terminated out of the loop
        for (i = 0; i < noOfNodes; i++)         // for routing table switching
            for (j = 0; j < noOfNodes; j++)     // for distance indexing of the selected routing table
                for (k = 0; k < noOfNodes; k++) ////arbitary vertx k to compare and caluclate various distances

                    if (rt[i].dist[j] > cost_matrix[i][k] + rt[k].dist[j])
                    {
                        rt[i].from[j] = k;
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        count++;
                    }
    } while (count != 0);

    for (i = 0; i < noOfNodes; i++) // selecting which router
    {
        printf("\nFor Router %d\n\n", i);
        for (j = 0; j < noOfNodes; j++)
        {
            printf("\t\n node %d is via %d distance %d\n", j, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    return 0;
}
