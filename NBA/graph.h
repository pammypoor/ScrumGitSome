#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<fstream>
#include<QDebug>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
#include<utility>
#include<bits/stdc++.h>
#include"filesused.h"
#include<sstream>
#include<QFile>
#include<functional>
#include <QTextBrowser>
using namespace std;

/*******************************************************************************
 * CLASS Graph
 *------------------------------------------------------------------------------
 * This template class is used to represent a graph it stores a list of vertices
 * along with a list of edges; The edge is implemented in an adjacency list
 * structure.
 ******************************************************************************/
template<typename VertexType, typename WeightType>
class Graph
{
    public:
        class Edge;      // forward declaration
        class Vertex;    // forward declaration

        typedef typename list<Vertex>::iterator VertexIt;
        typedef typename list<Edge>::iterator EdgeIt; // not needed have a 2d array

        /**********************************************************************
         * CLASS Vertex
         *--------------------------------------------------------------------
         * This class is part of the member class Graph it is used to represent
         * an individual vertex: it has the ability to store a list of
         * incident edges to the vertex
         **********************************************************************/
        class Vertex
        {
            friend class Graph;
            Vertex(const VertexType& v, int distinctI)
            {
                vertexElem = v;
                i = distinctI;
            }
            VertexType vertexElem;
            int i;                       //distinct integer i for each vertex
        };

        /**********************************************************************
         * CLASS Edge
         *-------------------------------------------------------------------
         * This class is part of the member class Graph it is used to represent
         * an individual Edge: it has the capability to store its incident
         * Vertices in a pair of VertexIterator. Since a edge can only have
         * two incident pairs a list is not used in this representation
         **********************************************************************/
        class Edge
        {
            friend class Graph;

            Edge(const pair<VertexIt, VertexIt>& vp, const WeightType& w)
            :incidentVertices(vp), weight(w), null(false) {}
        public:
            Edge()
            {
                VertexIt rVIt;
                incidentVertices = make_pair(rVIt, rVIt);
                weight = 0;
                null = true;
            }

            bool operator > (const Edge& rhs) const
            {
                return (weight > rhs.weight);
            }
            bool operator < (const Edge& rhs) const
            {
                return (weight < rhs.weight);
            }
        private:
            VertexIt adjVertexTo(const VertexIt& v)
            {
                if(incidentVertices.first == v)
                {
                    return incidentVertices.second;
                }
                return incidentVertices.first;
            }
            WeightType getWeight()
            {
                return weight;
            }

            pair<VertexIt, VertexIt> incidentVertices;
            WeightType weight;
            bool null;
        };

        /**********************************************************************
         * STRUCT Link
         *--------------------------------------------------------------------
         * This public class has the ability to create a link in the graph class
         * it has a vertexPair that will contain the two vertices one would
         * like to link as well as the weight for their edge.
         * Mimics an insert edge from the Graph ADT
         **********************************************************************/
        struct Link
        {
            Link(const pair<VertexType, VertexType>& vp, const WeightType& w)
            :vertexPair(vp), weight(w) {}

            pair<VertexType, VertexType> vertexPair; // like two strings
            WeightType weight;                       // weight when adding
        };

        //CONSTRUCTOR - template constructor used to initialize the graph
        template<typename ItType> Graph(ItType lnBegin, const ItType& lnEnd, const int size)
        {
            maxSize = size;

            adjacencyMatrix.resize(size, vector<Edge>(size, Edge()));

            sum = 0;
            uniqueInt = 0;

            vertices.push_back(Vertex(lnBegin->vertexPair.first, uniqueInt));
            qDebug() << "Adding links: " << endl;
            for(;lnBegin != lnEnd; ++lnBegin)
            {
                if(addLink(*lnBegin) == true)
                {
                    qDebug() << "Adding ";
                }
                else
                {
                    qDebug() << "Skiping ";
                }
                qDebug() << lnBegin->vertexPair.first
                     << "<-" << lnBegin->weight << "->"
                     << lnBegin->vertexPair.second
                     << endl;
            }
        }

