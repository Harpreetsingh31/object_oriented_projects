import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/**
 * Write a description of class PhonePanel here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class PhonePanel extends JPanel
{
    // instance variables - replace the example below with your own
    private JLabel label;
    private JButton ClearButton;
    
    /**
     * Constructor for objects of class PhonePanel
     */
    public PhonePanel()
    {
        // initialise instance variables
        clearButton Clearbutton = new clearButton(this);
        label = new JLabel(" ");
        setLayout(new BorderLayout());
        add(label, BorderLayout.NORTH);
        KeypadPanel keyPad = new KeypadPanel(this);
        add( keyPad, BorderLayout.SOUTH); 
        
        ClearButton = new JButton("Clear");
        ClearButton.addActionListener(Clearbutton);
        add(ClearButton);
        
        
        
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void refreshUI(String text)
    {
        // put your code here
        String y =label.getText();
        label.setText(y+text);
        
    }
    
     public void clear()
    {
        // put your code here
        String text = " ";
        label.setText(text);
        
    }
}
