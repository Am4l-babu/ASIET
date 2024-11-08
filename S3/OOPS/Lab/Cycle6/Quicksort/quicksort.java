import java.util.*;

class Sort {
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    void quicksort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Sort obj = new Sort();
        
     	int arr[] = new int[100];
        System.out.println("Enter the length of the array:");
        int len = s.nextInt();
        System.out.println("Enter an array:");
        for (int i = 0; i < len; i++) {
            arr[i] = s.nextInt();
        }
        obj.quicksort(arr, 0, len - 1);
        System.out.println("The sorted array is:");
        for (int i = 0; i < len; i++) {
            System.out.print(arr[i] + " ");
       }
        System.out.println();
        s.close();
    }
}
