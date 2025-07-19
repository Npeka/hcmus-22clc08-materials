package W10;
import java.net.*;
import java.io.*;
import java.util.*;

public class UDPServerDemo01 {
    public static void main(String []args){
        int serverPort = 1234;
        int clientPort = 6789;

        Scanner scanner = new Scanner(System.in);
        String s;
        try (DatagramSocket socket = new DatagramSocket(serverPort)) {
            while(true){
                System.out.print("Enter a string: ");
                s = scanner.nextLine();
                if(s.compareTo("exit") == 0){
                    socket.close();
                    break;
                }
                byte[] buffer = s.getBytes();
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length, 
                        InetAddress.getLocalHost(), clientPort);
                socket.send(packet);
            }
        } catch (SocketException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (UnknownHostException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
