import java.awt.event.*;
import javax.swing.*;

/**
 * Write a description of class clearButton here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class clearButton implements ActionListener
{
    private PhonePanel c;
    
    public clearButton(PhonePanel c)
    {
        this.c=c;
     
    }
   
    public void  actionPerformed(ActionEvent event)
    {
        c.clear();
    }
}
