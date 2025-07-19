package W09;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Task implements Runnable {
    private final int taskId;

    public Task(int taskId) {
        this.taskId = taskId;
    }

    @Override
    public void run() {
        System.out.println("Task " + taskId + " is running on thread: " + Thread.currentThread().getName());
        try {
            Thread.sleep(1000); // Simulate work with a 1-second delay
        } catch (InterruptedException e) {
            System.err.println("Task " + taskId + " was interrupted.");
        }
        System.out.println("Task " + taskId + " completed.");
    }
}

public class DemoExecutorService {
    public static void main(String[] args) {
        // Create a fixed thread pool with 3 threads
        ExecutorService executorService = Executors.newFixedThreadPool(3);

        // Submit 10 tasks to the executor service
        for (int i = 0; i < 10; i++) {
            Task task = new Task(i);
            executorService.submit(task);
        }

        // Shut down the executor service
        executorService.shutdown();
        System.out.println("All tasks submitted.");
    }
}
