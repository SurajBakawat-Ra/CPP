#include <functional>
#include <iostream>

class D
{
    public:
        void DFunc(std::function<void()> callback)
        {
            _callback = callback;

            if(true)
                DExecuteCallBack();

        }

        std::function<void()> _callback;

        void DExecuteCallBack()
        {
            if(_callback != nullptr)
                _callback();
            else
                std::cout<<"callback is null"<<std::endl;
        }
};

class C
{
    public:
        void CFunc(std::function<void()> callback)
        {
            D d;
            d.DFunc(callback);
        }
};

class B
{
    public:
        void BFunc(std::function<void()> callback)
        {
            C c;
            c.CFunc(callback);
        }
};

class A
{
    public:
        void AFunc(std::function<void()> callback)
        {
            B b;
            b.BFunc(callback);
        }

        void AHello()
        {
            std::cout<<"A Hello"<<std::endl;
        }
};

int main()
{
    A a;
    B b;

    a.AFunc([&]()
    {
        std::cout<<"A callback"<<std::endl;
    });

    b.BFunc(std::bind(&A::AHello, &a));
}

