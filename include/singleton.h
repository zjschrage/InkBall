#pragma once
#include <memory>

template <typename T>
class Singleton {
    public:
        static T& get() {return *single;}
        static void set(std::unique_ptr<T> singleNew) {single = std::move(singleNew);}

    private:
        Singleton() {}
        static std::unique_ptr<T> single;
};

template <typename T>
std::unique_ptr<T> Singleton<T>::single = nullptr;