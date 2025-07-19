package W10;
import java.io.*;
import java.net.*;

public class TCPServerDemo01 {
    public static void main(String []args){
        int serverPort = 1234;
        try (ServerSocket server = new ServerSocket(serverPort)) {
            while(true){
                System.out.println("Waiting for client...");
                Socket client = server.accept();
                System.out.println("A client is connected");
                InputStream in = client.getInputStream();
                OutputStream out = client.getOutputStream();
                BufferedReader reader = new BufferedReader(new InputStreamReader(in));
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(out));

                while(true){
                    // Read a string from client
                    String s = reader.readLine();
                    System.out.println("Client sent: " + s);
                    String s2 = s.toUpperCase();
                    writer.write(s2 + "\n");
                    writer.flush(); 
                    
                    if(s.compareTo("exit") == 0){
                        break;
                    }
                }

                System.out.println("Client disconnected");

                
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }    
}
