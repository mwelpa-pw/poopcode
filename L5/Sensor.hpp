#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <numeric>
using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>

template<typename T>
class Sensor {
    public:
        struct Identity {
            std::string hardwareID;
            std::string type;

            Identity(const std::string & hardwareID, const std::string & type) : hardwareID(hardwareID), type(type) {}
        };

        Sensor(const std::string & label, std::variant<Identity, std::string> source, std::optional<std::string> unit = std::nullopt )
             : label(label), source(source), unit(unit) {}

        std::string getLabel() const {
            return label;
        }

        std::variant<Identity, std::string> getSource() const {
            return source;
        }

        std::optional<std::string> getUnit() const {
            return unit;
        }

        std::vector<T> getMeasurements() const {
            return measurements;
        }



        struct sum_agg
        {
            double operator()(double acc, double val) const
            {
                return acc + val*val;
            }
        };

        double getRMS() const {
            std::vector<T> measurements = getMeasurements();

            double totalSum = std::accumulate(measurements.begin(), measurements.end(), 0.0, sum_agg{});
            if (totalSum == 0.0) {
                return T(0);
            }
            totalSum = totalSum / measurements.size();
            return sqrt(totalSum);
        }

        double getMin() const {
            auto measurements = getMeasurements();
            auto min = std::min_element(measurements.begin(), measurements.end());
            if (min == measurements.end()) {
                return T(0);
            }
            // return min;
        }

        bool operator>(const Sensor<T> &other) const {
            if (other.label == getLabel()) {
                if (other.getMeasurements().size() < getMeasurements().size()) {
                    return 1;
                } else {
                    return 0;
                }
            } else if (other.label < getLabel()) {
                return 1;
            } else {
                return 0;
            }
        }

        Sensor<T> operator<<(T element)
        {
            measurements.push_back(element);
            return *this;
        }

        bool operator!=(const Sensor<T> &other) const {
            if (other.label != getLabel()) {
                return 1;
            } else {
                return 0;
            }
        }

    private:
        std::string label;
        std::variant<Identity, std::string> source;
        std::optional<std::string> unit;
        std::vector<T> measurements;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Sensor<T>& other) {

    os << other.getLabel() << "["  << ", "  << "] RMS: " <<
    other.getRMS() << "Min: " << other.getMin() << "Unit: ";

    return os;
}

#endif