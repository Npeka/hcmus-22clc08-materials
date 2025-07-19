package W10;
import java.net.*;

public class URLDemo {
    public static void main(String []args){
        try {
            // URL url = new URL("http://www.hcmus.edu.vn");
            URI  uri = new URI("http://www.hcmus.edu.vn");
            URL url = uri.toURL();
            System.out.println("Protocol: " + url.getProtocol());
            System.out.println("Port: " + url.getPort());
            System.out.println("Host: " + url.getHost());
            System.out.println("File: " + url.getFile());
            System.out.println("Path: " + url.getPath());
            System.out.println("Query: " + url.getQuery());
            System.out.println("Ref: " + url.getRef());
        }
        catch (URISyntaxException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (MalformedURLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }    
}
