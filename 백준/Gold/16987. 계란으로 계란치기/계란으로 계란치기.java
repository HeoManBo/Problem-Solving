import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static List<Egg> eggs = new ArrayList<>();

    static class Egg{
        //무게만큼 내구도 감소
        int armor;
        int weight;

        public Egg(int armor, int weight) {
            this.armor = armor;
            this.weight = weight;
        }

        //서로 계란을 때림
        public void hit(Egg egg){
            this.armor -= egg.weight;
            egg.armor -= this.weight;
        }

        //원상 복구
        public void back(Egg egg){
            this.armor += egg.weight;
            egg.armor += this.weight;
        }

    }

    static int ans = Integer.MIN_VALUE;
    static boolean[] broken;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        broken = new boolean[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int armor = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            eggs.add(new Egg(armor, weight));
        }
        go(0, 0);

        System.out.println(ans);
    }

    private static void go(int now, int count) {
        if(now == N){ //가장 최근의 든 계란이 가장 오른쪽에 든 경우
            ans = Math.max(ans, count);
            return;
        }

        if(!canHit(now)) {
            go(now + 1, count);
            return;
        }

        Egg nowEgg = eggs.get(now);
        for(int i=0; i<N; i++){
            // 계란 치기
            if(i == now || broken[i]) continue;
            Egg candidate = eggs.get(i);
            nowEgg.hit(candidate);
            int num = 0;
            if(nowEgg.armor <= 0){
                broken[now] = true;
                num++;
            }
            if(candidate.armor <= 0){
                broken[i] = true;
                num++;
            }
            go(now+1, count + num); //오른쪽 계란으로 이동
            //원복
            nowEgg.back(candidate);
            if(nowEgg.armor > 0){
                broken[now] = false;
            }
            if(candidate.armor > 0){
                broken[i] = false;
            }
        }
    }

    // 손에 든 계란이 깨졌거나, 깨지지 않은 다른 계란이 없는 경우
    private static boolean canHit(int now) {
        if(broken[now]) return false; // 손에 쥔 계란이 깨진 경우 

        for(int i=0; i<N; i++){
            if(i != now && !broken[i]) return true; //손에 쥔 계란이 아니고, 하나라도 깨지지 않은 계란이 있으면
        }

        return false;
    }

}
