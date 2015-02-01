import java.util.ArrayList;
import java.util.Arrays;
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

    public void parseLine(String line) {
        String[] parts = line.split(" ");

        if (parts[0].contains("DEF")) {       //DEF a ;
            vars.put(parts[1], 0);
        } else if (parts[0].contains("FOR")) {
            ArrayList<String> statements = buildForStatements(parts);
            int count = Integer.parseInt(parts[1]);
            for(int i = 0; i < count; i++)  {
                for(String s: statements)   {
                    String[] statement = s.split(" ");
                    doOp(statement);
                }
            }

        } else if (vars.containsKey(parts[0])) {       //starts with letter in hashmap
            if (parts[1].equals("=")) {      // a =
                if (vars.containsKey(parts[2])) {       //a = another letter in hashmap
                    vars.put(parts[0], vars.get(parts[2]));
                } else {        // a = number
                    vars.put(parts[0], Integer.parseInt(parts[2]));
                }
            } else {
                doOp(parts);
            }
        }
    }

    public void doOp(String[] parts)  {     //pass this guy something like a = 3
        if(parts[1].contains("+"))  {
            if (vars.containsKey(parts[2])) {
                vars.put(parts[0], vars.get(parts[2]) + vars.get(parts[0]));
            } else {
                vars.put(parts[0], Integer.parseInt(parts[2]) + vars.get(parts[0]));
            }
        }
        if(parts[1].contains("-"))  {
            if (vars.containsKey(parts[2])) {
                vars.put(parts[0], vars.get(parts[2]) - vars.get(parts[0]));
            } else {
                vars.put(parts[0], Integer.parseInt(parts[2]) - vars.get(parts[0]));
            }
        }
        if(parts[1].contains("*")) {
            if (vars.containsKey(parts[2])) {
                vars.put(parts[0], vars.get(parts[2]) * vars.get(parts[0]));
            } else {
                vars.put(parts[0], Integer.parseInt(parts[2]) * vars.get(parts[0]));
            }
        }
    }

    public ArrayList<String> buildForStatements(String[] parts)  {
        ArrayList<String> words = new ArrayList<String>(Arrays.asList(parts));
        ArrayList<String> ret = new ArrayList<String>();

        StringBuilder sb = new StringBuilder();
        for(int i = 2; !words.get(i).equals("ENDFOR"); i++) {
            if(words.get(i).equals(";")) {
                ret.add(sb.toString());         //need to split this
                sb.setLength(0);
            }
            else {
                sb.append(words.get(i) + " ");      //Definitely hacky, but it works
            }
        }

        return ret;
    }

    public void printVars()	{
        for(Entry<String, Integer> entry: vars.entrySet()){
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }
    }
}
