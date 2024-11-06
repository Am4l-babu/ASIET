import java.util.*;

class PrimeNumbers {

    boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    void printPrimesUpTo(int n) {
        System.out.println("Prime numbers up to " + n + ":");
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    public static void main(String args[]) 
    {
        if(args.length<1)
	{
		System.out.println("Enter an integer as an argument");
		System.exit(0);
	}
	PrimeNumbers primeNumbers = new PrimeNumbers();
	int n=(Integer.parseInt(args[0]));
        primeNumbers.printPrimesUpTo(n);
    }
}
