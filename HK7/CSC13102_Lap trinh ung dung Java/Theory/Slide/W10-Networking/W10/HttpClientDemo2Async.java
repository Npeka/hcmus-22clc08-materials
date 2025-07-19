package W10;

import java.net.URI;
import java.net.http.*;
import java.io.InputStream;
import java.util.*;

public class HttpClientDemo2Async {
    public static void main(String[] args) {
        // Obtain a client that uses the default settings.
        HttpClient myHC = HttpClient.newHttpClient();

        // Create a request
        HttpRequest myReq = HttpRequest.newBuilder(URI.create("http://www.google.com/")).build();

        // Send the request asynchronously and get the response.
        myHC.sendAsync(myReq, HttpResponse.BodyHandlers.ofInputStream())
            .thenAccept(myResp -> {
                // Handle the response
                try {
                    // Display response code and request method.
                    System.out.println("Response code is " + myResp.statusCode());
                    System.out.println("Request method is " + myReq.method());

                    // Get headers from the response.
                    HttpHeaders hdrs = myResp.headers();
                    // Get a map of the headers.
                    Map<String, List<String>> hdrMap = hdrs.map();
                    Set<String> hdrField = hdrMap.keySet();

                    System.out.println("\nHere is the header");
                    // Display all header keys and values
                    for (String k : hdrField) {
                        System.out.println("Key: " + k + " Value: " + hdrMap.get(k));
                    }

                    // Display the body
                    System.out.println("\nHere is the body: ");
                    InputStream input = myResp.body();
                    int c;
                    // Read and display the entire body.
                    while ((c = input.read()) != -1) {
                        System.out.print((char) c);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            })
            .exceptionally(e -> {
                // Handle exceptions
                e.printStackTrace();
                return null;
            });

        // To prevent the main thread from exiting immediately
        try {
            Thread.sleep(5000); // Wait for async operations to complete
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
