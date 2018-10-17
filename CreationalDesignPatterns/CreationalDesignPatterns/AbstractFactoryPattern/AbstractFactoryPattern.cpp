//
//  AbstractFactoryPattern.cpp
//  CreationalDesignPatterns
//
// Theme selector
#include <iostream>
using std::cout;

class textColor{
public:
    virtual void getTextColor()=0;
    virtual void getGreenTextColor()=0;
};
class backGroundColor{
public:
    virtual void getBackGroundColor()=0;
};
class lightText:public textColor{
public:
    void getTextColor(){
        cout<<"TEXT COLOR is black\n";
    }
    void getGreenTextColor(){
        cout<<"Green text is DARK\n";
    }
};
class darkText:public textColor{
public:
    void getTextColor(){
        cout<<"TEXT COLOR is white\n";
    }
    void getGreenTextColor(){
        cout<<"Green text is light\n";
    }
};
class lightBackGround:public backGroundColor{
public:
    void getBackGroundColor(){
        cout<<"Back Ground color is White\n";
    }
};
class darkBackGround:public backGroundColor{
public:
    void getBackGroundColor(){
        cout<<"Back ground color is black\n";
    }
};
class factory{
    
public:
    virtual textColor* getDefaultText()=0;
    virtual backGroundColor* getDefaultColor()=0;
};
class lighFactory:public factory{
public:
    textColor* getDefaultText(){
        return new lightText;
    }
    backGroundColor* getDefaultColor(){
        return new lightBackGround;
    }
};
class darkFactory:public factory{
public:
    textColor* getDefaultText(){
        return new darkText;
    }
    backGroundColor* getDefaultColor(){
        return new darkBackGround;
    }
};
int main(void){
    int choice;
    cout<<"Choose Theme\n1.LIGHT\n2.DARK\nChoose your option : ";
    std::cin>>choice;
    if(choice < 0 || choice > 2){
        cout<<"Invalid choice...\n";
        return 0;
    }
    factory* fObj;
    if(choice == 2){
        fObj=new darkFactory;
    }else{
        fObj=new lighFactory;
    }
    fObj->getDefaultText()->getTextColor();
    fObj->getDefaultText()->getGreenTextColor();
    fObj->getDefaultColor()->getBackGroundColor();
    
}
