package multiThread;

import java.util.concurrent.Callable;
import java.util.concurrent.TimeUnit;

public class TaskWithResult implements Callable<String> {
	private int id;
	public TaskWithResult(int id){
		this.id = id;
	}
	@Override
	public String call() throws Exception {
		// TODO Auto-generated method stub
		TimeUnit.MILLISECONDS.sleep(100);
		return "result of TaskWithResult " + id;
	}

}
