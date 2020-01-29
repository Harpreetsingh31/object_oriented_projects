/**
 * This class implements an up-counter that mimics the cell division 
 * process. Counting up doubles the current count, as long as doing so 
 * will not exceed the counter's maximum value. Counting down reduces
 * the count by 1.
 * 
 * @author D.L. Bailey, SCE, Carleton University
 * @version 1.00 Feb. 9, 2015
 */
public class CellDivisionCounter extends Counter
{
    private static final int MIN_COUNT = 1;
    
    /* The largest int that can be represented in Java is 
     * Integer.MAX_VALUE, which is 2^31 - 1.
     */
    private static final int MAX_COUNT = Integer.MAX_VALUE;
    
    /**
     * Constructs a new CellDivisionCounter whose current count 
     * and minimum count are initialized to MIN_COUNT, and whose
     * maximum count is initialized to MAX_COUNT.
     */
    public CellDivisionCounter()
    {
        super(MIN_COUNT, MAX_COUNT);
    }

    /**
     * Double this counter's current value. If doubling the count
     * would cause this counter to exceed its maximum value, the 
     * state of the counter is not changed; i.e., the current count
     * is not increased.
     */
    public void countUp()
    {  
        
        int i = getCount();
        
          if(i < maximumCount()/2){
            while(i >0){
                super.countUp();
                i--;            
            }
            
      }  
    }
      
}


