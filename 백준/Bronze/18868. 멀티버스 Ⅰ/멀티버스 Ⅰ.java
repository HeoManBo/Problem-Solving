
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        int[][] planet = new int[M][N];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                planet[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = 0;
        for (int i = 0; i < M-1; i++) {
            int[] A = planet[i];
            boolean flag = false;
            for (int j = i+1; j < M; j++) {
                int[] B = planet[j];
                for (int k = 0; k < N-1; k++) {
                    for (int q = k + 1; q < N; q++) {
                        if (A[k] < A[q]) { // Ai < Aj 이면
                            //Bi < Bj 여야 함
                            if (!(B[k] < B[q])) {
                                flag = true;
                            }
                        } else if (A[k] == A[q]) {
                            if (!(B[k] == B[q])) {
                                flag = true;
                            }
                        } else if(A[k] > A[q]){
                            if (!(B[k] > B[q])) {
                                flag = true;
                            }
                        }
                        if(flag) break;
                    }
                }
                if(!flag){
                    ans++;
                }
                flag = false;
            }
        }

        System.out.println(ans);
    }

}
