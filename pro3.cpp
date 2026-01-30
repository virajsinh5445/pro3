#include <iostream>
#include <cstring>
using namespace std;


class Vehicle {
protected:
    int id;
    char maker[30];
    char model[30];
    int year;

    static int totalVehicles;

public:
    Vehicle() {
        id = 0;
        strcpy(maker, "");
        strcpy(model, "");
        year = 0;
        totalVehicles++;
    }

    ~Vehicle() {
        totalVehicles--;
    }

    void setData() {
        cout << "Enter Vehicle ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Manufacturer: ";
        cin.getline(maker, 30);

        cout << "Enter Model: ";
        cin.getline(model, 30);

        cout << "Enter Year: ";
        cin >> year;
    }

    void showData() {
        cout << "ID: " << id << endl;
        cout << "Manufacturer: " << maker << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    int getId() {
        return id;
    }

    static int getTotal() {
        return totalVehicles;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
protected:
    char fuel[20];

public:
    void setCar() {
        setData();
        cin.ignore();
        cout << "Enter Fuel Type: ";
        cin.getline(fuel, 20);
    }

    void showCar() {
        showData();
        cout << "Fuel Type: " << fuel << endl;
    }
};

class ElectricCar : public Car {
protected:
    int battery;

public:
    void setElectric() {
        setCar();
        cout << "Enter Battery Capacity: ";
        cin >> battery;
    }

    void showElectric() {
        showCar();
        cout << "Battery: " << battery << " kWh" << endl;
    }
};

class SportsCar : public ElectricCar {
    int speed;

public:
    void setSports() {
        setElectric();
        cout << "Enter Top Speed: ";
        cin >> speed;
    }

    void showSports() {
        showElectric();
        cout << "Top Speed: " << speed << " km/h" << endl;
    }
};

class Sedan : public Car {
public:
    void showSedan() {
        showCar();
        cout << "Type: Sedan" << endl;
    }
};

class SUV : public Car {
public:
    void showSUV() {
        showCar();
        cout << "Type: SUV" << endl;
    }
};

class Aircraft {
protected:
    int range;

public:
    void setAircraft() {
        cout << "Enter Flight Range: ";
        cin >> range;
    }

    void showAircraft() {
        cout << "Flight Range: " << range << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    void setFlying() {
        setCar();
        setAircraft();
    }

    void showFlying() {
        showCar();
        showAircraft();
    }
};

class Registry {
public:
    void menu() {
        int choice;
        do {
            cout << "\n--- Vehicle Registry Menu ---\n";
            cout << "1. Add Car\n";
            cout << "2. Add Electric Car\n";
            cout << "3. Add Sports Car\n";
            cout << "4. Add Flying Car\n";
            cout << "5. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                Car c;
                c.setCar();
                c.showCar();
                break;
            }
            case 2: {
                ElectricCar e;
                e.setElectric();
                e.showElectric();
                break;
            }
            case 3: {
                SportsCar s;
                s.setSports();
                s.showSports();
                break;
            }
            case 4: {
                FlyingCar f;
                f.setFlying();
                f.showFlying();
                break;
            }
            case 5:
                cout << "Exit Program\n";
                break;
            default:
                cout << "Wrong Choice\n";
            }
        } while (choice != 5);
    }
};

int main() {
    Registry r;
    r.menu();

    cout << "\nTotal Vehicles Created: "
            << Vehicle::getTotal() << endl;

    return 0;
}