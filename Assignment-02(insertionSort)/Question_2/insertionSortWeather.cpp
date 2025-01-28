#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// Structure to represent weather data
struct WeatherData {
    string city;
    string timeStamp;
    double temperature;
    double humidity;
    double rainfall;
};
// Function to perform Insertion Sort
void insertionSort(vector<WeatherData>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        WeatherData key = data[i];
        int j = i - 1;

        // Move elements of data[0..i-1] that are greater than key.city to one position ahead of their current position
        while (j >= 0 && data[j].city > key.city) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

// Function to generate random weather data
vector<WeatherData> generateWeatherData(int numSamples) {
    vector<string> cities = {"Delhi", "Bangalore", "Mumbai", "UP", "Goa"};
    vector<string> times = {"5:00 AM", "6:00 AM", "7:00 AM", "8:00 AM", "9:00 AM", 
                            "10:00 AM", "11:00 AM", "12:00 PM", "1:00 PM", "2:00 PM"};
    vector<WeatherData> data;

    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < numSamples; ++i) {
        WeatherData record;
        record.city = cities[rand() % cities.size()];
        record.timeStamp = times[rand() % times.size()];
        record.temperature = 20 + (rand() % 20); // Random temperature between 20 and 40
        record.humidity = 30 + (rand() % 70);    // Random humidity between 30% and 100%
        record.rainfall = (rand() % 50);         // Random rainfall between 0 and 50 mm
        data.push_back(record);
    }

    return data;
}

// Function to print the weather data
void printWeatherData(const vector<WeatherData>& data) {
    cout << setw(5) << "S.No." << setw(15) << "City" << setw(15) << "Time Stamp"<< setw(15) << "Temp. (C)" << setw(15) << "Humidity (%)" << setw(15) << "Rainfall (mm)" << endl;
    // if we write data.size() instead of 15 it will print all the data
    for (size_t i = 0; i < 15; ++i) {
        cout << setw(5) << i + 1 << setw(15) << data[i].city << setw(15) << data[i].timeStamp<< setw(15) << data[i].temperature << setw(15) << data[i].humidity << setw(15) << data[i].rainfall << endl;
    }
}

int main() {
    // Generate weather data with at least 100 samples
    vector<WeatherData> weatherData = generateWeatherData(100);

    // Input data sorted by time
    cout << "Input Data (Unsorted) first 15 data only:" << endl;
    printWeatherData(weatherData);
    insertionSort(weatherData);

    // Output data sorted by city
    cout << "\nOutput Data (Sorted by City) first 15 data only:" << endl;
    printWeatherData(weatherData);

    return 0;
}