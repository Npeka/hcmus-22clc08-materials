package W10;
import java.net.*;

public class InetAddressTest{
    public static void main(String []args){
        try {
            InetAddress addr1 = InetAddress.getLocalHost();
            System.out.println("Local Host:" + addr1);

            InetAddress adrr2 = InetAddress.getByName("www.fit.hcmus.edu.vn");
            System.out.println("FIT:" + adrr2);

            InetAddress[] addr3 = InetAddress.getAllByName("www.hcmus.edu.vn");
            for(int i = 0; i < addr3.length; i++){
                System.out.println("HCMUS:" + addr3[i]);
            }
        } catch (UnknownHostException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }        
    }
}