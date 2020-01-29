import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class CellDivisionCounterTest.
 *
 * @author  D.L. Bailey, SCE, Carleton U.
 * @version 1.01 Feb 9, 2015
 */
public class CellDivisionCounterTest
{
    private CellDivisionCounter counter;
    
    /**
     * Default constructor for test class CellDivisionCounterTest
     */
    public CellDivisionCounterTest()
    {
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    {
        counter = new CellDivisionCounter();
    }

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    @After
    public void tearDown()
    {
    }
    
    @Test
    public void testInitialState()
    {
        /* Verify that the initial value of the counter is 1,
         * and that its minimum and maximum values are correct. 
         */        
        assertEquals(1, counter.getCount());
        assertEquals(1, counter.minimumCount());
        assertEquals(Integer.MAX_VALUE, counter.maximumCount());
    }
    
    @Test
    public void testCountUp()
    {
        int expected = 1;
        
        /* Verify that we count 2, 4, 8, 16, 32. */
        for (int n = 1; n <= 5; n += 1) {
            expected = expected * 2;
            counter.countUp();
            assertEquals(expected, counter.getCount());
        }
    }
    
    @Test
    public void testMaximumNotExceeded()
    {
        int expected = 1;
        
        /* Count 2, 4, 8, 16, ..., 2^30. */
        for (int n = 1; n <= 30; n += 1) {
            expected = expected * 2;
            counter.countUp();
        }
        
        /* Verify that the count has reached 2^30. */
        assertEquals(expected, counter.getCount());
        
        /* The count is now 2^30, which cannot be doubled, 
         * because the largest int that can be represented in Java
         * is 2^31 - 1. Calling countUp now shouldn't change the
         * state of the counter.
         */
        counter.countUp();
        assertEquals(expected, counter.getCount());
    }
    
    @Test
    public void testReset()
    {
        for (int i = 1; i <= 4; i += 1) {
            counter.countUp();
        }
        
        /* Count 2, 4, 6, 8, then reset the counter.
         * Verify that the count is now 1.
         */ 
        counter.reset();
        assertEquals(1, counter.getCount());
        assertTrue(counter.isAtMinimum());
    } 
    
    @Test
    public void testCountDown()
    {
        counter.countUp(); // count should now be 2
        counter.countUp(); // count should now be 4
        
        counter.countDown();
        assertEquals(3, counter.getCount());       
        counter.countDown();
        assertEquals(2, counter.getCount());           
        counter.countDown();
        assertEquals(1, counter.getCount());  
        
        // Verify the the count remains at 1
        counter.countDown();
        assertEquals(1, counter.getCount());         
    }      
}
