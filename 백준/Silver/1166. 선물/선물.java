import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long N = Long.parseLong(st.nextToken());
        long L = Long.parseLong(st.nextToken());
        long W = Long.parseLong(st.nextToken());
        long H = Long.parseLong(st.nextToken());


        double l = 0.0, r = 1_000_000_000;

        for(int i=1; i<=10_000; i++){
            double mid = (l + r) / 2;
            long count = (long) (L / mid) * (long) (W / mid) * (long) (H / mid); //하나의 상자 크기가 mid * mid * mid 일 때 몇 개 들어갈 수 있는지
            if(count >= N){
                l = mid;
            }else{
                r = mid;
            }
        }

        System.out.printf("%.10f\n", l);
    }

}
