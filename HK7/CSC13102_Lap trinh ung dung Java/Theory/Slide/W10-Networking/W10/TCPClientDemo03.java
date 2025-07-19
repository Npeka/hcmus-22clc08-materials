package W10;
import java.io.*;
import java.net.*;
import java.util.*;

public class TCPClientDemo03 {
    public static void main(String []args){
        String serverIP = "localhost";
        int serverPort = 1234;
        try (Socket socket = new Socket(serverIP, serverPort)) {
            Scanner scanner = new Scanner(System.in);

            InputStream in = socket.getInputStream();
            OutputStream out = socket.getOutputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(in));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(out));

            while(true){
                System.out.print("Enter a string: ");
                String s = scanner.nextLine();
                writer.write(s + "\n");
                writer.flush();

                String s2 = reader.readLine();
                System.out.println("Server message: " + s2);

                if(s.compareTo("exit") == 0){
                    break;
                }
            }

        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }    
}
