/**
 * This class implements a up-counter that counts between a minimum value
 * and a maximum value, inclusive. It must be reset to the minimum value
 * once it reaches its maximimum value.
 * 
 * @author D.L. Bailey, SCE, Carleton University
 * @version 1.00 Feb. 14, 2012;
 *          1.01 Feb 5, 2015 (edit comments).
 */
public class LimitedCounter extends Counter
{
    /**
     * Constructs a new LimitedCounter whose current count is initialized to 
     * Counter.DEFAULT_MINIMUM, and which counts between Counter.DEFAULT_MINIMUM 
     * and Counter.DEFAULT_MAXIMUM, inclusive.
     */
    public LimitedCounter()
    {
        super();
    }

    /**
     * Constructs a new LimitedCounter whose current count is initialized to 
     * minCount, and which counts between minCount and maxCount, inclusive.
     */
    public LimitedCounter(int minCount, int maxCount)
    {
        super(minCount, maxCount);
    }

    /**
     * Increments this counter by 1.
     * If we've reached the maximum count, calling this method doesn't change the 
     * state of the counter.
     */
    public void countUp()
    {
        if (!isAtMaximum()) {
            super.countUp();
        }
    }
}
