#include <iostream>
#include <vector>
#include <string>

// Simulated Device Interface
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getName() const = 0;
};

// Simulated Light Device
class Light : public Device {
public:
    Light(const std::string& name) : name(name), status(false) {}

    void turnOn() override {
        status = true;
        std::cout << name << " light turned ON.\n";
    }

    void turnOff() override {
        status = false;
        std::cout << name << " light turned OFF.\n";
    }

    std::string getName() const override {
        return name;
    }

private:
    std::string name;
    bool status;
};

// Simulated Thermostat Device
class Thermostat : public Device {
public:
    Thermostat(const std::string& name) : name(name), temperature(22.0) {}

    void turnOn() override {
        std::cout << name << " thermostat turned ON.\n";
    }

    void turnOff() override {
        std::cout << name << " thermostat turned OFF.\n";
    }

    void setTemperature(double temp) {
        temperature = temp;
        std::cout << name << " thermostat set to " << temperature << " degrees Celsius.\n";
    }

    std::string getName() const override {
        return name;
    }

private:
    std::string name;
    double temperature;
};

// Smart Home Controller
class SmartHome {
public:
    void addDevice(Device* device) {
        devices.push_back(device);
    }

    void operateDevices() {
        for (const auto& device : devices) {
            device->turnOn();
            device->turnOff();
        }
    }

    Device* findDeviceByName(const std::string& name) const {
        for (const auto& device : devices) {
            if (device->getName() == name) {
                return device;
            }
        }
        return nullptr;
    }

private:
    std::vector<Device*> devices;
};

int main() {
    // Simulated Devices
    Light livingRoomLight("Living Room");
    Light kitchenLight("Kitchen");
    Thermostat livingRoomThermostat("Living Room");

    // Smart Home Initialization
    SmartHome mySmartHome;
    mySmartHome.addDevice(&livingRoomLight);
    mySmartHome.addDevice(&kitchenLight);
    mySmartHome.addDevice(&livingRoomThermostat);

    // Operate Devices
    mySmartHome.operateDevices();

    // Find and Operate a Specific Device
    Device* foundDevice = mySmartHome.findDeviceByName("Kitchen");
    if (foundDevice) {
        foundDevice->turnOn();
    } else {
        std::cout << "Device not found.\n";
    }

    return 0;
}

			