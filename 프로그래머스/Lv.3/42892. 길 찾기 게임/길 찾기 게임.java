import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Solution {
    static class Node{
        int y;
        int x;
        int num; //노드 번호
        Node left;
        Node right;
        Node parent;

        public Node(int y, int x, int num) {
            this.y = y;
            this.x = x;
            this.num = num;
        }

        public void addLeft(Node node){
            this.left = node;
            node.parent = this;
        }

        public void addRight(Node node){
            this.right = node;
            node.parent = this;
        }

        public static boolean emptyNode(Node node){
            if(node.y == -1 && node.x == -1 && node.num == -1) return true;
            return false;
        }
        
        public static Node MakeEmptyNode(){
            return new Node(-1,-1,-1);
        }
    }

    public int[][] solution(int[][] nodeinfo) {
        List<Node> nodes = new ArrayList<>();
        for(int i=0; i<nodeinfo.length; i++){
            nodes.add(new Node(nodeinfo[i][1], nodeinfo[i][0], i+1));
        }
        Node root = makeTree(nodes);
        List<Integer> inOrder = new ArrayList<>();
        inOrder(root, inOrder);
        List<Integer> postOrder = new ArrayList<>();
        postOrder(root, postOrder);
        int[][] result = new int[2][];
        result[0] = inOrder.stream().mapToInt(i -> i).toArray();
        result[1] = postOrder.stream().mapToInt(i -> i).toArray();
        return result;
    }

    private void postOrder(Node root, List<Integer> process) {
        if(!Node.emptyNode(root.left)){
            postOrder(root.left, process);
        }
        if(!Node.emptyNode(root.right)){
            postOrder(root.right, process);
        }
        process.add(root.num);
    }

    private void inOrder(Node root, List<Integer> process) {
        process.add(root.num);
        if(!Node.emptyNode(root.left)){
            inOrder(root.left, process);
        }
        if(!Node.emptyNode(root.right)){
            inOrder(root.right, process);
        }
    }

    private Node makeTree(List<Node> nodes) {
        if(nodes.isEmpty()) return new Node(-1,-1,-1);//빈 깡통
        if(nodes.size() == 1) {
            Node n = nodes.get(0);
            n.left = Node.MakeEmptyNode();
            n.right = Node.MakeEmptyNode();
            return n;
        }
        Collections.sort(nodes, (n1, n2) -> n2.y - n1.y); //y값이 가장 큰 놈이 해당 서브트리의 루트
        Node node = nodes.get(0); //가장 Y가 큰 값의 서브트리
        int x = node.x; //루트의 x 값을 가지고 왼쪽 서브트리 후보와 오른쪽 서브 트리 후보를 나누어 재귀를 돌린다.
        List<Node> left = new ArrayList<>();
        List<Node> right = new ArrayList<>();
        for(Node n : nodes){
            if(n.x > x) right.add(n);
            if(n.x < x) left.add(n);
        }

        node.addLeft(makeTree(left));
        node.addRight(makeTree(right));

        return node;
    }
}