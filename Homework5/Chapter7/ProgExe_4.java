public class ProgExe_4 {

  public static int a = 3;

  public static int whoops() {
    a += 5;
    return 4;
  }

  public static int test(boolean flag)  {
    if(flag)
      a = a + whoops(); // returns 7
    else
      a = whoops() + a; // returns 12

    return a;
  }

  public static void main(String[] args) {
    System.out.println(test(true));
    ProgExe_4.a = 3;
    System.out.println(test(false));
  }

  //Java always evaluates expressions in left to right order,
  //so it's possible to avoid the problems that come with
  //calling functions in operand evaluation.

}
