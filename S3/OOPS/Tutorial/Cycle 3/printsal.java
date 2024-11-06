import java.util.*;

class employee {
    int age;
    long phone;
    String name, address;
    double salary;
    int workExperience;

    void printSal() {
        System.out.println("Salary: " + salary);
    }
}

class officer extends employee {
    String special;

    void calculateSal() {
        double baseSalary = 30000;
        if (special.equalsIgnoreCase("Technical")) {
            salary = baseSalary + 5000;
        } else if (special.equalsIgnoreCase("Managerial")) {
            salary = baseSalary + 8000;
        } else {
            salary = baseSalary;
        }
        salary += workExperience * 1000;
    }
}

class manager extends employee {
    String dep;

    void calculateSal() {
        double baseSalary = 50000;
        if (dep.equalsIgnoreCase("HR")) {
            salary = baseSalary + 6000;
        } else if (dep.equalsIgnoreCase("Finance")) {
            salary = baseSalary + 8000;
        } else {
            salary = baseSalary;
        }
        salary += workExperience * 1500;
    }
}

class print {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        officer a = new officer();
        manager b = new manager();

        System.out.println("Enter the Officer's details");
        System.out.println("Enter The Name:");
        a.name = s.nextLine();
        System.out.println("Enter the Age:");
        a.age = s.nextInt();
        System.out.println("Enter the address:");
        s.nextLine();
        a.address = s.nextLine();
        System.out.println("Enter the phone number:");
        a.phone = s.nextLong();
        System.out.println("Enter the Specialization:");
        s.nextLine();
        a.special = s.nextLine();
        System.out.println("Enter the Work Experience (in years):");
        a.workExperience = s.nextInt();
        a.calculateSal();

        System.out.println("Enter the Manager's details");
        System.out.println("Enter The Name:");
        b.name = s.nextLine();
        System.out.println("Enter the Age:");
        b.age = s.nextInt();
        System.out.println("Enter the address:");
        s.nextLine();
        b.address = s.nextLine();
        System.out.println("Enter the phone number:");
        b.phone = s.nextLong();
        System.out.println("Enter the Department:");
        s.nextLine();
        b.dep = s.nextLine();
        System.out.println("Enter the Work Experience (in years):");
        b.workExperience = s.nextInt();
        b.calculateSal();

        System.out.println("The details of the officer are:");
        System.out.println("Name:\t" + a.name);
		s.nextLine();
        System.out.println("Age:\t" + a.age);
        System.out.println("Address:\t" + a.address);
        System.out.println("Phone number:\t" + a.phone);
        a.printSal();
        System.out.println("Specialization:\t" + a.special);

        System.out.println("The details of the Manager are:");
        System.out.println("Name:\t" + b.name);
        System.out.println("Age:\t" + b.age);
        System.out.println("Address:\t" + b.address);
        System.out.println("Phone number:\t" + b.phone);
        b.printSal();
        System.out.println("Department:\t" + b.dep);
    }
}
