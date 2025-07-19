package W09;

public class DemoDaemonThreadSupportingThread {
    public static void main(String[] args) {
        // Shared variable to indicate the progress of the user thread
        ProgressTracker progressTracker = new ProgressTracker();

        // Create the user thread
        Thread userThread = new Thread(() -> {
            System.out.println("User Thread: Starting main task...");
            for (int i = 1; i <= 10; i++) {
                try {
                    Thread.sleep(1000); // Simulate task progress
                } catch (InterruptedException e) {
                    System.out.println("User Thread: Interrupted!");
                }
                progressTracker.setProgress(i * 10); // Update progress (e.g., 10%, 20%)
                System.out.println("User Thread: Completed " + i * 10 + "%");
            }
            System.out.println("User Thread: Task completed!");
        });

        // Create the daemon thread for monitoring and support
        Thread monitoringDaemon = new Thread(() -> {
            boolean is100 = false;
            while (true) {
                if(is100){
                    continue;
                }
                System.out.println("Monitoring Daemon: User thread progress = "
                        + progressTracker.getProgress() + "%");
                if (progressTracker.getProgress() == 100) {
                    System.out.println("Monitoring Daemon: User thread completed its task.");
                    is100 = true;
                }
                try {
                    Thread.sleep(500); // Check progress every 500 ms
                } catch (InterruptedException e) {
                    System.out.println("Monitoring Daemon: Interrupted!");
                }
            }
        });

        // Set the monitoring thread as a daemon
        monitoringDaemon.setDaemon(true);

        // Start both threads
        monitoringDaemon.start();
        userThread.start();
    }
}

// Shared resource to track progress
class ProgressTracker {
    private int progress;

    public synchronized int getProgress() {
        return progress;
    }

    public synchronized void setProgress(int progress) {
        this.progress = progress;
    }
}
