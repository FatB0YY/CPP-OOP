#include <iostream>

//class MyClass {
//    // по умолчанию поля private - нельзя достучаться из вне до поля
//    // наследование private
//};

//struct MyStruct {
//    // по умолчанию поля public - можно достучаться из вне до поля
//    // наследование public
//};


// C
struct DateC {
    int day;
    int month;
    int year;
};

void print(const DateC& date) {
    std::cout << date.year << " : " << date.day << " : " << date.month;
}

void init(DateC* this_) {
    this_->day = 2;
    this_->month = 1;
    this_->year = 1970;
}


// C++ 
struct DateCpp {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    

public:
    // конструктор по умолчанию
    DateCpp() : day(1), month(1), year(1970) {}
    // перегрузка
    DateCpp(unsigned day, unsigned month, unsigned year) : day(day), month(month), year(year) {}

    ~DateCpp() {
        day = 0;
        month = 0;
        year = 0;
    }

    void print() {
        std::cout << year << " : " << day << " : " << month;
    }

    //unsigned int - от 0 до ...
    void setMonth(unsigned int m) {
        if (m > 12) {
            throw std::invalid_argument("incorrect month");
        }
        else {
           month = m;
        }
    }

    unsigned int getMonth() {
        return month;
    }


};

template<typename T>

struct SmartPointer {
    SmartPointer(T* pointer) : m_pointer(pointer){}
    T* get(){return m_pointer}
    ~SmartPointer() { delete m_pointer; }
private:
    T* m_pointer;
};


// будет жить всю нашшу программу
//DateCpp date_cpp{ 2, 4, 1988 };

void func() {
    // начинает жить с того момента,
    // когда исполнение зашло в эту функцию первый раз
    // и до тех пор, пока не закончится программа
    //static DateCpp date_cpp{ 2, 4, 1988 };
    //DateCpp* date = new DateCpp{ 2, 4, 1988 };
    //delete date;

    // RAII
    SmartPointer<DateCpp> ptr{
        new DateCpp{}
    };
}


int main()
{
    DateC date_c = {};
    init(&date_c);

    // проблема инвариант - гарантия что поведение класса не будет нарушено.
    //date_c.day = 56;
    //date_c.month = 23;
    print(date_c);

    DateCpp date_cpp = { 1, 1, 1970 };
    // date_cpp.month = 23; // error semantic
    date_cpp.setMonth(11);
    // std::cout << date_cpp.month << std::endl; // error
    std::cout << date_cpp.getMonth() << std::endl;
    date_cpp.print();

    return 0;
}


/*
    Парадигмы программирования – способ. 
    Например ооп (наиболее популярная), функциональное, структурное, процедурное, логическая, обобщённая итд.

    В чем разница класса и объекта. У нас есть завод по производству автомобилей. 
    Класс это чертеж, того какими с-вами и поведениями будет обладать объекты, те экземпляры. 
    Класс производит объекты.

    Все эти штуки – public, private это инкапсуляция.

    Разницы в производительности нет.

    Как сделать гарантию, что при создании объекта у него будут инициализироваться данные. 
    Нам помогает конструктор. Он вызывается автоматически. То же самое с деструктором.

    Что такое операция new. New выделяет память в хипе, возвращает указатель на выделенную память, вызывает конструкторы.
    Delete вызывает деструктор.


    Плохая практика – вызывать new и delete.
    Нужно делать дополнительные гарантии – smartPointer.
    И так, внутри создаем приватную переменную типа T m_pointer, также конструктор, 
    который принимает указатель на T pointer и проинициализируем ее. Деструктор, 
    который удаляет указатель и метод get для получения этого указателя.
    Теперь мы создали объект в хипе и положили его в конструктор, 
    те захватили его объект какой-то ресурс в конструкторе, а ptr будет уничтожен, 
    когда закончится выполнение этой ф-ции. Эта идиома называет RAII.


    Const объектов. Если наш объект константный, то мы можем вызывать у него ТОЛЬКО константные методы.
    Что такое константный метод – этот тот метод, который никак не модифицирует состояние нашего класса. 
    Что такое состояние класса – это переменные константы внутри нашего класса.
    Но есть обходной путь, если укажем у поля mutable. 
    Mutable – можем менять значения поля внутри константного метода (лучше очень редко использовать, в костылях)
    Const – гарантия модификации.
*/


