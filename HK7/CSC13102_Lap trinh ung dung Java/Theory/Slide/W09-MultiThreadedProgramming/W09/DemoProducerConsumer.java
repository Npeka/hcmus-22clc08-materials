package W09;
import java.util.Random;

public class DemoProducerConsumer {
    public static void main(String[] args) {
        Drop drop = new Drop();
        (new Thread(new Producer(drop))).start();
        (new Thread(new Consumer(drop))).start();
    }
}

class Drop {
    // Message sent from producer to consumer.
    private String message;

    // true if consumer should wait for producer to send message,
    // false if producer should wait for onsumer to retrieve message.
    private boolean empty = true;

    public synchronized String take() {
        // Wait until message is available.
        while (empty) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        // Toggle status.
        empty = true;
        System.out.println("Consumer");
        // Notify producer that status has changed.
        notifyAll();
        return message;
    }

    public synchronized void put(String message) {
        // Wait until message has been retrieved.
        while (!empty) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        // Toggle status.
        empty = false;
        // Store message.
        this.message = message;
        System.out.println("Producer");
        // Notify consumer that status has changed.
        notifyAll();
    }
}

class Producer implements Runnable {
    private Drop drop;

    public Producer(Drop drop) {
        this.drop = drop;
    }

    public void run() {
        String importantInfo[] = {
                "Mares eat oats",
                "Does eat oats",
                "Little lambs eat ivy",
                "A kid will eat ivy too"
        };
        Random random = new Random();

        for (int i = 0; i < importantInfo.length; i++) {
            drop.put(importantInfo[i]);
            try {
//                Thread.sleep(random.nextInt(10000));
                Thread.sleep(10000);
            } catch (InterruptedException e) {}
        }
        drop.put("DONE");
    }
}

class Consumer implements Runnable {
    private Drop drop;

    public Consumer(Drop drop) {
        this.drop = drop;
    }

    public void run() {
        Random random = new Random();
        for (String message = drop.take(); !message.equals("DONE");
             message = drop.take()) {
            System.out.format("MESSAGE RECEIVED: %s%n", message);
            try {
//                Thread.sleep(random.nextInt(1000));
                Thread.sleep(1000);
            } catch (InterruptedException e) {}
        }
    }
}

