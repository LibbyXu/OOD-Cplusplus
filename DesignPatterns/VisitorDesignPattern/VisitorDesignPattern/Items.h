//
//  Items.h
//  VisitorDesignPattern
//
//  Created by Lihua Xu on 5/14/21.
//

#ifndef Items_h
#define Items_h
class items{
public:
    items(double item):price(item){};
    void setPrice(double newPrice){
        price=newPrice;
    };
    double getPrice(){
        return price;
    };
    virtual double accept(Visitor *visitor)=0;
protected:
    double price;
};
#endif /* Items_h */
