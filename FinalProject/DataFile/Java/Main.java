import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
	static Student makeStudent(String stats)	{
		List<String> parts = Arrays.asList(stats.split(" "));

		String name = parts.get(0);
		List<Integer> homework = parts.subList(1, 4).stream()
				.map(Integer::valueOf).collect(Collectors.toList());
		List<Integer> quiz = parts.subList(4, parts.size() - 1).stream()
				.map(Integer::valueOf).collect(Collectors.toList());
		int exam = Integer.parseInt(parts.get(parts.size() - 1));

		return new Student(name, homework, quiz, exam);
	}

	public static void main(String[] args)	{
		String fileName = args[0];
		BufferedReader input = null;
		ArrayList<Student> students = new ArrayList<Student>();
		String line;

		try {
			input = new BufferedReader(new FileReader(fileName));
			while((line = input.readLine()) != null)	{
				students.add(makeStudent(line));
			}
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

		for(Student s : students)	{
			System.out.println(s.toString());
		}
	}
}
