import java.util.*;

class largest{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of values");
        int n = s.nextInt();
        int largest =0;
	      for (int i = 0; i < n; i++) 
	          {
              System.out.print("Enter number " + (i + 1) + ": ");
              int num = s.nextInt();
              if (num > largest) 
                largest = num;
            }
        System.out.println("The largest number is: " + largest);
        s.close();
    }
}
