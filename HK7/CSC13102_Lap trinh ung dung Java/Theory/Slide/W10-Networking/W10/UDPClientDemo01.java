package W10;
import java.net.*;
import java.io.*;
import java.util.*;

public class UDPClientDemo01 {
    public static void main(String []args){
        int serverPort = 1234;
        int clientPort = 6789;
        try (DatagramSocket socket = new DatagramSocket(clientPort)) {
            byte[] buffer = new byte[1024];
            while(true){
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                socket.receive(packet);
                String s = new String(packet.getData(), 0, packet.getLength());
                System.out.println("Server message: " + s);
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}
