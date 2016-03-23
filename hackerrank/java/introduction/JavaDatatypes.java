import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;

import java.util.StringTokenizer;

import java.math.BigInteger;

public class JavaDatatypes {
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
                BigInteger number = in.nextBigInteger();
                out.printf("%d ", number);

                if (number.compareTo(BigInteger.valueOf(Long.MIN_VALUE)) < 0 ||
                    number.compareTo(BigInteger.valueOf(Long.MAX_VALUE)) > 0) {
                    out.println("can't be fitted anywhere.");
                }
                else {
                    out.println("can be fitted in:");

                    if (number.compareTo(BigInteger.valueOf(Byte.MIN_VALUE)) >= 0 &&
                        number.compareTo(BigInteger.valueOf(Byte.MAX_VALUE)) <= 0) {
                        out.println("* byte");
                    }

                    if (number.compareTo(BigInteger.valueOf(Short.MIN_VALUE)) >= 0 &&
                        number.compareTo(BigInteger.valueOf(Short.MAX_VALUE)) <= 0) {
                        out.println("* short");
                    }

                    if (number.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) >= 0 &&
                        number.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) <= 0) {
                        out.println("* int");
                    }

                    out.println("* long");
                }
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

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public BigInteger nextBigInteger() throws IOException {
            return new BigInteger(next());
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
