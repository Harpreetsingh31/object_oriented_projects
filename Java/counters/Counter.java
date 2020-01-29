/**
 * This class is designed to be used as the superclass for different
 * types of up-counters.
 * 
 * @author D.L. Bailey, SCE, Carleton University
 * @version 1.00 Feb. 14, 2012;
 *          1.01 Feb. 9, 2015 (edit comments, define countDown).
 */
public class Counter
{
    /** The current value of this counter. */
    private int count;

    /** The minimum value of this counter. */
    private int minimumCount;

    /** The maximum value of this counter. */
    private int maximumCount;

    /** The default minimum value of this counter. */
    private static final int DEFAULT_MINIMUM = 0;

    /** The default maximum value of this counter. */
    private static final int DEFAULT_MAXIMUM = 999;

    /**
     * Constructs a new Counter whose current count is initialized to 
     * DEFAULT_MINIMUM, and which is in tended to count between 
     * DEFAULT_MINIMUM and DEFAULT_MAXIMUM, inclusive.
     */
    public Counter()
    {
        this(DEFAULT_MINIMUM, DEFAULT_MAXIMUM);
    }

    /**
     * Constructs a new Counter whose current count is initialized to 
     * minCount, and which is intended to count between minCount and 
     * maxCount, inclusive.
     * 
     * @param The minimum value for this counter.
     * @param The maximum value for this counter.
     */
    public Counter(int minCount, int maxCount)
    {
        minimumCount = minCount;
        maximumCount = maxCount;
        count = minimumCount;
    }

    /**
     * Returns the maximum value of this counter.
     * 
     * @return The counter's maximum value.
     */
    public int maximumCount()
    {
        return maximumCount;
    }

    /**
     * Returns the minimum value of this counter.
     * 
     * @return The counter's minimum value.
     */
    public int minimumCount()
    {
        return minimumCount;
    }

    /**
     * Returns this counter's current count.
     * 
     * @return The counter's current value.
     */
    public int getCount()
    {
        return count;
    }

    /**
     * Determines if this counter is at its minimum value.
     * 
     * @return true if this counter is at it minimum value;
     * otherwise false.
     */
    public boolean isAtMinimum()
    {
         return (count == minimumCount);
    }

    /**
     * Determines if this counter is at its maximum value.
     * 
     * @return true if this counter is at its maximum value;
     * otherwise false.
     */
    public boolean isAtMaximum()
    {
        return (count == maximumCount);
    }

    /**
     * Resets this counter to its minimum value.
     */
    public void reset()
    {
        count = minimumCount;
    }

    /**
     * Increments this counter by 1.
     * 
     * This method should overridden by a countUp method in 
     * every subclass, to provide countUp behaviour that is 
     * appropriate for instances of the subclass.
     */
    public void countUp()
    {
        count++;
    }
    
    // Solution to Exercise 5
    /**
     * Decrements this counter by 1. 
     * If we've reached the minimum count, calling this method doesn't 
     * change the state of the counter.
     */
    public void countDown()
    {
        if(count == minimumCount){
        }else{
        count--;
        }
    }
}

