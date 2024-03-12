import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    List<List<Integer>> graph = new ArrayList<>();
    private static final int STICK = 2; // 막대 모양
    private static final int DONUT = 1; // 도넛 모양
    private static final int LOOP = 3; //8자 모양

    public int[] solution(int[][] edges) {
        int[] answer = new int[4];
        init();
        int maxNode = -1;
        int[] in = new int[1000001];
        for(int[] edge : edges){
            graph.get(edge[0]).add(edge[1]);
            maxNode = Math.max(maxNode, Math.max(edge[0],edge[1]));
            in[edge[1]]++;
        }
        int[] chk = new int[maxNode+1];
        //시작점은 나가는 간선이 여러 개인 그래프
        for(int i=1; i<=maxNode; i++){
            if(graph.get(i).size() >= 2 && in[i] == 0){
                answer[0] = i;
                findGraph(i, answer, chk) ;
                break;
            }
        }
        return answer;
    }

    //시작점이 root인 경우
    private void findGraph(int root, int[] answer, int[] chk) {
        for(int next : graph.get(root)){
            dfs(next, next, chk, answer);
        }
    }

    private boolean dfs(int now, int first, int[] chk, int[] answer){
        chk[now] += 1;

        if(graph.get(now).size() == 0){ //더 이상 진행 방향이 없는 경우 막대모양
            answer[STICK] += 1;
            return true;
        }

        for(int next : graph.get(now)){
            if(graph.get(next).size() == 2){ //진출 차수가 2개인 경우 LOOP
                answer[LOOP]++;
                return true;
            }
            else if(chk[next] == 1 && next == first){ //제자리로 돌아오는 경우 DONUT
                answer[DONUT]++;
                return true;
            }
            if(dfs(next, first, chk, answer)) return true;
        }


        return false;
    }

    private void init() {
        for(int i=0; i<1_000_001; i++){
            graph.add(new ArrayList<>());
        }
    }
}