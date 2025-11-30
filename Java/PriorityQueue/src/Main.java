import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {

        /* Priority queue is a FIFO data structure that serves elements
           with the highest priorities first before elements with lower priority.*/

        Queue<String> priorityClientQueue = new PriorityQueue<>();
        priorityClientQueue.offer("Ana");
        priorityClientQueue.offer("Bob");
        priorityClientQueue.offer("Alice");
        priorityClientQueue.offer("John");

        while(!priorityClientQueue.isEmpty()) System.out.println(priorityClientQueue.poll());

    }
}