import java.util.ArrayList;
import java.util.List;

public class Student {
	private String name;
	private List<Integer> homeworkGrades;
	private List<Integer> quizGrades;
	private double homeworkScore;
	private double quizScore;
	private double examScore;
	
	public Student(String name, List<Integer> homework, List<Integer> quiz, int exam)	{
		this.name = name;
		homeworkGrades = homework;
		quizGrades = quiz;
		
		homeworkScore = homeworkAverage();
		quizScore = quizAverage();
		examScore = exam;
	}
	
	double homeworkAverage()	{
		return homeworkGrades.stream().mapToInt(i -> i).average().orElseThrow(IllegalArgumentException::new);
	}
	
	double quizAverage()	{
		return quizGrades.stream().mapToInt(i -> i).average().orElseThrow(IllegalArgumentException::new);
	}
	
	public double getGrade()	{
		return homeworkScore * .35 + quizScore * .20 + examScore * .45;
	}
	
	public char getLetterGrade()	{
		double grade = getGrade();
		if(grade > 90)
			return 'A';
		else if(grade > 80)
			return 'B';
		else if(grade > 70)
			return 'C';
		else if(grade > 60)
			return 'D';
		else
			return 'F';
	}
	
	public String getName()	{
		return this.name;
	}
	
	public String toString()	{
		return String.format("%s %.1f %c", this.name, this.getGrade(), this.getLetterGrade());
	}
}