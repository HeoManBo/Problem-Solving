import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int ans = -1;
        for (int i = 0; i < N; i++) {
            List<Integer> remain = new ArrayList<>();

            int except = arr[i];
            for (int j = 0; j < N; j++) {
                if (arr[j] != except) {
                    remain.add(arr[j]);
                }
            }

            for (int j = 0; j < remain.size(); j++) {
                int length = 1;
                int now = remain.get(j);
                for (int k = j + 1; k < remain.size(); k++) {
                    if (now != remain.get(k)) {
                        break;
                    }
                    length++;
                }
                ans = Math.max(ans, length);
            }

        }

        System.out.println(ans);
    }

}
