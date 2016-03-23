import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    private static int B;
    private static int H;
    private static boolean flag;

    static {
        InputReader in  = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        try {
            B = in.nextInt();
            H = in.nextInt();
        }
        catch (IOException exception ) {
        }

        if (B > 0 && H > 0) {
            flag = true;
        }
        else {
            out.println("java.lang.Exception: Breadth and height must be positive");
            out.flush();
        }
    }

    public static void main(String[] args) {
        if(flag) {
            System.out.print(B * H);
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

