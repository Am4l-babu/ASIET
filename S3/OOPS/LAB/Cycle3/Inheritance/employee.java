import java.util.*;

class employee{
	String employeename;
	int age;
	long phonenumber;
	String address;
	double salary;

	void printsal(){
		System.out.println("Salary:\t" +salary);
	}
}

class officer extends employee{
	String spec;
}

class manager extends employee{
	String dep;
}

class employeeprinting{
	public static void main(String args[])
	{
		Scanner S1 = new Scanner(System.in);
		
		officer o = new officer();
		manager m = new manager();
		
		System.out.println("Enter Officer Details");
		System.out.println("Enter Name:");
		o.employeename = S1.nextLine();
		System.out.println("Enter Age:");
		o.age = S1.nextInt();
		System.out.println("Enter Phonenumber:");
		o.phonenumber = S1.nextLong();
		System.out.println("Enter Address:");
		S1.nextLine();
		o.address = S1.nextLine();
		System.out.println("Enter Salary:");
		o.salary = S1.nextDouble();
		System.out.println("Enter Specialization:");
		S1.nextLine();
		o.spec = S1.nextLine();

		System.out.println("Enter Manager Details");
		System.out.println("Enter Name:");
		m.employeename = S1.nextLine();
		System.out.println("Enter Age:");
		m.age = S1.nextInt();
		System.out.println("Enter Phonenumber:");
		m.phonenumber = S1.nextLong();
		System.out.println("Enter Address:");
		S1.nextLine();
		m.address = S1.nextLine();
		System.out.println("Enter Salary:");
		m.salary = S1.nextDouble();
		System.out.println("Enter Department:");
		S1.nextLine();
		m.dep = S1.nextLine();
		
		System.out.println("The details of the Officer are:");
		System.out.println("Name:\t" + o.employeename);
		System.out.println("Age:\t" + o.age);
		System.out.println("Address:\t" + o.address);
		System.out.println("Phone number:\t" + o.phonenumber);
		o.printsal();
		System.out.println("Specialization:\t" + o.spec);

		System.out.println("The details of the Manager are:");
		System.out.println("Name:\t" + m.employeename);
		System.out.println("Age:\t" + m.age);
		System.out.println("Address:\t" + m.address);
		System.out.println("Phone number:\t" + m.phonenumber);
		m.printsal();
		System.out.println("Department:\t" + m.dep);
		S1.close();
   
		}
}
