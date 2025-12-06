public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph(4);

        graph.addNode(new Node('A'));
        graph.addNode(new Node('B'));
        graph.addNode(new Node('C'));
        graph.addNode(new Node('D'));

        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 0);
        graph.addEdge(2, 1);
        graph.addEdge(2, 3);

        graph.print();

        System.out.println(graph.hasEdge(0, 1));
        System.out.println(graph.hasEdge(0, 3));
        System.out.println(graph.hasEdge(3, 1));
    }
}