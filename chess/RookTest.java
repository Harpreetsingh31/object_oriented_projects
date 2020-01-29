import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class RookTest.
 *
 * @author  D.L. Bailey
 * @version 1.00 March 26, 2007, v 1.01 March 7, 2012
 */
public class RookTest
{
    /**
     * Default constructor for test class RookTest
     */
    public RookTest()
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
        Rook r;
        
        r = new Rook(true, 3, 2);
        assertEquals("White Rook, row = 3, column = 2", r.toString());
        
        r = new Rook(false, 4, 4);
        assertEquals("Black Rook, row = 4, column = 4", r.toString()); 
    }
        
    @Test
    public void testCanMoveTo() 
    {
        Rook r;
         
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(1, 2));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());
        
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(5, 2));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());        
        
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(3, 1));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());        
        
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(3, 5));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());        
        
        r = new Rook(true, 3, 4);
        assertFalse(r.canMoveTo(5, 2));
        
        r = new Rook(true, 1, 5);
        assertFalse(r.canMoveTo(0, 5));
        
        r = new Rook(true, 8, 5);
        assertFalse(r.canMoveTo(9, 5));
        
        r = new Rook(true, 5, 1);
        assertFalse(r.canMoveTo(5, 0));
        
        r = new Rook(true, 5, 8);
        assertFalse(r.canMoveTo(5, 9));                   
    }
    
    @Test
    public void testMoveTo() 
    {
        Rook r;
         
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(1, 2));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());
        r.moveTo(1, 2);
        assertEquals(1, r.getRow());
        assertEquals(2, r.getColumn());
        
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(5, 2));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());        
        r.moveTo(5, 2);
        assertEquals(5, r.getRow());
        assertEquals(2, r.getColumn());
        
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(3, 1));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());        
        r.moveTo(3, 1);
        assertEquals(3, r.getRow());
        assertEquals(1, r.getColumn());
        
        r = new Rook(true, 3, 2);
        assertTrue(r.canMoveTo(3, 5));
        assertEquals(3, r.getRow());
        assertEquals(2, r.getColumn());        
        r.moveTo(3, 5);
        assertEquals(3, r.getRow());
        assertEquals(5, r.getColumn()); 
        
        r = new Rook(true, 3, 4);
        assertFalse(r.canMoveTo(5, 2));
        r.moveTo(5, 2);
        assertEquals(3, r.getRow());
        assertEquals(4, r.getColumn());
        
        r = new Rook(true, 1, 5);
        assertFalse(r.canMoveTo(0, 5));
        
        r = new Rook(true, 8, 5);
        assertFalse(r.canMoveTo(9, 5));
        
        r = new Rook(true, 5, 1);
        assertFalse(r.canMoveTo(5, 0));
        
        r = new Rook(true, 5, 8);
        assertFalse(r.canMoveTo(5, 9));                   
    }    
}
