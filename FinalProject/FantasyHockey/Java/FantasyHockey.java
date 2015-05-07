import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FantasyHockey {
	
	static void printPlayerScore(String name, HashMap<String, Integer> goals)	{
		if(!goals.containsKey(name))	{
			System.out.println(String.format("%s scored 0 goals", name));
			return;
		}

		System.out.println(String.format("%s scored %d goals!", name, goals.get(name)));
		
	}
	
	public static void main(String[] args)	{
		final String SEARCH = "goal scored";
		
		String fileName = "C:\\Users\\Craig\\Desktop\\CSE465\\FinalProject\\FantasyHockey\\Java\\NHL.txt";
		//String fileName = args[0];
		BufferedReader input = null;
		String line;
		HashMap<String, Integer> playerGoals = new HashMap<String, Integer>();

		try {
			input = new BufferedReader(new FileReader(fileName));
			while((line = input.readLine()) != null)	{
				if(line.toLowerCase().contains(SEARCH))	{
					System.out.println(line);
					List<String> parts = Arrays.asList(line.split(" "));
					for(int i = 0; i < parts.size() - 1; i++)	{
						if (parts.get(i).equals("by"))	{
							String firstName = parts.get(i + 1);
							String lastName = parts.get(i + 2);
							lastName = Arrays.asList(lastName.split("\\(")).get(0);
							
							String name = firstName + " " + lastName;
							
							if(playerGoals.containsKey(name))	{
								playerGoals.put(name, playerGoals.get(name) + 1);
								break;
							} else	{
								playerGoals.put(name, 1);
								break;
							}
						}
					}
				}
			}
			printPlayerScore("Travis Zajac", playerGoals);
			printPlayerScore("Jaromir Jagr", playerGoals);
			printPlayerScore("Dmitry Kulikov", playerGoals);
			printPlayerScore("Dan Ellis", playerGoals);
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.out.println("Failed to open the file");
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("Error reading line from file");
		} finally {
			try {
				if(input != null) input.close();
			} catch (IOException e) {
				e.printStackTrace();
				System.out.println("Error closing bufferedReader");
			}
		}
	}
}