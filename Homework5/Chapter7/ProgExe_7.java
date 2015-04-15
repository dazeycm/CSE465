public class ProgExe_7 {

  int a = 0;

  public static void print(int a, int b) {
    System.out.printf("%d, %d\n", a, b);
  }

  public static void test() {
    int j = 0;

    for (int i = 0; i < 5; i++) {
      print(j, j++);
    }
    // prints 0 0, 1 1, 2 2, 3 3, 4 4

    for (int i = 0; i < 5; i++) {
      print(j++, j);
    }
    // prints 5 6, 6 7, 7 8, 8 9, 9, 10

    // The left parameter is calculated before the right parameter.
  }

  public static void main(String[] args) {
    ProgExe_7.test();
  }
}
