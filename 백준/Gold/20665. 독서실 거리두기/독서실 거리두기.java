import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int N, T, P;
    static boolean[] chk;
    static int[] seatIdx;
    static List<Reservation> reservations;

    static class Reservation implements Comparable<Reservation> {
        int start;
        int end;

        public static int toSecond(int time) {
            int hour = time / 100;
            int minute = time % 100;
            return (hour * 60 * 60) + (minute * 60);
        }

        public Reservation(int start, int end) {
            this.start = toSecond(start);
            this.end = toSecond(end);
        }

        public int holdSeatTime() {
            return end - start;
        }

        @Override
        public int compareTo(Reservation o) {
            if (this.start == o.start) {
                return holdSeatTime() - o.holdSeatTime(); // 입실 시간이 같으면 짧은 이용시간을 먼저 배정
            }

            return this.start - o.start; // 그외엔 먼저 오는 사람 배정
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        reservations = new ArrayList<>();
        reservations.add(new Reservation(0, 0));
        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            reservations.add(new Reservation(start, end));
        }
        Collections.sort(reservations);
        chk = new boolean[N + 1];
        seatIdx = new int[N + 1];
        int answer = Reservation.toSecond(2100) - Reservation.toSecond(900); // 뺏기는 자리만큼 시간을 뺌
        for (int i = 1; i <= T; i++) {
            deleteSeat(i);
            int seatedNumber = findSeat();
            if (seatedNumber == P) { //앉을 자리가 관리자가 앉을 자리라면
                answer -= reservations.get(i).holdSeatTime();
            }
            chk[seatedNumber] = true;
            seatIdx[seatedNumber] = i;
        }

        System.out.println(answer / 60);
    }

    private static void deleteSeat(int now) {
        for (int i = 1; i <= N; i++) { //현재 앉을 사람의 시간보다 적게 있는 사람 다 내보냄
            if (chk[i] && reservations.get(seatIdx[i]).end <= reservations.get(now).start) {
                chk[i] = false;
                seatIdx[i] = 0;
            }
        }
    }

    private static int findSeat(){
        List<int[]> dist = new ArrayList<>();
        // i번이 비어 있다면 가장 가까운 곳의 idx를 찾는다
        for (int seat = 1; seat <= N; seat++) {
            if (!chk[seat]) { //해당 자리가 비어있다면. ==> 해당 자리에서 가장 가까히 앉아 있는 놈의 자리를 찾음
                int left = seat - 1;
                int right = seat + 1;
                int leftIdx = Integer.MAX_VALUE, rightIdx = Integer.MAX_VALUE;
                for (int i = left; i >= 1; i--) {
                    if(chk[i]) {
                        leftIdx = i;
                        break;
                    }
                }
                for (int i = right; i <= N; i++) {
                    if(chk[i]) {
                        rightIdx = i;
                        break;
                    }

                }

                int leftDist = leftIdx == Integer.MAX_VALUE ? leftIdx : seat - leftIdx;
                int rightDist = rightIdx == Integer.MAX_VALUE ? rightIdx : rightIdx - seat;
                int minDist = Math.min(leftDist, rightDist);
                dist.add(new int[]{seat, minDist});
            }
        }

        dist.sort((a, b) -> {
            if (a[1] == b[1]) { //가장 먼 거리의 좌석이 여러 개면
                //좌석 번호가 가장 작은 순
                return a[0] - b[0];
            }

            return b[1] - a[1];
        });

        return dist.get(0)[0];
    }
}