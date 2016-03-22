import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;

import java.util.StringTokenizer;

public class JavaIfElse {
    public static void main(String[] args) {
        InputReader in  = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int number = in.nextInt();

        if (number % 2 == 1) {
            out.println("Weird");
        }
        else if (number <= 5) {
            out.println("Not Weird");
        }
        else if (number <= 20) {
            out.println("Weird");
        }
        else {
            out.println("Not Weird");
        }

        in.close();
        out.close();
    }

    private static class InputReader {
        private BufferedReader  reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                catch (IOException exception) {
                    throw new RuntimeException(exception);
                }
            }

            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public void close() {
            try {
                reader.close();
            }
            catch (IOException exception) {
                throw new RuntimeException(exception);
            }
        }
    }
}
