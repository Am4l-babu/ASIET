class Fibonacci {

  int fibonacciRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

   int fibonacciNonRecursive(int n) {
        if (n <= 1) {
            return n;
        }

        int prev2 = 0;
        int prev1 = 1;
        int current = 0;

        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }

    public static void main(String[] args) {
      Scanner s=new Scanner(System.in);
      int n = s.nextInt;

        System.out.println("Fibonacci series using recursive method:");
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacciRecursive(i) + " ");
        }

        System.out.println("Fibonacci series using non-recursive method:");
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacciNonRecursive(i) + " ");
        }
      s.close();
    }
}
