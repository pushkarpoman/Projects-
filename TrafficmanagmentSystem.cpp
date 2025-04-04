#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

enum TrafficLightColor {
    RED,
    GREEN,
    YELLOW
};

class TrafficLight {
private:
    TrafficLightColor color;
    mutex mtx;

public:
    TrafficLight() : color(RED) {}

    void setLight(TrafficLightColor newColor) {
        lock_guard<mutex> lock(mtx);
        color = newColor;
    }

    TrafficLightColor getLight() {
        lock_guard<mutex> lock(mtx);
        return color;
    }
};

class Car {
public:
    void drive() {
        cout << "Car is driving." << endl;
    }

    void stop() {
        cout << "Car has stopped." << endl;
    }
};

class TrafficManager {
private:
    TrafficLight trafficLight;
    vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void simulateTraffic() {
        for (int i = 0; i < 10; ++i) {
            this_thread::sleep_for(chrono::seconds(1));

            TrafficLightColor currentColor = trafficLight.getLight();
            if (currentColor == RED) {
                cout << "Traffic Light: RED" << endl;
                for (auto& car : cars) {
                    car.stop();
                }
                trafficLight.setLight(GREEN);
            } else if (currentColor == GREEN) {
                cout << "Traffic Light: GREEN" << endl;
                for (auto& car : cars) {
                    car.drive();
                }
                trafficLight.setLight(YELLOW);
            } else if (currentColor == YELLOW) {
                cout << "Traffic Light: YELLOW" << endl;
                // Yellow duration for caution
                this_thread::sleep_for(chrono::seconds(1));
                trafficLight.setLight(RED);
            }
        }
    }
};

int main() {
    Car car1, car2;
    
    TrafficManager trafficManager;
    trafficManager.addCar(car1);
    trafficManager.addCar(car2);

    thread trafficSimulation(&TrafficManager::simulateTraffic, &trafficManager);
    trafficSimulation.join();

    return 0;

    
}

			