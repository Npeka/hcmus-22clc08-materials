package W09; 

class DemoDaemonThread {
    public static void main(String[] args) {
        // Create a user thread
        Thread userThread = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                System.out.println("User Thread: Task " + i);
                try {
                    Thread.sleep(1000); // Simulate work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("User Thread: Finished!");
        });

        // Create a daemon thread
        Thread daemonThread = new Thread(() -> {
            while (true) {
                System.out.println("Daemon Thread: Background task running...");
                try {
                    Thread.sleep(500); // Simulate work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        // Set daemon thread property
        daemonThread.setDaemon(true);

        // Start both threads
        daemonThread.start();
        userThread.start();

        try {
            userThread.join();
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }


        System.out.println("Main Thread: Finished!");
    }
}
