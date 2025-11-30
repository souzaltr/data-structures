import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Stack <String> processStack = new Stack<>();

        processStack.push("1564645");
        processStack.push("1564646");
        processStack.push("1564647");
        processStack.push("1564648");
        processStack.push("1564649");

        System.out.println(processStack);
        System.out.println(processStack.empty());

        // The pop method returns the removed object so we can use this as below
        String lastRemovedProcess = processStack.pop();
        System.out.println(lastRemovedProcess);
        System.out.println(processStack);

        // But we can also peek at the last object without removing it
        System.out.println(processStack.peek());

        // the search method returns 1-based position from the top of the stack.
        // The topmost element is considered to be at position 1.
        // If the object o is not found in the stack, the method returns -1.
        System.out.println(processStack.search("1564645"));
    }
}