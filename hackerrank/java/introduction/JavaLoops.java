import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;

import java.util.StringTokenizer;

public class JavaLoops {
    public static void main(String[] args) throws IOException {
        InputReader in  = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        new Problem().solve(in, out);

        in.close();
        out.close();
    }

    private static class Problem {
        public void solve(InputReader in, PrintWriter out) throws IOException {
            int testCases = in.nextInt();

            for (int test = 0; test < testCases; ++test) {
                int a = in.nextInt();
                int b = in.nextInt();
                int n = in.nextInt();

                int factor  = 1;
                int element = a;

                for (int i = 0; i < n; ++i) {
                    element += factor * b;
                    factor  *= 2;

                    if (i > 0) {
                        out.print(" ");
                    }

                    out.print(element);
                }

                out.println();
            }
        }
    }

    private static class InputReader {
        private BufferedReader  reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }

            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public String nextLine() throws IOException {
            return reader.readLine();
        }

        public void close() throws IOException {
            reader.close();
        }
    }
}
