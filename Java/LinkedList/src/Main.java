import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();
        list.offer("A");
        list.push("B");
        list.offer("C");
        list.push("D");
        list.add(2,"E");

        System.out.println(list);

        list.pop();
        list.remove("E");
        System.out.println(list);

    }
}