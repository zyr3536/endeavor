package multiThread;

public class SimplePriorities implements Runnable{
	private int countDown = 5;
	private volatile double d;
	private int priority;
	public SimplePriorities(int priority){
		this.priority = priority;
	}
	public String toString(){
		return Thread.currentThread() + ": " + countDown;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		Thread.currentThread().setPriority(priority);
		while(true){
			for(int i = 1;i < 1000000;++i){
				d += (Math.PI + Math.E) / (double)i;
			if(i % 1000 == 0)
				Thread.yield();
			}
		System.out.println(this);
		if(--countDown == 0)
			return;
		}
	}
	

}
