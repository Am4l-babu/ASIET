import java.util.*;

abstract class Shape {
    void numberOfSides() {
    }
    
    void calculateArea(int length, int width) {
        System.out.println("Area of Rectangle: " + (length * width));
    }
    
    void calculateArea(float base, float height) {
        System.out.println("Area of Triangle: " + (0.5 * base * height));
    }
    
    void calculateArea(int sideLength) {
        System.out.println("Area of Hexagon: " + ((3 * Math.sqrt(3) / 2) * Math.pow(sideLength, 2)));
    }
}

class Rectangle extends Shape {
    void numberOfSides() {
        System.out.println("The number of sides of a Rectangle is 4");
    }
}

class Triangle extends Shape {
    void numberOfSides() {
        System.out.println("The number of sides of a Triangle is 3");
    }
}

class Hexagon extends Shape {
    void numberOfSides() {
        System.out.println("The number of sides of a Hexagon is 6");
    }
}

class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        Rectangle R = new Rectangle();
        Triangle T = new Triangle();
        Hexagon H = new Hexagon();
        
        R.numberOfSides();
        T.numberOfSides();
        H.numberOfSides();
        
        System.out.print("Enter length and width for Rectangle: ");
        int length = s.nextInt();
        int width = s.nextInt();
        R.calculateArea(length, width);
        
        System.out.print("Enter base and height for Triangle: ");
        float base = s.nextFloat();
        float height = s.nextFloat();
        T.calculateArea(base, height);
        
        System.out.print("Enter side length for Hexagon: ");
        int sideLength = s.nextInt();
        H.calculateArea(sideLength);
        
        s.close();
    }
}
