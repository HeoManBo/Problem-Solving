import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] people;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        people = new int[N];
        for (int i = 0; i < N; i++) {
            people[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(people);
        int wait = 0;
        int ans = 0;
        for(int i=0; i<N; i++){
            ans += people[i] + wait;
            wait += people[i];
        }
        System.out.println(ans);
        
    }




}
