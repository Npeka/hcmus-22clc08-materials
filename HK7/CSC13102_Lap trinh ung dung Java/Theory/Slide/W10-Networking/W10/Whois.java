package W10;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.*;
public class Whois {
    public static void main(String []args){
        
        try {
            Socket s = new Socket("whois.internic.net", 43);
            InputStream in = s.getInputStream();
            OutputStream out = s.getOutputStream();
            String domain = "www.hcmus.edu.vn";
            byte[] buffer = domain.getBytes();
            out.write(buffer);
            int c;
            while((c = in.read()) != -1){
                System.out.print((char)c);
            }
            s.close();
        } 
        catch (SocketException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
    }
}
