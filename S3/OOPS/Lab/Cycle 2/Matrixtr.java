import java.util.Scanner;

class matrixtr {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        System.out.println("Enter the number of Rows of the  matrix");
        int r1 = s.nextInt();
        System.out.println("Enter the number of Columns of the  matrix");
        int c1 = s.nextInt();
        
        
        int[][] a = new int[r1][c1];
        
        System.out.println("Enter the  matrix:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                a[i][j] = s.nextInt();
            }
        }
        

        System.out.println("The Transpose is:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                System.out.print(a[j][i] + "\t");
            }
            System.out.println();
        }
        
        s.close();
    }
}
