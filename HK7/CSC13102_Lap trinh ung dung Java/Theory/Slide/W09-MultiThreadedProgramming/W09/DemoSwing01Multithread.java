package W09;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


// Java Program to Illustrate Working of SwingWorker Class
  
// Importing required classes
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
  
// Main class
public class DemoSwing01Multithread {
  
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
                for (int i = 100; i >= 0; i--) {
                    statusLabel.setText(String.valueOf(i));
                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(DemoSwing01Multithread.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
        });
  
        mainFrame.add(btn);
        mainFrame.setVisible(true);
    }
  
    // Main driver method
    public static void main(String[] args)
    {
        swingWorkerSample();
    }
}