        //DESTRUCTOR
        ~Graph() {}

        //METHOD - adds a link to the graph given a pair
        bool addLink(const Link& ln)
        {
            VertexIt fVertexKey = findVertex(ln.vertexPair.first);
            VertexIt sVertexKey = findVertex(ln.vertexPair.second);
            VertexIt missing = vertices.end();

            if(fVertexKey != missing || sVertexKey != missing)
            {

                if(fVertexKey == missing)
                {
                    uniqueInt++;
                    Vertex newVertex(ln.vertexPair.first, uniqueInt);
                    vertices.push_back(newVertex);
                    fVertexKey = --vertices.end();
                }
                if(sVertexKey == missing)
                {
                    uniqueInt++;
                    Vertex newVertex(ln.vertexPair.second, uniqueInt);
                    vertices.push_back(newVertex);
                    sVertexKey = --vertices.end();
                }

                Edge newEdge(make_pair(fVertexKey, sVertexKey), ln.weight);
                edges.push_back(newEdge);

                //put edge in the adjacency matrix
                int row = fVertexKey->i;
                int col = sVertexKey->i;
//				cout << "row col: " << row << col << " ";
                adjacencyMatrix[row][col] = newEdge;
                adjacencyMatrix[col][row] = newEdge; // undirected
                return true;
            }
            if(fVertexKey == missing && sVertexKey == missing)
            {
                if(fVertexKey == missing)
                {
                    uniqueInt++;
                    Vertex newVertex(ln.vertexPair.first, uniqueInt);
                    vertices.push_back(newVertex);
                    fVertexKey = --vertices.end();
                }
                if(sVertexKey == missing)
                {
                    uniqueInt++;
                    Vertex newVertex(ln.vertexPair.second, uniqueInt);
                    vertices.push_back(newVertex);
                    sVertexKey = --vertices.end();
                }

                Edge newEdge(make_pair(fVertexKey, sVertexKey), ln.weight);
                edges.push_back(newEdge);

                //put edge in the adjacency matrix
                int row = fVertexKey->i;
                int col = sVertexKey->i;
//				cout << "row col: " << row << col << " ";
                adjacencyMatrix[row][col] = newEdge;
                adjacencyMatrix[col][row] = newEdge; // undirected
                return true;
            }
            return false;
        }

        //METHOD - finds a vertex given a VertexType
        VertexIt findVertex(const VertexType& k)
        {
            VertexIt it = vertices.begin();
            VertexIt itEnd = vertices.end();
            for(; it != itEnd; ++it)
            {
                if(it->vertexElem == k)
                {
                    return it;
                }
            }
            return itEnd;
        }
        //findVertex: given a uniqueInt obtain the vertex
        VertexIt findVertex(int k)
        {
            VertexIt it = vertices.begin();
            VertexIt itEnd = vertices.end();
            for(; it != itEnd; ++it)
            {
                if(it->i == k)
                {
                    return it;
                }
            }
            return itEnd;
        }

        //METHOD - takes in a v returns a list of edge iterators
        list<Edge> returnListOfIncidentEdges(const VertexIt& v)
        {
            list<Edge> incidentEdgesV;
            int row = v->i;
            for(int col = 0; col < maxSize; col++)
            {
//				cout << " col: " << col;
                Edge incidentEdge = adjacencyMatrix[row][col];
                if(incidentEdge.null != true)
                {
                    incidentEdgesV.push_back(adjacencyMatrix[row][col]);
//					cout << "NEW EDGE: " << incidentEdge.weight;
                }
            }

            return incidentEdgesV;
        }

