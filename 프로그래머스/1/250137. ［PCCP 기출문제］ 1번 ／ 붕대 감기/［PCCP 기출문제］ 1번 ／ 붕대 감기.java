class Solution {
   
    public int solution(int[] bandage, int health, int[][] attacks) {
        int now = health;
        int cnt = bandage[0]; //추가 체력
        int last_attack = 0; //마지막 공격 시간
        for (int[] attack : attacks) {
            int time = attack[0] - last_attack - 1; //마지막 공격시부터 현재 공격까지의 시간차이
            int heal = (bandage[1] * time) + (bandage[2] * (time / bandage[0]));
            now = Math.min(now + heal, health);
            now -= attack[1];
            last_attack = attack[0];
            if(now <= 0) return -1;
        }

        return now;
    }

}