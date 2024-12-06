#include <iostream>
#include <regex>
#include <string>

class Route {
private:
    std::string departurePoint;
    std::string destinationPoint;
    std::string flightNumber;

public:
    Route(const std::string& departure, const std::string& destination, const std::string& flight)
        : departurePoint(departure), destinationPoint(destination), flightNumber(flight) {}

    std::string getDeparturePoint() const { return departurePoint; }
    std::string getDestinationPoint() const { return destinationPoint; }
    std::string getFlightNumber() const { return flightNumber; }

    std::string getAirline() const {
        std::regex flightRegex(R"(^([A-Z]{2})\d+$)");
        std::smatch match;

        if (std::regex_match(flightNumber, match, flightRegex)) {
            std::string airlineCode = match[1];
            if (airlineCode == "UA") return "United Airlines";
            if (airlineCode == "AA") return "American Airlines";
            if (airlineCode == "DL") return "Delta Airlines";
            if (airlineCode == "LH") return "Lufthansa";
            return "Unknown Airline";
        } else {
            return "Invalid flight number";
        }
    }

    void displayRoute() const {
        std::cout << "Departure: " << departurePoint
                  << ", Destination: " << destinationPoint
                  << ", Flight Number: " << flightNumber
                  << ", Airline: " << getAirline() << std::endl;
    }
};

int main() {
    Route route1("New York", "Los Angeles", "AA1234");
    Route route2("Frankfurt", "Chicago", "LH5678");
    Route route3("San Francisco", "Tokyo", "UA999");

    route1.displayRoute();
    route2.displayRoute();
    route3.displayRoute();

    Route invalidRoute("Paris", "Rome", "123XYZ");
    invalidRoute.displayRoute();

    return 0;
}
