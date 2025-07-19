package W10;
import java.net.*;
import java.util.concurrent.*;
import java.io.*;

public class TCPServerDemo03 {
    public static void main(String []args){
        int  serverPort = 1234;
        try (ServerSocket server = new ServerSocket(serverPort)) {
            ExecutorService pool = Executors.newFixedThreadPool(2);
            while(true){
                System.out.println("Waiting for client...");
                Socket client = server.accept();
                System.out.println("A client is connected");

                // RunnableOfServerDemo03 r = new RunnableOfServerDemo03(client);
                // Thread clientThread = new Thread(r);
                // clientThread.start();

                RunnableOfServerDemo03 r = new RunnableOfServerDemo03(client);
                pool.submit(r);
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}

class RunnableOfServerDemo03 implements Runnable{
    private Socket client;
    public RunnableOfServerDemo03(Socket client){
        this.client = client;
    }

    @Override
    public void run() {
        try {
            InputStream in = client.getInputStream();
            OutputStream out = client.getOutputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(in));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(out));

            while (true) {
                String s = reader.readLine();
                System.out.println("Client sent: " + s);

                writer.write(s.toUpperCase() + "\n");
                writer.flush();

                if (s.equals("exit")) {
                    break;
                }
            }
            System.out.println("Client disconnected");
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}