#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Toy{
protected:
	string name;
	float price;
public:	
	virtual ~Toy(){}
	virtual void prepareParts()=0;
	virtual void combineParts()=0;
	virtual void assembleParts()=0;
	virtual void applyLabel()=0;
	virtual void showProduct()=0;
};
class Car:public Toy{
public:
	void prepareParts(){cout<<"preparing car parts...\n";}
	void combineParts(){cout<<"combining car parts...\n";}
	void assembleParts(){cout<<"assembling car parts...\n";}
	void applyLabel(){cout<<"applying car label...\n"; name="Tesla"; price=20;}
	void showProduct(){cout<<name<<" "<<price<<endl;}
};
class Bike:public Toy{
public:
	void prepareParts(){cout<<"preparing bike parts...\n";}
	void combineParts(){cout<<"combining bike parts...\n";}
	void assembleParts(){cout<<"assembling bike parts...\n";}
	void applyLabel(){cout<<"applying bike label...\n"; name="Royal Enfield"; price=10;}
	void showProduct(){cout<<name<<" "<<price<<endl;}
};
class Plane:public Toy{
public:
	void prepareParts(){cout<<"preparing plane parts...\n";}
	void combineParts(){cout<<"combining plane parts...\n";}
	void assembleParts(){cout<<"assembling plane parts...\n";}
	void applyLabel(){cout<<"applying plane label...\n"; name="Jet Airways"; price=100;}
	void showProduct(){cout<<name<<" "<<price<<endl;}
};
