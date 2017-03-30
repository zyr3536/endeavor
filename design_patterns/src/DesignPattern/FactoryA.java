package DesignPattern;

public class FactoryA extends IFactory{

	@Override
	public IProduct create() {
		return new ProductA();
	}

}