        //METHOD - dfs traversal recursive implementation
        void dfs(const VertexIt& v, map<VertexType, bool>& visited, QVector<QString> &dfsTeam)
        {


            visited[v->vertexElem] = true;
            dfsTeam.push_back(v->vertexElem);

            list<Edge> incList = returnListOfIncidentEdges(v);

            EdgeIt it = incList.begin();
            EdgeIt itEnd = incList.end();

            vector<WeightType> incidentWeights;
            for(; it != itEnd; ++it)
            {
                WeightType temp = it->getWeight();
                incidentWeights.push_back(temp);
//              cout << " " << temp << " ";
            }
            //find smallest edge
            std::sort(incidentWeights.begin(), incidentWeights.end());
//            cout << " s:" << incidentWeights[0] << " ";

            //now search for the adj vertex with the smallest edge;
            incList = returnListOfIncidentEdges(v);
            it = incList.begin();
            itEnd = incList.end();

            unsigned int index = 0;
            while( it != itEnd && index != incidentWeights.size())
            {
                if(it->getWeight() == incidentWeights[index])
                {
                    VertexIt w = it->adjVertexTo(v);
                    if(!visited[w->vertexElem])
                    {
                        sum = sum + incidentWeights[index];

                        dfs(w, visited, dfsTeam);
                    }
                    if(visited[w->vertexElem])
                    {
                        it = incList.begin();
                    }
                    index++;
                }
                else // new was just it++ without else causing error
                {
                    it++;
                } //END IF
            } // END WHILE

        }

        //METHOD - dfs used as interface for calling the dfs algorithm
        void dfs(const VertexType& start)
        {
            QVector<QString> dfsTeams;
            map<VertexType, bool> visited;
            dfs(findVertex(start), visited, dfsTeams);
            QFile fin(DFSFILE);
            if(!fin.open(QFile::WriteOnly | QFile::Text))
            {
                qDebug() << "Could not open file";
                return;
            }

            QTextStream out(&fin);

            for(int count = 0; count < dfsTeams.size(); count++)
            {
                out << dfsTeams.at(count) << "\n";
            }

            out << "\n\nTotal distance traveled: " << sum << "\n\n";
            fin.flush();
            fin.close();
        }

        //METHOD - breadth first traversal yet to be modified
        void bfs(const VertexType& start)
        {
            QFile fin(BFSFILE);
            if(!fin.open(QFile::WriteOnly | QFile::Text))
            {
                qDebug() << "Could not open file";
                return;
            }
            QTextStream out(&fin);

            map<VertexType, bool> visited;
            queue<VertexIt> q;

            sum = 0;
            VertexIt v = findVertex(start);
            q.push(v);
            visited[v->vertexElem] = true;
            out << v->vertexElem << "\n";

            list<Edge> incList = returnListOfIncidentEdges(v);
            EdgeIt it = incList.begin();
            EdgeIt itEnd = incList.end();
            vector<WeightType> incidentWeights;
            for(; it != itEnd; ++it)
            {
                WeightType temp = it->getWeight();
                incidentWeights.push_back(temp);
            }
            //find smallest edge
            std::sort(incidentWeights.begin(), incidentWeights.end());
            unsigned int index = 0;  //for choosing the smallest

            while(!q.empty())
            {
                v = q.front();
                q.pop();
                list<Edge> incList;
                EdgeIt it;
                EdgeIt itEnd;
                if(index == 0)
                {
                    incList = returnListOfIncidentEdges(v);
                    it = incList.begin();
                    itEnd = incList.end();
                }
                else
                {
                    incList = returnListOfIncidentEdges(v);
                    it = incList.begin();
                    itEnd = incList.end();
                    for(; it != itEnd; ++it)
                    {
                        WeightType temp = it->getWeight();
                        incidentWeights.push_back(temp);
                    }
                    std::sort(incidentWeights.begin(), incidentWeights.end());
                    index = 0;
                    incList = returnListOfIncidentEdges(v);
                    it = incList.begin();
                    itEnd = incList.end();
                }


                while( it != itEnd && index != incidentWeights.size())
                {
                    if(it->getWeight() == incidentWeights[index])
                    {
                        VertexIt w = it->adjVertexTo(v);
                        if(!visited[w->vertexElem])
                        {
                            out << w->vertexElem << "\n";
                            sum = sum + it->getWeight();
                            q.push(w);
                            visited[w->vertexElem] = true;
                            index++;
                            it = incList.begin();
                        }
                        else
                        {
                            //cross edge
                            index++;
                            it = incList.begin();
                        }
                    }
                    else
                    {
                        it++;
                    }
                }
                incidentWeights.clear();
            }
            out << "\n\nTotal distance traveled: " << sum << "\n\n";
            fin.flush();
            fin.close();
        }

