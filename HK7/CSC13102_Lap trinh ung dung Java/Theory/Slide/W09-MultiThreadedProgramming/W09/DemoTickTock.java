package W09;

class TickTock {
    String state; // contains the state of the clock

    synchronized void tick(boolean running) {
        if (!running) {
            state = "ticked";
            notify();
            return;
        }
        System.out.print("Tick ");
        state = "ticked";
        notify();
        try {
            while (!state.equals("tocked"))
                wait();
            // Thread.sleep(1000);
            // wait();
        } catch (InterruptedException exc) {
            System.out.println("Thread interrupted.");
        }
    }

    synchronized void tock(boolean running) {
        if (!running) {
            state = "tocked";
            notify();
            return;
        }
        System.out.println("Tock");
        state = "tocked";
        notify();
        try {
            while (!state.equals("ticked"))
                wait();
            // Thread.sleep(1000);
            // wait();
        } catch (InterruptedException exc) {
            System.out.println("Thread interrupted.");
        }
    }
}

class MyThread6 implements Runnable {
    Thread thrd;
    TickTock ttOb;

    MyThread6(String name, TickTock tt) {
        thrd = new Thread(this, name);
        ttOb = tt;
        thrd.start(); // start the thread
    }

    public void run() {
        if (thrd.getName().compareTo("Tick") == 0) {
            for (int i = 0; i < 5; i++)
                ttOb.tick(true);
            ttOb.tick(false);
        } else {
            for (int i = 0; i < 5; i++)
                ttOb.tock(true);
            ttOb.tock(false);
        }
    }
}

public class DemoTickTock {
    public static void main(String args[]) {
        TickTock tt = new TickTock();
        MyThread6 mt1 = new MyThread6("Tick", tt);
        MyThread6 mt2 = new MyThread6("Tock", tt);

        try {
            mt1.thrd.join();
            mt2.thrd.join();
        } catch (InterruptedException exc) {
            System.out.println("Main thread interrupted.");
        }
    }
}
