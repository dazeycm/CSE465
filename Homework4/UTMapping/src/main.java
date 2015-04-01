
public class main {

	public static int UTMapping(int N, int r, int c)	{
		if (r > c)
			return -1;
		else
			return (r * N) - ((r - 1) * r / 2) + (c - r);
	}
	
	public static void main(String[] args) {
		
	}

}
