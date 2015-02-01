import java.util.HashMap;
import java.util.Map.Entry;

/**
 * Created by Craig on 1/31/2015.
 */

public class ZInterpreter {

    private HashMap<String, Integer> vars;

    public ZInterpreter() 	{
        vars = new HashMap();
    }

    public void parseLine(String line)	{
        String[] parts = line.split(" ");

        if(parts[0].contains("DEF"))    {
            vars.put(parts[1], 0);
        }

    }

    public void printVars()	{
        for(Entry<String, Integer> entry: vars.entrySet()){
            System.out.println(entry.getKey() + " = " + entry.getValue() + "\n");
        }
    }
}
