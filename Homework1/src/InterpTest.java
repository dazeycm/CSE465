import java.io.*;

/**
 * Created by Craig on 1/31/2015.
 */

public class InterpTest {
    public static void main(String[] args) throws IOException {
        ZInterpreter interp = new ZInterpreter();

        BufferedReader br = new BufferedReader(new FileReader(args[0]));

        String line = null;
        while((line = br.readLine()) != null)  {
            interp.parseLine(line);
        }

        interp.printVars();

        int a = 0;
        int b = 0;
        a = 1;
        for(int i = 0; i < 20; i++) {
            b += a;
            a *= 2;
        }
        a += 1000;
        for(int i = 0; i < 20; i++) {
            b -= a;
            a += 2;
        }

        System.out.println(a);
        System.out.println(b);


    }


}
