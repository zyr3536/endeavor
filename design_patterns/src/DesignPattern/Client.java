package DesignPattern;

public class Client {
	public static void main(String[] args) {
		/*简单工厂
		IProduct ProductA  = SimpleFactory.create("A");
		IProduct ProductB = SimpleFactory.create("B");
		ProductA.showName();
		ProductB.showName();*/
		/*工厂方法	
		FactoryA fa = new FactoryA();
		FactoryB fb = new FactoryB();
		IProduct ProductA = fa.create();
		IProduct ProductB = fb.create();
		ProductA.showName();
		ProductB.showName();*/
		
		/*抽象工厂*/
		AbstractFactory fa = new Factory_A();
		AbstractFactory fb = new Factory_B();
		AbstractProduct_1 a = fa.createProduct1();
		AbstractProduct_2 b = fb.createProduct2();
		a.showName();
		b.showName();
	}
}