        //METHOD - breadth first traversal yet to be modified
        void bfsDiscoveryCrossEdges(const VertexType& start)
        {
            map<VertexType, bool> visited;
            queue<VertexIt> q;
            vector<WeightType> discoveryEdges;
            typename vector<WeightType>::iterator disIt;

            sum = 0;
            VertexIt v = findVertex(start);
            q.push(v);
            visited[v->vertexElem] = true;
//			cout << " " << v->vertexElem;

            list<Edge> incList = returnListOfIncidentEdges(v);
            EdgeIt it = incList.begin();
            EdgeIt itEnd = incList.end();
            vector<WeightType> incidentWeights;
            for(; it != itEnd; ++it)
            {
                WeightType temp = it->getWeight();
                incidentWeights.push_back(temp);
            }
            //find smallest edge
            std::sort(incidentWeights.begin(), incidentWeights.end());
            unsigned int index = 0;  //for choosing the smallest

            while(!q.empty())
            {
                v = q.front();
                q.pop();
                list<Edge> incList;
                EdgeIt it;
                EdgeIt itEnd;
                if(index == 0)
                {
                    incList = returnListOfIncidentEdges(v);
                    it = incList.begin();
                    itEnd = incList.end();
                }
                else
                {
                    incList = returnListOfIncidentEdges(v);
                    it = incList.begin();
                    itEnd = incList.end();
                    for(; it != itEnd; ++it)
                    {
                        WeightType temp = it->getWeight();
                        incidentWeights.push_back(temp);
                    }
                    std::sort(incidentWeights.begin(), incidentWeights.end());
                    index = 0;
                    incList = returnListOfIncidentEdges(v);
                    it = incList.begin();
                    itEnd = incList.end();
                }


                while( it != itEnd && index != incidentWeights.size())
                {
                    if(it->getWeight() == incidentWeights[index])
                    {
                        VertexIt w = it->adjVertexTo(v);
                        if(!visited[w->vertexElem])
                        {
                            discoveryEdges.push_back(incidentWeights[index]);
                            cout << "From: " << v->vertexElem << " -("
                                 << incidentWeights[index] << ")-> " << w->vertexElem
                                 << " is a DISCOVERY Edge." << endl;
                            sum = sum + it->getWeight();
                            q.push(w);
                            visited[w->vertexElem] = true;
                            index++;
                            it = incList.begin();
                        }
                        else
                        {
                            disIt = std::find(discoveryEdges.begin(), discoveryEdges.end(), it->getWeight());
                            if(disIt == discoveryEdges.end())
                            {
                                cout << "From: " << v->vertexElem << " -("
                                     << incidentWeights[index] << ")-> " << w->vertexElem
                                     << " is a CROSS Edge." << endl;
                                discoveryEdges.push_back(incidentWeights[index]);
                            }
                            index++;
                            it = incList.begin();
                        }
                    }
                    else
                    {
                        it++;
                    }
                }
                incidentWeights.clear();
            }
        }

        //METHOD - for interface used to call the other method recursively
        void discoveryEdges(const VertexType& start)
        {
            map<VertexType, bool> visited;  //CALC - used to check vertex visited
            OutputDiscoveryEdges(findVertex(start), visited);
        }

