#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define INF INT_MAX
#define MAX 2001

#define MAX_ID 30005

using namespace std;

int n, m;
int start;

int graph[MAX][MAX];
int Dist[MAX];
bool isMade[MAX_ID] = { false };
bool isCancel[MAX_ID] = { false };

struct Package {
    int id;
    int revenue;
    int dest;
    int profit;

    struct Comparator {
        bool operator()(const Package& a, const Package& b) const {
            if(a.profit == b.profit) { return a.id > b.id; } // profit이 같으면 id가 작은 순으로 ..
        
            return a.profit < b.profit; // profit이 가장 큰 순으로 나열
        }
    };
};

priority_queue<Package, vector<Package>, Package::Comparator> pq;

void Dijkstra();

int main(void) {
    int Q;
    cin >> Q;

    for(int t = 0; t < Q; t++) {
        int request;
        cin >> request;

        if(request == 100) {
            cin >> n >> m;
            start = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    graph[i][j] = INF;


            for(int i = 0; i < m; i++) {
                int v, u, w;
                cin >> v >> u >> w;
                graph[v][u] = min(w, graph[v][u]);
                graph[u][v] = min(w, graph[u][v]);
            }
            
            Dijkstra();
        }
        else if(request == 200) {
            int id, revenue, dest;
            cin >> id >> revenue >> dest;
            
            Package p;
            p.id = id;
            p.revenue = revenue;
            p.dest = dest;
            p.profit = revenue - Dist[dest];
            isMade[id] = true;

            pq.push(p);
        }
        else if(request == 300) {
            int id;
            cin >> id;
            if(isMade[id]) isCancel[id] = true;
        }
        else if(request == 400) {
            while(!pq.empty()) {
                Package p = pq.top();

                if(p.profit < 0) {
                    cout << -1 << endl;
                    break;
                }

                pq.pop();
                if(!isCancel[p.id]) {
                    cout << p.id << endl;
                    break;
                }
            }
        }
        else if(request == 500) {
            cin >> start;
            Dijkstra();
            vector<Package> temp;
            while(!pq.empty()) {
                temp.push_back(pq.top());
                pq.pop();
            }

            for(Package p : temp) {
                Package new_p;
                isMade[p.id] = true;
                new_p.id = p.id;
                new_p.revenue = p.revenue;
                new_p.dest = p.dest;
                new_p.profit = new_p.revenue - Dist[new_p.dest];
                pq.push(new_p);
            }
        }

    }
    return 0;
}

void Dijkstra() {
    bool visited[MAX];
    // init
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        Dist[i] = INF;
    }

    Dist[start] = 0;

    for(int i = 0; i < n - 1; i++) { // 시작점 제외 탐험 시작
        int v = 0, minDist = INF;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && minDist > Dist[j]) {
                v = j;
                minDist = Dist[j];
            }
        }
        visited[v] = true; // v번째 정점에 대한 방문 완료

        for(int j = 0; j < n; j++) {
            if(!visited[j] && Dist[v] != INF && graph[v][j] != INF && Dist[j] > Dist[v] + graph[v][j]) {
                // j번째 정점은 방문한 적이 없으나 v번째 정점은 방문한 적이 있으면서 v->j의 경로가 있으며 j까지의 최단경로가 ...->v->j로 가는 경로보다 길 때
                Dist[j] = Dist[v] + graph[v][j];
                // j번째 정점까지의 최단거리 갱신
            }
        }
    }
}