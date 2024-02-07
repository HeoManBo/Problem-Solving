#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[11][11];
int num_arr[11][11]; //대륙에 번호를 표시함.
bool check[11][11]; //방문 표시 
int num = 1;
//동서남북
int dy[] = { 0,0,1,-1 };
int dx[] = { -1,1,0,0 };
//{dist, start, end} 
vector<pair<int, pair<int, int>>> edge;
int parent[11];
vector<int> graph[11];
int ans = 0;

//크루스칼 알고리즘을 위함. 
int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    parent[v] = u;
}

bool isin(int y, int x) {
    return (y >= 0 && y < N) && (x >= 0 && x < M);
}

//섬마다 번호를 매긴다.
void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y,x });
    check[y][x] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        num_arr[y][x] = num;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (isin(ny, nx)) {
                if (!check[ny][nx] && arr[ny][nx]) {
                    q.push({ ny,nx });
                    check[ny][nx] = true;
                }
            }
        }
    }
}

//해당 위치에서 동서남북으로 일직선으로 쭉 이동했을때
//다른 섬을 만난다면 해당 길이와 시작 섬, 도착 섬번호를 기록한다.
//동일한 섬이라면 중단한다.
void distance(int y, int x, int now_num) {
    for (int i = 0; i < 4; i++) {
        int dist = 0, ny = y, nx = x;
        //동,서,남,북으로 계속 쭈욱 이동해본다.
        while (true) {
            ny += dy[i];
            nx += dx[i];
            //범위를 벗어난다면 break;
            if (!isin(ny, nx)) {
                break;
            }
            //이동했는데 동일한 섬번호면 break;
            else if (num_arr[ny][nx] == now_num) {
                break;
            }
            //범위안에있다면 다음 점이 바다라면 계속 이동해보고, 
            //다른 섬에도착한다면 해당 정보를 저장한다.
            else {
                //바다라면 거리 1 증가
                if (num_arr[ny][nx] == 0) {
                    dist++;
                    continue;
                }
                else if (num_arr[ny][nx] != now_num) {
                    //거리가 2이상일 때만 기록한다.
                    if (dist > 1) {
                        edge.push_back({ dist,{num_arr[y][x],num_arr[ny][nx]} });
                    }
                    break;
                }
            }
        }
    }
}



int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!check[i][j] && arr[i][j]) {
                bfs(i, j);
                num++;
            }
        }
    }
    //각 섬에서 다른 섬까지의 거리를 구한다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (num_arr[i][j]) {
                distance(i, j, num_arr[i][j]);
            }
        }
    }
    //크루스칼 알고리즘을 사용하여 섬끼리 최소 비용으로 잇는 스패닝 트리를 만든다.
    sort(edge.begin(), edge.end());
    for (int i = 1; i < num; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < edge.size(); i++) {
        auto x = edge[i];
        int u = x.second.first;
        int v = x.second.second;
        int d = x.first;
        //아직 두 섬이 연결되어있지 않다면 연결한다.
        if (find(u) != find(v)) {
            merge(u, v);
            ans += d;
            //두 섬을 정점으로 그래프를 만든다. 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    //모든 섬들이 연결되었는지 확인한다.
    queue<int> q;
    q.push(1);
    vector<bool> chk(num + 1, false);
    int cnt = 1;
    chk[1] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (!chk[next]) {
                q.push(next);
                chk[next] = true;
                cnt++;
            }
        }
    }
    //모든 섬이 연결돼있지 않다면 -1 출력
    if (cnt != num - 1) cout << "-1\n";
    //연결돼있으면 mst로 연결한 값 출력 
    else {
        cout << ans << "\n";
    }
    return 0;
}