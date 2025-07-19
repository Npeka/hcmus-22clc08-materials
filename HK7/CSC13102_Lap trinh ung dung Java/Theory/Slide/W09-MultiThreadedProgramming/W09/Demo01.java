package W09;

class MyRunnable implements Runnable {
    String thrdName;

    MyRunnable(String name) {
        thrdName = name;
    }

    // Entry point of runnable.
    public void run() {
        System.out.println(thrdName + " starting.");
        try {
            for (int count = 0; count < 10; count++) {
                Thread.sleep(400);
                System.out.println("In " + thrdName +
                        ", count is " + count);
            }
        } catch (InterruptedException exc) {
            System.out.println(thrdName + " interrupted.");
        }
        System.out.println(thrdName + " terminating.");
    }
}

public class Demo01 {
    public static void main(String args[]) {
        System.out.println("Main thread starting.");
        // First, construct a MyThread object.
        MyRunnable mr = new MyRunnable("Child #1");
        // Next, construct a thread from that object.
        Thread newThrd = new Thread(mr);
        // Finally, start execution of the thread.
        newThrd.start();
        for (int i = 0; i < 50; i++) {
            System.out.print(".");
            try {
                Thread.sleep(100);
            } catch (InterruptedException exc) {
                System.out.println("Main thread interrupted.");
            }
        }
        System.out.println("Main thread ending.");
    }
}
