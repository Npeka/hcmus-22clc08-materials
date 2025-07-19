package W10;
import java.io.*;
import java.net.*;
import java.util.*;

public class TCPClientDemo02 {
    public static void main(String []args){
        String serverIP = "localhost";
        int serverPort = 1234;
        try (Socket socket = new Socket(serverIP, serverPort)) {
            Scanner scanner = new Scanner(System.in);

            InputStream in = socket.getInputStream();
            OutputStream out = socket.getOutputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(in));
            ObjectOutputStream oos = new ObjectOutputStream(out);

            while(true){
                System.out.print("Enter an array of integers: ");
                String s = scanner.nextLine();
                String[] arr = s.split(" ");
                List<Integer> list1 = new ArrayList<>();
                for (String str : arr) {
                    list1.add(Integer.parseInt(str));
                }
                int[] array = list1.stream().mapToInt(i -> i).toArray();
                oos.writeObject(array);
                oos.flush();

                String s2 = reader.readLine();
                int sum = Integer.parseInt(s2);
                System.out.println("Server message: " + sum);

                if(list1.get(0) == -1){
                    break;
                }
            }

        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
