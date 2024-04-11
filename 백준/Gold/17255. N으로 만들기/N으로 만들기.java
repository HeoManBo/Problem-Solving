import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String target = br.readLine();
        Set<List<String>> set = new HashSet<>();

        AtomicInteger a = new AtomicInteger(0);
        for (int i = 0; i <= 9; i++) {
            List<String> order = new ArrayList<>();
            StringBuilder sb = new StringBuilder();
            sb.append(i);
            order.add(sb.toString());
            go(sb, target, set, order, a);
        }

        System.out.println(a.get());
    }

    private static void go(StringBuilder sb, String target, Set<List<String>> set, List<String> order, AtomicInteger a) {
        if(sb.length() == target.length()){
            if(sb.toString().equals(target)){
                if(!set.contains(order)){
                    set.add(List.copyOf(order));
                    a.incrementAndGet();
                }
            }

            return;
        }

        // backtracking
        if (!target.contains(sb.toString())) {
            return;
        }

        for(int i=0; i<=9; i++){
            //좌로 하나씩 붙임
            StringBuilder next = new StringBuilder();
            next.append(i);
            next.append(sb);
            order.add(next.toString());
            go(next, target, set, order, a);
            order.remove(order.size() - 1);
        }

        for(int i=0; i<=9; i++){
            //우로 하나씩 붙임
            StringBuilder next = new StringBuilder(sb);
            next.append(i);
            order.add(next.toString());
            go(next, target, set, order, a);
            order.remove(order.size() - 1);
        }

    }

}
