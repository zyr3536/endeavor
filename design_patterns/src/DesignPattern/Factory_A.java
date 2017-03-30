package DesignPattern;

public class Factory_A extends AbstractFactory{
	public Product_A1 createProduct1(){
		return new Product_A1();
	}
	public Product_A2 createProduct2(){
		return new Product_A2();
	}
}
