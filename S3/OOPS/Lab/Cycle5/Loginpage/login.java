import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class LoginUI implements ActionListener {
    JFrame frame;
    JTextField usernameField;
    JPasswordField passwordField;
    JButton submitButton, clearButton;

    LoginUI() {
        frame = new JFrame("Login");

        JLabel usernameLabel = new JLabel("Username:");
        usernameField = new JTextField(15);
        
        JLabel passwordLabel = new JLabel("Password:");
        passwordField = new JPasswordField(15);
        
        submitButton = new JButton("Submit");
        clearButton = new JButton("Clear");

        submitButton.addActionListener(this);
        clearButton.addActionListener(this);

        JPanel panel = new JPanel(new GridLayout(3, 2, 5, 5));
        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(clearButton);
        panel.add(submitButton);

        frame.add(panel);
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == clearButton) {
            usernameField.setText("");
            passwordField.setText("");
        } else if (e.getSource() == submitButton) {
            showWelcomePage();
        }
    }

    private void showWelcomePage() {
        frame.getContentPane().removeAll();
        frame.getContentPane().revalidate();
        frame.getContentPane().repaint();

        JLabel welcomeLabel = new JLabel("Welcome!", SwingConstants.CENTER);
        frame.add(welcomeLabel);
        frame.setSize(300, 100);
    }

    public static void main(String[] args) {
        new LoginUI();
    }
}
