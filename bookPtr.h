#pragma once
#include "book.h"
namespace jingahyun2693303
{
    class bookPtr
    {
        book* bPtr;
    public:
        //생성자
        bookPtr(const book& b = book{"bookTitle",1,10000}):bPtr{new book{b}}
        {
            std::cout << "constructor\n";
        }
        //소멸자
        ~bookPtr()
        {
            std::cout << "~destructor\n";
            delete bPtr;}
        //복사생성자
        bookPtr(const bookPtr& copy)
        {
            std::cout << "copy constructor\n";
            bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
        }
        bookPtr(bookPtr&& move) noexcept
        {
            std::cout << "move constructor\n";
            bPtr = move.bPtr;
            move.bPtr = nullptr;
        }
        //복사=연산자
        bookPtr& operator=(const bookPtr& copy)
        {
            if (this != &copy)
            {
                delete bPtr;
                bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
            }
            return *this;
        }
        bookPtr& operator=(bookPtr&& move) noexcept
        {
            if (this != &move)
            {
                delete bPtr;
                bPtr = move.bPtr ;
                move.bPtr = nullptr;
            }
            return *this;
        }
        void print() const 
        {
            if (bPtr)
                std::cout << *bPtr;
            else 
                std::cout << "no data (nullptr)\n";
            
        }
    };
}