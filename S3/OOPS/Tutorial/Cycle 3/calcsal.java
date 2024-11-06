import java.util.*;

class Employee {
  	int salry;
  	void display() {
        System.out.println("Name of the class is Employee");
    }
    void calcSalary() {
        System.out.println("Salary of employee is " + salry);
    }
}
class Engineer extends Employee { 
}
class main {
    public static void main(String[] args) {
    	Scanner s=new Scanner(System.in);
        Employee a = new Employee();
        Engineer b = new Engineer();
        System.out.println("Enter the salary of the employee");
        a.salry=s.nextInt();
        a.display();
        a.calcSalary();
        System.out.println("Enter the salary of the Engineer");
       	b.salry=s.nextInt();
        b.display();
        b.calcSalary();     
    }
}
