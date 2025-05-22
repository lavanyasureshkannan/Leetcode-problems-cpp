#include <iostream>
#include <memory>
using namespace std;

class Passenger
{
    public:
    string Name;
    Passenger(const string& m_name) : Name(m_name) {}
};

class Flight
{
    public:
    string origin;
    string destination;
    double base_fare;

    Flight(const string& m_origin, const string& m_destination, double m_base_fare) 
    : origin(m_origin), destination(m_destination), base_fare(m_base_fare) {}
};

class Seat_class
{
    public:
    virtual double calculate_fare(double base_fare) const = 0;
    virtual ~Seat_class() = default;
};

class Economy : public Seat_class
{
    public:
    double calculate_fare(double base_fare) const
    {
        return base_fare;
    }
};

class Business : public Seat_class
{
    public:
    double calculate_fare(double base_fare) const
    {
        return (1.5 * base_fare);
    }
};

class Reservation
{
    public:
    Passenger _passenger;
    Flight _flight;
    shared_ptr<Seat_class> _seat_class_ptr;
    double amount;

    Reservation(const Passenger& p, const Flight& f, shared_ptr<Seat_class> scp)
    : _passenger(p), _flight(f), _seat_class_ptr(move(scp))
    {
        amount = _seat_class_ptr->calculate_fare(_flight.base_fare);
    }
};

class reservation_factory
{
    public:

    static shared_ptr<Reservation> create_reservation(const Passenger& p, const Flight& f, const string& class_name)
    {
        shared_ptr<Seat_class> _seat_class;
        if(class_name == "economy")
        {
            _seat_class =  make_shared<Economy>();
        }
        else if(class_name == "business")
        {
            _seat_class = make_shared<Business>();
        }
        else 
        {
            return nullptr;
        }
        return make_shared<Reservation>(p, f, _seat_class);
    }
};

int main()
{
    Passenger p1("alice");
    Flight f1("LA", "SF", 100.0);

    Passenger p2("alice");
    Flight f2("LA", "SF", 100.0);

    auto reservation1 = reservation_factory::create_reservation(p1,f1,"economy");
    cout << reservation1->amount << endl;

    auto reservation2 = reservation_factory::create_reservation(p2,f2,"business");
    cout << reservation2->amount << endl;


    return 0;
}