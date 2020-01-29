import javax.swing.JFrame;

/**
 * SYSC 2004 Winter 2015 Lab 11
 * A mockup of the GUI for a telephone.
 * 
 * @version (insert today's date)
 */
public class PhoneGUI
{
   /**
    * Creates and displays the main program frame.
    */
   public static void main(String[] args)
   {
      JFrame frame = new JFrame("Telephone");
      PhonePanel panel = new PhonePanel();
      
      frame.getContentPane().add(panel);      
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.pack();
      frame.setVisible(true);
   }
}
