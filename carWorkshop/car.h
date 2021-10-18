#include <iostream>
#include <time.h>
using namespace std;

enum serviceTypes
{changeOil = 1, swupdat = 2, hwChange = 3, electIssue = 4};
enum servicePrice
{ };

typedef struct time
{
    int day;
    int month= 0;
    int year= 0;
    int hour = 0;
    int min = 0;
} date_t;




class Customer {
public:
    std::string Name = "No Name";
    Customer() {}
    //Customer(const unsigned int &_c, const std::string &_n);
    ~Customer() {}
    void calculateVisit(int serviceType, int customerID );
    std::string customerAddress;
    int customerTell;

private:
    unsigned int Counter = 0; //visting workshop during last year
protected:
    time_t lastvisit;

};

class Service{
public:
    Service() = delete;
    //Service(const unsigned int &_c, const std::string &_n):Counter(_c),Name(_n){};
    ~Service() = default;
    int calculatCost(int itemNo, int price);
    bool payment(int customerID, int price);
private:
    unsigned int Counter;
    std::string Name;
protected:
    std::string mode;
    int plateNo = 0;


};

class service {
public:
    service() = delete;
    service(const unsigned int &_c, const std::string &_n):Counter(_c),Name(_n){};
    ~service() = default;
    int price;

private:
    unsigned int Counter;
    std::string Name;
protected:
    std::string mode;
    int plateNo = 0;


};



class parts {
public:
    parts() = delete;
    parts(const unsigned int &_c, const std::string &_n):Counter(_c),Name(_n){};
    ~parts() = default;
    unsigned int availableItem;
    std::string Name;
    void bla();
private:
    
    
};

