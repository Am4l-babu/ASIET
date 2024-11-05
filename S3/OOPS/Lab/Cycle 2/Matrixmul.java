import java.util.Scanner;

class matrixmul {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        System.out.println("Enter the number of Rows of the First matrix");
        int r1 = s.nextInt();
        System.out.println("Enter the number of Columns of the First matrix");
        int c1 = s.nextInt();
        
        System.out.println("Enter the number of Rows of the Second matrix");
        int r2 = s.nextInt();
        System.out.println("Enter the number of Columns of the Second matrix");
        int c2 = s.nextInt();
        
        if (c1 != r2) {
            System.out.println("The Matrices can't be Multiplied");
            System.exit(0);
        }
        
        int[][] a = new int[r1][c1];
        int[][] b = new int[r2][c2];
        int[][] product = new int[r1][c2];
        
        System.out.println("Enter the First matrix:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                a[i][j] = s.nextInt();
            }
        }
        
        System.out.println("Enter the Second matrix:");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                b[i][j] = s.nextInt();
            }
        }
        
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                product[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    product[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        
        System.out.println("The product is:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                System.out.print(product[i][j] + "\t");
            }
            System.out.println();
        }
        
        s.close();
    }
}
