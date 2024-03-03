import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    private static class Box{
        int size;

        public Box(int height, int width){
            size = height * width;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());
        for(int i=0; i<test; i++){
            int j, N;
            String[] sp = br.readLine().split(" ");
            j = Integer.parseInt(sp[0]);
            N = Integer.parseInt(sp[1]);
            List<Box> boxes = new ArrayList<>();
            for(int k=0; k<N; k++){
                sp = br.readLine().split(" ");
                int height = Integer.parseInt(sp[0]);
                int size = Integer.parseInt(sp[1]);
                boxes.add(new Box(height,size));
                boxes.sort((b1, b2) -> b2.size - b1.size);
            }
            int ans = 0;
            for(int k=0; k< boxes.size(); k++){
                if(j > 0){
                    j -= boxes.get(k).size;
                    ans++;
                }else{
                    break;
                }
            }
            System.out.println(ans);
        }
    }
}