import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        // Queue is a FIFO (first-in first-out) data structure.
        Queue<String> clientQueue = new LinkedList<>();

        /* The queue interface basically provides three methods
           to add, remove and get to the head of the queue. But the difference between
           they are the add, remove and element methods can throw an exception in some cases,
           offer, poll and peek return a special value (false or null) instead.
        */

        clientQueue.offer("Laura");
        clientQueue.offer("João");
        clientQueue.offer("Silvio");
        clientQueue.offer("Bruno");
        clientQueue.offer("Amanda");
        clientQueue.offer("Júlia");

        System.out.println(clientQueue);

        clientQueue.poll();
        System.out.println(clientQueue);

        System.out.println("The head of this queue is " + clientQueue.peek());
    }
}