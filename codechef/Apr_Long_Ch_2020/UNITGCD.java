import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class UNITGCD {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int t = sc.nextInt();
            Print printer = new Print();
            while (t > 0) {
                int n = sc.nextInt();
                if (n <= 3) {
                    //System.out.println(1);
                    printer.println(1);
                    if (n == 1) printer.println("1 1");//System.out.println("1 1");
                    else if (n == 2) printer.println("2 1 2");//System.out.println("2 1 2");
                    else printer.println("3 1 2 3");//System.out.println("3 1 2 3");
                } else {
                    printer.println(n / 2);//System.out.println(n / 2);
                    printer.println("3 1 2 3");//System.out.println("3 1 2 3");
                    for (int i = 4; i <= n; i += 2) {
                        if (i + 1 <= n) {
                            printer.println("2 " + i + " " + (i + 1));//System.out.println("2 " + i + " " + (i + 1));
                        } else {
                            printer.println("1 " + i);//System.out.println("1 " + i);
                        }
                    }
                }
                t--;
            }
            printer.close();
        }
    }

    static class Print {
        private final BufferedWriter bw;

        public Print() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
        }
    }

}