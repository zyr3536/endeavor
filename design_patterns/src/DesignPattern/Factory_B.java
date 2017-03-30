package DesignPattern;

public class Factory_B extends AbstractFactory{
	public Product_B1 createProduct1(){
		return new Product_B1();
	}
	public Product_B2 createProduct2(){
		return new Product_B2();
	}
}
