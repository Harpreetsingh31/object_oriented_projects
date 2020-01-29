/**
 * This class implements an up-counter that counts between a minimum value
 * and a maximum value, inclusive. After the counter reaches its maximum
 * value, counting up causes the counter to roll over to its minimum value.
 * 
 * @author D.L. Bailey, SCE, Carleton University
 * @version 1.00 Feb. 14, 2012;
 *          1.01 Feb. 5, 2015 (edit comments).
 */
public class RollOverCounter extends Counter
{
    /**
     * Constructs a new RollOverCounter whose current count is initialized 
     * to Counter.DEFAULT_MINIMUM, and which counts between
     * Counter.DEFAULT_MINIMUM and Counter.DEFAULT_MAXIMUM, inclusive.
     */
    public RollOverCounter()
    {
        super();
    }

    /**
     * Constructs a new RollOverCounter whose current count is initialized 
     * to minCount, and which counts between minCount and maxCount, 
     * inclusive.
     */
    public RollOverCounter(int minCount, int maxCount)
    {
        super(minCount, maxCount);
    }

    /**
     * Increments this counter by 1.
     * If we've reached the maximum count, calling this method rolls the 
     * counter over to its minimum value.
     */
    public void countUp()
    {
        if (isAtMaximum()) {
            reset();
        } else {
            super.countUp();
        }
    }
}
