package DesignPattern;

public class SimpleFactory {
	public static IProduct create(String productName){
		switch(productName){
		case "A":
			return new ProductA();
		case "B":
			return new ProductB();
		default:
			return null;	
		}
	}
}
