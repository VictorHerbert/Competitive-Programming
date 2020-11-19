#define INF INT_MAX

struct Vertex{
    int src,
        dst,
        weight;

    Vertex(int _src, int _dst, int _weight):
        src(_src),
        dst(_dst),
        weight(_weight){};
};

struct Connection{
    int node,
        weight;

    Connection(int _node, int _weight):
        node(_node),
        weight(_weight){};
};

struct _priorityqueue_inverted_operators_connection : Connection {
    _priorityqueue_inverted_operators_connection(int _node, int _weight):
        Connection(_node,_weight){};

    static _priorityqueue_inverted_operators_connection toPqConn(Connection& c){
        return _priorityqueue_inverted_operators_connection(c.node,c.weight);
    }

    bool operator >  (const Connection& c) const { return weight < c.weight;} //Para Priority Queue
    bool operator <  (const Connection& c) const { return weight > c.weight;}
    bool operator == (const Connection& c) const { return weight == c.weight;}
};

typedef Connection Conn;
typedef _priorityqueue_inverted_operators_connection pqConn;

struct BaseGraph{

};

template <typename T>
struct ImpGraph {
    vector<T> (*getAdj)(T);
    //vector<T> getAdj(T t);

    ImpGraph(vector<T> (*_getAdj)(T)):
        getAdj(_getAdj){};

    void bfs(T src, T dst){
        map<T,bool> marc;
        queue<T> q;

        q.push(src);

        while(!q.empty()){
            T cur = q.front();
            q.pop();

            cout << cur << " ";

            if(cur == dst)
                return;

            for(auto t : getAdj(cur)){
                if(!marc[t]){
                    q.push(t);
                }
            }
        }

    }

};


struct Graph{

    int size(){
        return adjList.size();
    }

    vector < vector < Connection > > adjList;

    Graph(int edgeCount){
        vector < Connection > aux;
        aux.reserve(edgeCount);
        adjList = vector < vector < Connection > > (edgeCount,aux);
    };

    void reserve(int _size){adjList.reserve(_size);}

    void addVertex(int src, int dst, int weight = 1){
        adjList[src].push_back(Conn(dst,weight));
        //vertexList.push_back(Vertex(src,dst,weight));
    }

    int bfs(int src, int dst){
        vector < int > stepdist (this->size(), INF);
        bfs(src, stepdist);
        return stepdist[dst];
    }

    void bfs(int src, vector < int >& stepdist ){
        int current;
        queue<int> q;

        q.push(src);
        stepdist[src] = 0;

        while(!q.empty()){
            current = q.front();
            q.pop();

            cout << current << "|";

            for(auto c : adjList[current]){
                if(stepdist[c.node] == INF){
                    q.push(c.node);
                    stepdist[c.node] = stepdist[current]+1;
                }
            }
        }
    }

    void dfs(int src = 0){
        int current;
        vector < bool > visited (this->size(), false);
        stack<int> s;

        s.push(src);
        visited[src] = true;

        while(!s.empty()){
            current = s.top();
            s.pop();

            cout << current << "|";

            for(auto c : adjList[current]){
                if(!visited[c.node]){
                    s.push(c.node);
                    visited[c.node] = true;
                }
            }
        }
    }

    int dijkstra(int src, int dst){
        vector < int > distances = vector < int > (this->size(), INF);
        vector < int > path = vector < int > (this->size(), -1);

        return dijkstra(src,dst,distances,path);
    }

    int dijkstra(int src, int dst, vector < int >& distances, vector < int >& path){
        priority_queue<pqConn> pq;
        int current;

        pq.push(pqConn(src,0));
        distances[src] = 0;

        while(!pq.empty()){
            current = pq.top().node;
            pq.pop();

            for(auto c : adjList[current]){

                if(distances[c.node] > distances[current] + c.weight){
                    distances[c.node] = distances[current] + c.weight;
                    pq.push(pqConn::toPqConn(c));
                    path[c.node] = current;

                    if(c.node == dst){
                        return distances[dst];
                    }
                }
            }
        }

        return distances[dst];
    }


    int bellman_ford(int src, int dst){
        vector<int> distances, path;
        bellman_ford(src, distances, path);
        return distances[dst];
    }

    void bellman_ford(int src, vector<int>& dist, vector<int>& path){

        dist = vector < int > (this->size(), INF);
        path = vector < int > (this->size(), -1);

        dist[src] = 0;

        int vertexCount = this->size();
        vertexCount--;
        while(vertexCount--){
            for(int i = 0; i < adjList.size(); i++){
                for(auto c : adjList[i]){
                    if(dist[i] != INF)
                        if(dist[c.node] > dist[i] + c.weight){
                            dist[c.node] = dist[i] + c.weight;
                            path[c.node] = i;
                        }
                }
            }
        }
    }

    bool hasNegativeCicles(vector<int>& dist){
        int vertexCount = this->size();
        vertexCount--;
        while(vertexCount--){
            for(int i = 0; i < adjList.size(); i++){
                for(auto c : adjList[i]){
                    if(dist[c.node] > dist[i] + c.weight){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    int kosaraju(){
        vector<int> strongly_connected_components;
        kosaraju(strongly_connected_components);
        return strongly_connected_components.size();
    }


    void kosaraju(vector<int>& scc){

    }
};

struct BDGraph : Graph{
    void addVertex(int src, int dst, int weight = 1){
        adjList[src].push_back(Conn(dst,weight));
        adjList[dst].push_back(Conn(src,weight));
    }

    BDGraph (int n):
        Graph(n){};

    /*void kosaraju(vector<int>& scc){
        scc.reserve(this->size());

        for(int i = 0; i < this->size() ;i++){
            //bfs(i)
        }
    }*/
};