        //METHOD - used to output the discovery edges recursively goes through the dfs
        //         in order to output the corresponding edges
        void OutputDiscoveryEdges(const VertexIt& v, map<VertexType, bool>& visited)
        {
            visited[v->vertexElem] = true;

            typename list<EdgeIt>::iterator it = v->getIncidentEdges().begin();
            typename list<EdgeIt>::iterator itEnd = v->getIncidentEdges().end();

            vector<WeightType> incidentWeights; // CALC - stores incident weights
                                                //        to vertex
            for(; it != itEnd; ++it)
            {
                WeightType temp = (*it)->getWeight();
                incidentWeights.push_back(temp);
            }
            //find smallest edge
            std::sort(incidentWeights.begin(), incidentWeights.end());
            it = v->getIncidentEdges().begin();
            itEnd = v->getIncidentEdges().end();

            unsigned int index = 0;
            while( it != itEnd && index != incidentWeights.size())
            {
                if((*it)->getWeight() == incidentWeights[index])
                {
                    VertexIt w = (*it)->adjVertexTo(v);
                    if(!visited[w->vertexElem])
                    {
                        cout << "Discovery Edge: " << incidentWeights[index];
                        cout << endl;
                        OutputDiscoveryEdges(w, visited);
                    }
                    if(visited[w->vertexElem])
                    {
                        it = v->getIncidentEdges().begin();
                    }
                    index++;
                }
                else
                {
                    it++; // check the next incident edge if matches with smallest
                          // weight
                }
            }
        }

        //METHOD - returns the sum of the discovery edges
        double OutputSum()
        {
            return sum;
        }

        //METHOD - prints graph to the console with vertices and their corresponding
        //         vertices to their incident edges
        void PrintGraph()
        {
            qDebug() << endl << "GRAPH: " << endl;
            //Loop - loops through the vertices with a VertexIt typedef above
            for(VertexIt vIt = vertices.begin(); vIt != vertices.end(); vIt++)
            {
                qDebug() << left << (*vIt).vertexElem << " -> ";
                list<Edge> incList = returnListOfIncidentEdges(vIt);
                typename list<Edge>::iterator it = incList.begin();
                typename list<Edge>::iterator itEnd = incList.end();
                //Loop - loops through the vertices adjacent to this vertex
                for(; it != itEnd; it++)
                {
                    qDebug() << it->adjVertexTo(vIt)->vertexElem << ", ";
                }
                qDebug() << endl;
            }
            qDebug() << right;
        }

        //Dijkstra - returns a vector of vertexType, and returns the cost through modifying
        //           the cost parameter
        QVector<VertexType> Dijkstra(const VertexType& start, const VertexType& end, double& cost)
        {
            double dist[maxSize]; // The output array. dist[i] will hold the shortest
                         // distance from v to i
            int parent[maxSize];
            bool sptSet[maxSize]; // sptSet[i] will be true if vertex i is included
                                  // in the shortest path tree


//            //Initialize all distance as INFINTE and stpSet[] as false;
//            for(int i = 0; i < maxSize; i++)
//            {
//                dist[i] = INT_MAX;
//                sptSet[i] = false;
//                parent[i] = 0;
//            }
//            parent[findVertex(start)->i] = -1;

//            dist[findVertex(start)->i] = 0;
//            for(int count = 0; count < maxSize; count++)
//            {
//                int u = minDistance(dist, sptSet);
//                sptSet[u] = true;
//                for(int w = 0; w < maxSize - 1; w++)
//                {
//                    //zero weight ?
//                    if(!sptSet[w] && adjacencyMatrix[u][w].weight && dist[u] != INT_MAX
//                                  && dist[u] + (adjacencyMatrix[u][w].weight) < dist[w])
//                    {
//                        dist[w] = dist[u] + adjacencyMatrix[u][w].weight;
//                        parent[w] = u;
//                    }


//                }
//            }

//            printSolution(dist, parent, start); // prints all the solutions


            // Create a priority queue to store vertices that
            // are being preprocessed. This is weird syntax in C++.
            // Refer below link for details of this syntax
            // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
            priority_queue< pair<double, int> , vector < pair<double, int> > , greater< pair<double, int> > > pq;

            // Create a vector for distances and initialize all
            // distances as infinite (INF)
            for(int i = 0; i < maxSize; i++)
            {
                dist[i] = INT_MAX;
                parent[i] = 0; // crashing?
            }

            // Insert source itself in priority queue and initialize
            // its distance as 0.
            pq.push(make_pair(0, findVertex(start)->i));
            parent[findVertex(start)->i] = -1;
            dist[findVertex(start)->i] = 0;

            /* Looping till priority queue becomes empty (or all
              distances are not finalized) */
            while (!pq.empty())
            {
                // The first vertex in pair is the minimum distance
                // vertex, extract it from priority queue.
                // vertex label is stored in second of pair (it
                // has to be done this way to keep the vertices
                // sorted distance (distance must be first item
                // in pair)
                int u = pq.top().second;
                pq.pop();

                list<Edge> adjEdgesOfVertex = returnListOfIncidentEdges(findVertex(u));

                for(typename list<Edge>::iterator it = adjEdgesOfVertex.begin();
                    it != adjEdgesOfVertex.end(); it++)
                {
                    //Get Vertex label and weight of current adjacent
                    // of u
                    int v = it->adjVertexTo(findVertex(u))->i;
                    double weight = it->weight;

                    if(dist[v] > dist[u] + weight)
                    {
                        dist[v] = dist[u] + weight;
                        pq.push(make_pair(dist[v], v));
                        parent[v] = u;
                    }
                }
            }

            QVector<VertexType> shortestPath;
            shortestPath = GetDijkstraPath(start, end, dist, parent);// returns a list of VertexType's
            cost = GetDijkstraCost(end, dist);

            return shortestPath;
        }

