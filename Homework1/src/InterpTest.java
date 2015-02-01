import java.io.*;

/**
 * Created by Craig on 1/31/2015.
 */

public class InterpTest {
    public static void main(String[] args) throws IOException {

        ZInterpreter interp = new ZInterpreter();
        BufferedReader br = new BufferedReader(new FileReader(args[0]));
        String line = null;
        while ((line = br.readLine()) != null) {
            interp.parseLine(line);
        }
        interp.printVars();

    }
}
