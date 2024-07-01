import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.EnumSet;
import java.util.OptionalInt;
import java.util.StringTokenizer;

public class Main {

    static int N, C;
    static int[] weight;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        weight = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            weight[i] = Integer.parseInt(st. nextToken());
        }
        Arrays.sort(weight);
        OptionalInt checkFirst = Arrays.stream(weight).filter((w) -> w == C).findFirst();
        //하나의 값만으로 C를 만족하는 경우
        if (checkFirst.isPresent()) {
            System.out.println(1);
            return;
        }

        int l = 0, r = N-1;
        while (l < r) {
            int sum = weight[l] + weight[r];
            if (sum == C) {
                System.out.println(1);
                return;
            }else if(sum > C) {
                r--;
            }else{
                //세개 확인
                for (int i = l + 1; i < r; i++) {
                    int three = sum + weight[i];
                    if(three > C) break;
                    if (three == C) {
                        System.out.println(1);
                        return;
                    }
                }
                l++;
            }
        }

        //두개 확인
//        boolean flag = false;
//        for (int i = 0; i < N; i++) {
//            for (int j = i + 1; j < N; j++) {
//                if (C - weight[i] > 0) {
//                    boolean b = find(i, j, C - weight[i]);
//                    if(b){
//                        flag = true;
//                        break;
//                    }
//                }
//            }
//            if(flag){
//                break;
//            }
//        }
//
//        //두개도 실패했으면 세 개 확인
//        if(!flag){
//            for (int i = 0; i < N; i++) {
//                for (int j = i + 2; j < N; j++) {
//                    int first = weight[i];
//                    int second = weight[j];
//                    if(first + second < C){
//                        boolean isIn = find(i, j, C - first - second);
//                        if (isIn) {
//                            flag  = true;
//                            break;
//                        }
//                    }
//                }
//                if(flag)break;
//            }
//        }


//        System.out.println((flag ? 1 : 0));
        System.out.println(0);
        br.close();
    }

    // [l,r]구간에 value 가 있는지 확인한다.
    private static boolean find(int l, int r, int value) {
        while (l <= r) {
            int mid = (l + r) / 2;
            int v = weight[mid];
            if (v == value) {
                return true;
            } else if (v > value) {
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }

        return false;
    }

}