        //changed
    protected:
        double GetDijkstraCost(const VertexType& end, double dist[])
        {
            int endingUniqInt;

            endingUniqInt = findVertex(end)->i;
            return dist[endingUniqInt];
        }

        QVector<VertexType> GetDijkstraPath(const VertexType& start,
                                            const VertexType& end,
                                            double dist[], int parent[])
        {
            QVector<VertexType> shortestPath;
            int startingUniqInt;
            int endingUniqInt;

            startingUniqInt = findVertex(start)->i;
            endingUniqInt = findVertex(end)->i;


            stack<int> path;
            qDebug() << "A path from " << start << " to ";
            qDebug() << findVertex(endingUniqInt)->vertexElem << ": ";

            int i = endingUniqInt;
            path.push(i);
            while(parent[i] != -1)
            {
                path.push(parent[i]);
                i = parent[i];
            }

            while(!path.empty())
            {
                qDebug() << findVertex(path.top())->vertexElem << " ";
                shortestPath.push_back(findVertex(path.top())->vertexElem);
                path.pop();
            }

            qDebug() << "(cost: " << dist[endingUniqInt] << ")" << endl;

            return shortestPath; //nothing for now qDebug() to test
        }

    public:
        void MinimumSpanningTreePrimJarnik()
        {
            int parent[maxSize];
            int key[maxSize];
            bool mstSet[maxSize];

            for(int i = 0; i < maxSize; i++)
            {
                key[i] = INT_MAX;
                mstSet[i] = false;
            }
            key[0] = 0;
            parent[0] = -1;

            for(int count = 0; count < maxSize; count++)
            {
                int u = minKey(key, mstSet);
                mstSet[u] = true;
                for(int v = 0; v < maxSize; v++)
                {
                    if(adjacencyMatrix[u][v].weight
                       && mstSet[v] == false && adjacencyMatrix[u][v].weight < key[v])
                    {
                        parent[v] = u;
                        key[v] = adjacencyMatrix[u][v].weight;
                    }
                }
            }
            printMST(parent);
        }
    protected:

