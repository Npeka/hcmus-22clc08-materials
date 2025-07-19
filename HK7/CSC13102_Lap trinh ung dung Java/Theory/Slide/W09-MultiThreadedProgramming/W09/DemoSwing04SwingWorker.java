package W09;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
// package test20221123_swing.concurrency;

// Java Program to Illustrate Working of SwingWorker Class
  
// Importing required classes
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.List;
import java.util.concurrent.ExecutionException;
import javax.swing.*;
  
// Main class
// SwingWorkerSample
public class DemoSwing04SwingWorker {
  
    private static JLabel statusLabel;
    private static JFrame mainFrame;
  
    // Method
    public static void swingWorkerSample()
    {
        mainFrame = new JFrame("Swing Worker");
        mainFrame.setSize(400, 400);
        mainFrame.setLayout(new GridLayout(2, 1));
  
        mainFrame.addWindowListener(new WindowAdapter() {
            // Method
            @Override
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }
        });
  
        statusLabel
            = new JLabel("Not Completed", JLabel.CENTER);
        mainFrame.add(statusLabel);
  
        JButton btn = new JButton("Start counter");
        btn.setPreferredSize(new Dimension(5, 5));
  
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                System.out.println(
                    "Button clicked, thread started");
                startThread();
            }
        });
  
        mainFrame.add(btn);
        mainFrame.setVisible(true);
    }
  
    // Method
    private static void startThread()
    {
  
        SwingWorker sw1 = new SwingWorker() {
            // Method
            @Override
            protected String doInBackground()
                throws Exception
            {
  
                // Defining what thread will do here
                for (int i = 100; i >= 0; i--) {
                    Thread.sleep(100);
                    System.out.println("Value in thread : "
                                       + i);
                    publish(i);
                }
  
                String res = "Finished Execution";
                return res;
            }
  
            // Method
            @Override protected void process(List chunks)
            {
                // define what the event dispatch thread
                // will do with the intermediate results
                // received while the thread is executing
                int val = (int) chunks.get(chunks.size() - 1);
  
                statusLabel.setText(String.valueOf(val));
            }
  
            // Method
            @Override protected void done()
            {
                // this method is called when the background
                // thread finishes execution
                try {
                    String statusMsg = (String) get();
                    System.out.println(
                        "Inside done function");
                    statusLabel.setText(statusMsg);
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
                catch (ExecutionException e) {
                    e.printStackTrace();
                }
            }
        };
  
        // Executes the swingworker on worker thread
        sw1.execute();
    }
  
    // Main driver method
    public static void main(String[] args)
    {
        swingWorkerSample();
    }
}