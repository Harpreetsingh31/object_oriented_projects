 import java.awt.event.*;
import javax.swing.*;

/**
 * SYSC 2004 Winter 2015 Lab 11
 * 
 * The listener for the dialling buttons (digits 0-9, plus * and #)
 * on a phone keypad.
 * 
 * @version (insert today's date)
 */
public class ButtonListener implements ActionListener
{   
    private PhonePanel P;
    public ButtonListener(PhonePanel P)
    {
        this.P=P;
    }
   
    public void actionPerformed(ActionEvent event)
    {
        /* Get a reference to the button that was clicked. */ 
        JButton button = (JButton) event.getSource();
        
        /* Get the text that is displayed on the button. */
        String key = button.getText();
        P.refreshUI(key);
        //System.out.println("The " + key + " key was clicked.");
    }
}
