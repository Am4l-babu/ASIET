import java.util.Scanner;

class SecondSmallestElement {

    int findSecondSmallest(int[] arr,int n) {
        int smallest = arr[0];
        int secondSmallest = arr[0];

        for (int i=0;i<n;i++) {
          int num=arr[i];
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else if (num > smallest && num < secondSmallest) {
                secondSmallest = num;
            }
        }

        return secondSmallest;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = s.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }

        int secondSmallest = findSecondSmallest(arr);
        System.out.println("The second smallest element is: " + secondSmallest);

        s.close();
    }
}