        //METHOD - used to find the minimum distance in dijkstra's algorithm
        int minDistance(double dist[], bool sptSet[])
        {
            int min = INT_MAX;
            int min_index;

            for(int v = 0; v < maxSize; v++)
            {
                if(sptSet[v] == false && dist[v] <= min)
                {
                    min = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        }

        //METHOD - used to find the minimum key for Prim Jarnik's algorithm
        int minKey(int key[], bool mstSet[])
        {
            int min = INT_MAX;
            int min_index;
            for(int v = 0; v < maxSize; v++)
            {
                if(mstSet[v] == false && key[v] < min)
                {
                    min = key[v];
                    min_index = v;
                }
            }
            return min_index;
        }

        //ACCESSOR - prints the solution for dijkstra's algorithm
        void printSolution(int dist[], int parent[], const VertexType& v)
        {
            stack<int> path;
            cout << "All shortest paths from " << v << " are: " << endl;
            for(int uniqInt = 0; uniqInt < maxSize; uniqInt++)
            {
                cout << "A path from " << v << " to ";
                cout << findVertex(uniqInt)->vertexElem << ": ";

                int i = uniqInt;
                path.push(i);
                while(parent[i] != -1)
                {
                    path.push(parent[i]);
                    i = parent[i];
                }

                while(!path.empty())
                {
                    cout << findVertex(path.top())->vertexElem << " ";
                    path.pop();
                }

                cout << "(cost: " << dist[uniqInt] << ")" << endl;
            }

        }

        //ACCESSOR - prints the solution for prim jarnik's algorithm
        void printMST(int parent[])
        {

            for(typename list<Vertex>::iterator it = vertices.begin();
                it != vertices.end(); it++)
            {
                qDebug() << "vertex: " << it->i;
            }
            for(int index = 0; index < maxSize; index++)
            {
                qDebug() << "par: " << parent[index];
            }
            int totalWeight = 0;
            qDebug() << "EDGE" << "WEIGHT" << endl;
            qDebug() << "----" << "------" << endl;
            for(int i = 1; i < maxSize; i++)
            {
                totalWeight = totalWeight + adjacencyMatrix[i][parent[i]].weight;
                qDebug() << findVertex(parent[i])->vertexElem << " - "
                     << findVertex(i)->vertexElem
                     << adjacencyMatrix[i][parent[i]].weight << endl;
            }
            qDebug() << endl << "Total weight is " << totalWeight << endl;
        }

    private:
        void initialize(int id[])
        {
            for(int i = 0; i < maxSize; i++)
            {
                id[i] = i;
            }
        }
        int root(int x, int id[])
        {
            while(id[x] != x)
            {
                id[x] = id[id[x]];
                x = id[x];
            }

            return x;
        }
        void union1(int x, int y, int id[])
        {
            int p = root(x, id);
            int q = root(y, id);
            id[p] = id[q];
        }
    public:
        double Kruskal()
        {
            QFile fin(MSTFILE);
            if(!fin.open(QFile::WriteOnly | QFile::Text))
            {
                qDebug() << "Could not open file";
                return 0;
            }
            QTextStream out(&fin);

            int id[maxSize];
            initialize(id);
            int x, y;
            double cost, minimumCost = 0;
//            sort(edges, edges + edges.size());
            edges.sort();

            out << "MINIMUM SPANNING TREE FOR GRAPH" << endl;
            for(typename list<Edge>::iterator it = edges.begin();
                it != edges.end(); it++)
            {
                x = it->incidentVertices.first->i;
                y = it->incidentVertices.second->i;
                cost = it->weight;

                if(root(x, id) != root(y, id))
                {
                    out << findVertex(x)->vertexElem << " --- " << findVertex(y)->vertexElem;
                    out << endl;
                    minimumCost += cost;
                    union1(x, y, id);
                }
            }
            out << endl;
            out << "COST MST: " << minimumCost << endl;

            fin.flush();
            fin.close();

            return minimumCost;
        }

    private:
        list<Vertex> vertices;  // graph's list of Vertices
        list<Edge> edges;       // graphs's list of edges
        vector< vector<Edge> >adjacencyMatrix;
        int uniqueInt;
        int maxSize;
        double sum;                // sum of the discovery edges
};

#endif // GRAPH_H
