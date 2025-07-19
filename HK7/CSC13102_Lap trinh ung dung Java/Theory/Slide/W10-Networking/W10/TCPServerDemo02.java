package W10;

import java.io.*;
import java.net.*;

public class TCPServerDemo02 {
    public static void main(String[] args) {
        int serverPort = 1234;
        try (ServerSocket server = new ServerSocket(serverPort)) {
            while (true) {
                System.out.println("Waiting for client...");
                Socket client = server.accept();
                System.out.println("A client is connected");
                InputStream in = client.getInputStream();
                OutputStream out = client.getOutputStream();
                ObjectInputStream ois = new ObjectInputStream(in);
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(out));

                while (true) {
                    int[] array = (int[]) ois.readObject();
                    String s = "";
                    for (int i = 0; i < array.length; i++) {
                        s += array[i] + " ";
                    }
                    System.out.println("Client sent: " + s);

                    int sum = 0;
                    for (int i = 0; i < array.length; i++) {
                        sum += array[i];
                    }
                    writer.write(sum + "\n");
                    writer.flush();

                    if (array[0] == -1) {
                        break;
                    }
                }
                System.out.println("Client disconnected");
            }
        } catch (ClassNotFoundException | IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
