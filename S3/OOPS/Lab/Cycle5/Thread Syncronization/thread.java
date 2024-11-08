class BankAccount {
    private int balance = 1000;

    public synchronized void deposit(int amount) {
        balance += amount;
        System.out.println(Thread.currentThread().getName() + " deposited: " + amount + ", New Balance: " + balance);
    }

    public synchronized void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println(Thread.currentThread().getName() + " withdrew: " + amount + ", New Balance: " + balance);
        } else {
            System.out.println(Thread.currentThread().getName() + " tried to withdraw: " + amount + " but insufficient funds. Balance: " + balance);
        }
    }

    public int getBalance() {
        return balance;
    }
}

class AccountHolder extends Thread {
    private BankAccount account;

    public AccountHolder(BankAccount account) {
        this.account = account;
    }

    public void run() {
        for (int i = 0; i < 3; i++) {
            account.deposit(100);
            account.withdraw(200);
        }
    }
}

class Main {
    public static void main(String[] args) {
        BankAccount sharedAccount = new BankAccount();

        AccountHolder holder1 = new AccountHolder(sharedAccount);
        AccountHolder holder2 = new AccountHolder(sharedAccount);

        holder1.setName("AccountHolder 1");
        holder2.setName("AccountHolder 2");

        holder1.start();
        holder2.start();
    }
}
