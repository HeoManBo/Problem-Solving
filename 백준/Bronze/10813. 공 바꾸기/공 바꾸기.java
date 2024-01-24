import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, M;
        String[] split = br.readLine().split(" ");
        N = Integer.parseInt(split[0]);
        M = Integer.parseInt(split[1]);
        int[] arr = new int[N+1];
        for(int i=1; i<=N; i++){
            arr[i] = i;
        }
        for(int i=0; i<M; i++){
            int f,s;
            split = br.readLine().split(" ");
            f = Integer.parseInt(split[0]);
            s = Integer.parseInt(split[1]);
            swap(f,s, arr);
        }

        for(int i=1; i<=N; i++){
            System.out.print(arr[i] + " ");
        }

    }

    private static void swap(int f, int s, int[] arr) {
        int tmp = arr[f];
        arr[f] = arr[s];
        arr[s] = tmp;
    }
}