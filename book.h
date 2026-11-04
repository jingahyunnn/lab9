#pragma once
#include <iostream>
#include <string>
namespace jingahyun2693303
{
class book
{
    std::string title;
    int id;    
    int price; 
    void testID()//id: 1~1000
    {
        if(id < 1 || id > 1000)
        {
            std::cout << "Invalid book id\n";
            std::exit(1);
        }
    }
    void testPrice()//price: 0~50000 won
    {
        if (price < 0 || price > 50000)
        {
            std::cout << "Invalid book price\n";
            std::exit(1);
        }
    }
public:
    book(const std::string& t = "no title yet", int d = 1, int p = 0)
    :title{t}, id{d}, price{p}
    {
        testID(); testPrice();
    }    
    void input()
    {
        std::cout << "Enter book title: ";
        std::getline(std::cin >> std::ws, title);//std::cin >> title;
        std::cout << "Enter book id: ";
        std::cin >> id; testID();
        std::cout << "Enter book price: ";
        std::cin >> price; testPrice();
    }
    friend std::istream& operator>>(std::istream& is, book& b)
    {
        std::cout << "Enter book title: ";
        std::getline(is >> std::ws, b.title);
        std::cout << "Enter book id: ";
        is >> b.id; b.testID();
        std::cout << "Enter book price: ";
        is >> b.price; b.testPrice();         
        return is;
    }        
    void setID(int d){id = d; testID();}
    void setPrice(int p){price = p; testPrice();}
    void setTitle(const std::string& t){title = t;}
    void print() const
    {
        std::cout << title << "(" << id << "): " << price << " won\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const book& b)
    {
        os << b.title << ", " << b.id << ", " << b.price << " won\n";
        return os;
    }
    const std::string& getTitle() const {return title;}
    int getID() const {return id;}
    int getPrice() const {return price;}
    

    // 1-4. 전위증가연산자, 후위증가연산자를 this를 이용해서 구현하세요. 리턴형식도 참조가 필요하면 참조로 리턴하게 변경하세요.
    book operator++()
        {
            ++price;
            return *this;
        }
    book operator++(int)
        {
            book temp{*this};
            price++;
            return temp;
        }


    // 1-5. 복합할당연산자 +=를 구현하세요. 매개변수는 int, price에 매개변수를 더해줍니다. this를 이용하세요.
    book& operator+=(int p)
    {
        price += p;
        return *this;
    }


    friend bool operator==(const book& b1, const book& b2)
    {
        return b1.id == b2.id && b1.price == b2.price;
    }
    friend int operator+(const book& b1, const book& b2)
    {
        return b1.price + b2.price;
    }
    price += p;
            return *this;
};
}