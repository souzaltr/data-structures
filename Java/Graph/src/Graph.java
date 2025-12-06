import java.util.ArrayList;

public class Graph {
    private final int[][] aMatrix;
    private final ArrayList<Node> nodes;

    Graph(int size){
        aMatrix = new int [size][size];
        nodes = new ArrayList<>();
    }

    public void addNode (Node node){
        nodes.add(node);
    }

    public void addEdge(int src, int destination){
        aMatrix[src][destination] = 1;
    }

    public boolean hasEdge(int src, int destination){
        return (aMatrix[src][destination] == 1);
    }

    public void print (){
        for(Node node : nodes){
            System.out.print("  "+node.getData());
        }

        System.out.println();

        for (int i = 0; i < aMatrix.length; i++){
            System.out.print(nodes.get(i).getData() + " ");
            for (int j = 0; j < aMatrix[i].length; j++){
                System.out.print(aMatrix[i][j] + "  ");
            }
            System.out.println();
        }
    }
}
