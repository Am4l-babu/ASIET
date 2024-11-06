import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Calculate {
    float sum(float a, float b) {
        return a + b;
    }

    float sub(float a, float b) {
        return a - b;
    }

    float div(float a, float b) {
        try {
            return a/b;
            }
       	catch(Exception e){
       		System.out.println("Division by 0 is not possible");
       		return Float.POSITIVE_INFINITY;
       	}
       
    }

    float mul(float a, float b) {
        return a * b;
    }
}

class UI implements ActionListener {
    JFrame frame;
    JTextField screen;
    float a, b, result;
    String operator;
    Calculate calc;
    
    JButton one, two, three, four, five, six, seven, eight, nine, zero, sum, sub, div, mul, equals, clear;

    public UI() {
        frame = new JFrame("Calculator");
        frame.setSize(250, 350);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        screen = new JTextField();
        screen.setBounds(50, 50, 150, 30);
        screen.setEditable(false);
        
        calc = new Calculate();
        
        one = createButton("1", 50, 100);
        two = createButton("2", 100, 100);
        three = createButton("3", 150, 100);
        four = createButton("4", 50, 150);
        five = createButton("5", 100, 150);
        six = createButton("6", 150, 150);
        seven = createButton("7", 50, 200);
        eight = createButton("8", 100, 200);
        nine = createButton("9", 150, 200);
        zero = createButton("0", 100, 250);
        
        sum = createButton("+", 200, 100);
        sub = createButton("-", 200, 150);
        mul = createButton("*", 200, 200);
        div = createButton("/", 200, 250);
        equals = createButton("=", 150, 250);
        clear = createButton("C", 50, 250);
        
        frame.add(screen);
        frame.add(one);
        frame.add(two);
        frame.add(three);
        frame.add(four);
        frame.add(five);
        frame.add(six);
        frame.add(seven);
        frame.add(eight);
        frame.add(nine);
        frame.add(zero);
        frame.add(sum);
        frame.add(sub);
        frame.add(mul);
        frame.add(div);
        frame.add(equals);
        frame.add(clear);
        
        frame.setVisible(true);
    }

    private JButton createButton(String text, int x, int y) {
        JButton button = new JButton(text);
        button.setBounds(x, y, 50, 50);
        button.addActionListener(this);
        return button;
    }

    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();
        
        if (command.charAt(0) == 'C') {
            screen.setText("");
            a = b = result = 0;
            operator = "";
        } else if (command.charAt(0) == '=') {
            b = Float.parseFloat(screen.getText());
            switch (operator) {
                case "+":
                    result = calc.sum(a, b);
                    break;
                case "-":
                    result = calc.sub(a, b);
                    break;
                case "*":
                    result = calc.mul(a, b);
                    break;
                case "/":
                    result = calc.div(a, b);
                    break;
            }
            screen.setText(String.valueOf(result));
            a = result;
        } else if ("0123456789".indexOf(command) >= 0) {
            screen.setText(screen.getText() + command);
        } else {
            if (!screen.getText().isEmpty()) {
                a = Float.parseFloat(screen.getText());
                operator = command;
                screen.setText("");
            }
        }
    }
}
class main{
	public static void main(String[] args) {
        UI a=new UI();
    }
}

	
	
