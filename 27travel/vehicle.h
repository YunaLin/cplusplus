#include<iostream>
#include<cmath>
using namespace std;


struct City {
    double x, y;          // position of the city
    string name;  // name of city
};

class Vehicle {
  public:
    explicit Vehicle(double _speed) : speed(_speed) {}
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const {
        return speed;
    }
    virtual ~Vehicle() {}
  private:
    double speed;
};


class BicycleStrategy:public Vehicle {
  public:
  explicit BicycleStrategy(double speed_);
  void doTravel(const City& src, const City& dest) {
    double distance = fabs(src.x-dest.x) + fabs(src.y - dest.y);
    double time = distance/this->getSpeed();
    cout << time;
    cout << " hours to Travel from " << src.name << " to " << dest.name
    << " by Bicycle.";
  }
};
BicycleStrategy::BicycleStrategy(double speed_):Vehicle(speed_) {}

class TrainStrategy:public Vehicle {
  public:
  explicit TrainStrategy(double speed_);
  void doTravel(const City& src, const City& dest) {
    double distance = sqrt((src.x - dest.x)*(src.x - dest.x) + (src.y - dest.y)
    *(src.y - dest.y));
    double time = distance/this->getSpeed();
    cout << time;
    cout << " hours to Travel from " << src.name << " to " << dest.name
    << " by Train.";
  }
};
TrainStrategy::TrainStrategy(double speed_):Vehicle(speed_) {}

class AirplaneStrategy:public Vehicle {
  public:
  explicit AirplaneStrategy(double speed_);
  void doTravel(const City& src, const City& dest) {
  double distance = fabs(dest.x - src.x) > fabs(dest.y - src.y)?
  fabs(dest.x - src.x):fabs(dest.y - src.y);
  double time = distance/this->getSpeed();
    cout << time;
    cout << " hours to Travel from " << src.name << " to " << dest.name
    << " by Airplane.";
  }
};
AirplaneStrategy::AirplaneStrategy(double speed_):Vehicle(speed_) {}
