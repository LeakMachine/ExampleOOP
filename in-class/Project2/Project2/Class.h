#pragma once
#include <iostream>
#include <string>
#include <time.h>

class Product {
	std::string code;
	std::string name;
	int price;
	int discount;
	int count;

public:
	Product();
	Product(std::string _code, std::string _name, int _price, int _discount, int _count);

	void showInfo();

	bool operator==(const Product& prod) {
		return (this->code == prod.code);
	};
	friend bool operator!=(const Product& left, const Product& right);
	friend std::ostream& operator<< (std::ostream out, const Product& prod) {
		out << prod.name << " " << prod.price << " " << " " << (int)(prod.price * (100 - prod.discount) / 100.0);
	};

	friend class Store;
};

bool operator!=(const Product& left, const Product& right) {
	//return !(&left == &right);
	return(left.code != right.code);
};

class Store {
	Product* assortment;
	int size;

public:
	Store() {
		// лучше - чтение из файла
		int size = 100;
		assortment = new Product[size];
		for (int i = 0; i < size; i++) {
			assortment[i].code = std::to_string(i);
			assortment[i].name = "Product" + std::to_string(i);
			assortment[i].count = 1 + rand() % 101;
			assortment[i].discount = 1 + rand() % 50;
			assortment[i].price = 200 + rand() % 5801;
		}
	};
	~Store();
};

typedef Product* ProductLink;

class Basket {
	//Product** goods;
	ProductLink* goods;
	int size;
	int count;
	ProductLink last;
	int cur_price;

public:
	Basket() {
		size = 50;
		goods = new ProductLink[size];
		count = 0;
		last = nullptr;
		cur_price = 0.0;
	};
	~Basket() {
		delete[] goods;
	};

	void scan(const Store& _store, std::string _code);
	std::string info();
	void add();
	std::string generateCheck();
	void getPrice();

	void clean() {
		count = 0;
	};
};