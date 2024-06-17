import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(reader.readLine().trim());
        String s1 = reader.readLine();
        String s2 = reader.readLine();

        int beg = 0, end = 0;

        // Find the length of the matching prefix
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == s2.charAt(i))
                beg++;
            else
                break;
        }

        // Find the length of the matching suffix
        for (int i = n - 1; i >= 0; i--) {
            if (s1.charAt(i + 1) == s2.charAt(i))
                end++;
            else
                break;
        }

        // Check if it's possible to make s1 identical to s2 by deleting one character
        if (beg + end + 1 < n) {
            writer.write("0\n");
        } else {
            int startPos = Math.min(beg + 1, n + 1);
            int endPos = Math.max(n - end + 1, 1);

            // Calculate number of deletions and print positions
            writer.write((startPos - endPos + 1) + "\n");
            for (int i = 1; i <= n + 1; i++) {
                if (i - 1 <= beg && n + 1 - i <= end) {
                    writer.write(i + " ");
                }
            }
            writer.write("\n");
        }

        writer.flush();
        reader.close();
        writer.close();
    }
}