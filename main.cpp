#include "bookPtr.h"
#include <memory>

int main()
{
    using namespace jingahyun2693303;

    bookPtr bp1;
    bookPtr bp2{bp1;//copy constructor
    bookPtr bp3{std::move(p2)};//move construtor
    bp2 = std::move(bp3);
    bp3 = bp2;

    bookPtr* bp{new bookPtr};
    //delete bp;

    //클래스1Ptr형을 가리키는 unique_ptr 객체1을 선언
    std::unique_ptr<bookPtr> up1;

    //클래스1Ptr형을 가리키는 unique_ptr 객체2를 선언하면서 원하는 값으로 초기화 (make_unique 사용)
    auto up2{std::make_unique<bookPtr>(book{"title", 1, 10000})};

    //unique_ptr 객체1에 unique_ptr 객체2를 이동, unique_ptr 객체1이 가리키는 값을 출력
    up1 = std::move(up2);
    up1->print();

    //클래스1Ptr형을 가리키는 shared_ptr 객체1을 선언하면서, 원하는 값으로 초기화
    auto sp1{std::shared_ptr<bookPtr>(book{"shared", 2, 20000})};
    //클래스1Ptr형을 가리키는 shared_ptr 객체2를 선언하면서 shared_ptr 객체1로 초기화
    std::shared_ptr<bookPtr> sp2{sp1};

    //shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력
    //shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    //클래스1Ptr형을 가리키는 weak_ptr 객체1을 선언하면서 shared_ptr 객체1로 초기화
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    //shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

    //shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

    //shared_ptr 객체1에서 reset 멤버함수를 호출한 후

    //shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

    //shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

    //weak_ptr 객체1에서 expired 멤버함수를 호출하여 expired가 아니면 (메모리가 있으면)
    if (!wp1.expired()) sp1 = wp1.lock();
    //weak_ptr 객체1에서 lock 멤버함수를 호출한 값을 shared_ptr 객체1에 할당 후 

    //shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

    //shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    delete bp;
        return 0;
    }