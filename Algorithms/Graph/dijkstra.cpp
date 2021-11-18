
#define Edge pair<int, int>
#define Graph vector<vector<Edge>>
#define weight first
#define dst second
inline Edge make_edge(int a, int b) { return Edge(b, a); }

Graph adjs;
vi marc;

void dijikstra(int vertex){
    set<Edge> fila;
    fila.insert(make_edge(vertex, 0));
    marc[vertex] = 0;

    int current, w;
    while (fila.size()){
        tie(w, current) = *fila.begin();
        fila.erase(fila.begin());

        for (Edge adj : adjs[current]){
            if (marc[adj.dst] > w + adj.weight)
            {
                marc[adj.dst] = w + adj.weight;
                fila.insert(make_edge(adj.dst, marc[adj.dst]));
            }
        }
    }
}
