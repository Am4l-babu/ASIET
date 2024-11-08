import java.util.*;

class IntegerSum {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter a line of integers separated by spaces:");

        String inputLine = s.nextLine();
        String[] numbers = inputLine.split(" ");

        int sum = 0;

        System.out.println("The integers are:");
        for (String numStr : numbers) {
            int num = Integer.parseInt(numStr);
            System.out.println(num);
            sum += num;
        }

        System.out.println("The sum of all integers is: " + sum);
    }
}
