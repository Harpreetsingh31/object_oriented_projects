import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class BishopTest.
 *
 * @author  D.L. Bailey
 * @version 1.00 March 26, 2007, v 1.01 March 7, 2012
 */
public class BishopTest
{
    /**
     * Default constructor for test class BishopTest
     */
    public BishopTest()
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
    public void testToString()
    {
        Bishop b;
        
        b = new Bishop(true, 3, 2);
        assertEquals("White Bishop, row = 3, column = 2", b.toString());       
        
        b = new Bishop(false, 4, 4);
        assertEquals("Black Bishop, row = 4, column = 4", b.toString());  
    }
   
    @Test
    public void testCanMoveTo() 
    {
        Bishop b;  
        
        b = new Bishop(true, 5, 4);
        assertTrue(b.canMoveTo(3, 2));
        assertEquals(5, b.getRow());
        assertEquals(4, b.getColumn());
        
        b = new Bishop(true, 5, 4);
        assertTrue(b.canMoveTo(7, 6));
        assertEquals(5, b.getRow());
        assertEquals(4, b.getColumn());        
        
        b = new Bishop(true, 3, 4);
        assertFalse(b.canMoveTo(3, 6));
        
        b = new Bishop(true, 3, 4);
        assertFalse(b.canMoveTo(1, 4));
        
        b = new Bishop(true, 1, 5);
        assertFalse(b.canMoveTo(0, 4));
        
        b = new Bishop(true, 8, 5);
        assertFalse(b.canMoveTo(9, 6));
        
        b = new Bishop(true, 5, 1);
        assertFalse(b.canMoveTo(4, 0));
        
        b = new Bishop(true, 5, 8);
        assertFalse(b.canMoveTo(6, 9));                   
    }
    
    @Test
    public void testMoveTo() 
    {
        Bishop b;
        
        b = new Bishop(true, 5, 4);
        assertTrue(b.canMoveTo(3, 2));
        assertEquals(5, b.getRow());
        assertEquals(4, b.getColumn());
        b.moveTo(3, 2);
        assertEquals(3, b.getRow());
        assertEquals(2, b.getColumn());
        
        b = new Bishop(true, 5, 4);
        assertTrue(b.canMoveTo(7, 6));
        assertEquals(5, b.getRow());
        assertEquals(4, b.getColumn());        
        b.moveTo(7, 6);
        assertEquals(7, b.getRow());
        assertEquals(6, b.getColumn());
        
        b = new Bishop(true, 3, 4);
        assertFalse(b.canMoveTo(3, 6));
        b.moveTo(3, 6);
        assertEquals(3, b.getRow());
        assertEquals(4, b.getColumn());
        
        b = new Bishop(true, 3, 4);
        assertFalse(b.canMoveTo(1, 4));
        b.moveTo(1, 4);
        assertEquals(3, b.getRow());
        assertEquals(4, b.getColumn());
        
        b = new Bishop(true, 1, 5);
        assertFalse(b.canMoveTo(0, 4));
        
        b = new Bishop(true, 8, 5);
        assertFalse(b.canMoveTo(9, 6));
        
        b = new Bishop(true, 5, 1);
        assertFalse(b.canMoveTo(4, 0));
        
        b = new Bishop(true, 5, 8);
        assertFalse(b.canMoveTo(6, 9));                   
    }    
}
