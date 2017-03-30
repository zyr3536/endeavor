package DesignPattern;

public class FactoryB extends IFactory{

	@Override
	public IProduct create() {
		return new ProductB();
	}

}
