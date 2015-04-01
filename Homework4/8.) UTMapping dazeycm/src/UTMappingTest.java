import static org.junit.Assert.*;

import org.junit.Test;


public class UTMappingTest {

	@Test
	public void UTMappingTest1() {
		assertEquals(0, main.UTMapping(4, 0, 0));
	}
	
	@Test
	public void UTMappingTest2() {
		assertEquals(8, main.UTMapping(4, 2, 3));
	}
	
	@Test
	public void UTMappingTest3() {
		assertEquals(3, main.UTMapping(4, 0, 3));
	}
	
	@Test
	public void UTMappingTest4() {
		assertEquals(9, main.UTMapping(4, 3, 3));
	}
	
	@Test
	public void UTMappingTest5() {
		assertEquals(-1, main.UTMapping(4, 3, 2));
	}

}
