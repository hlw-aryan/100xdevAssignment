import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class UsernameRegistration {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        Map<String, Integer> usernameMap = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            String username = scanner.nextLine();

            if (!usernameMap.containsKey(username)) {
                // Username not found, insert it with count 0
                usernameMap.put(username, 0);
                System.out.println("OK");
            } else {
                // Username found, increment count and suggest new username
                int count = usernameMap.get(username) + 1;
                usernameMap.put(username, count);
                System.out.println(username + count);
            }
        }

        scanner.close();
    }
}
