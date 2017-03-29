package DesignPattern;
//饿汉模式
public class Singleton {
	private static final Singleton instance = new Singleton();
	private Singleton(){}
	public static Singleton getInstance(){
		return instance;
	}
	
//懒汉模式
//	private class Singleton1{
//		private static Singleton1 instance;
//		private Singleton1(){}
//		public static synchronized Singleton1 getInstance(){
//			if(instance == null)
//				instance = new Singleton1();
//			return instance;
//		}
//	}
}
