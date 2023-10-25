/*****************************************************************************/
//
//  Author:        Vineet Byakod
//
//  Description:   This program reads in data about various subjects' heart rates
//                 from a file. The data includes each subject's ID, measured 
//                 maximum heart rate, age, average commuting heart rate over 5 days, 
//                 maximum commuting heart rate over 5 days, and exercise heart rate over 5 days.
//                 The program then calculates and outputs a summary including average 
//                 commuting heart rate, days exercised, estimated maximum heart rate, 
//                 the ratio of measured to estimated maximum heart rate, and the ratio 
//                 of maximum commuting heart rate to measured heart rate. The output is sorted
//                 by subject number.
//
/*****************************************************************************/

// Include necessary libraries
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;

// Define a struct to store each subject's data
struct SubjectData {
    int id;
    int measuredMaxHR;
    int age;
    vector<double> avgCommutingHRs;
    vector<int> maxCommutingHRs;
    vector<double> exerciseHRs;
};

/*****************************************************************************/
//              main()
/*****************************************************************************/
/*
********************
        Variables:
********************
vector<SubjectData> subjects; A vector to store subjects' heart rate data
int id, measuredMaxHR, age; Subject ID, Measured maximum heart rate, and Age of subject
double avgCommutingHR_single, exerciseHR; Single Average commuting heart rate, and Exercise heart rate
int maxCommutingHR; Maximum commuting heart rate

Vectors to store various results for output:
vector<int> subjectNumber; Subject numbers
vector<double> avgCommutingHRs; Average commuting heart rates
vector<int> daysExercised; Number of days exercised
vector<int> estimatedMaxHR; Estimated maximum heart rate
vector<double> measuredToEstimatedRatio; Ratios of measured to estimated maximum heart rate
vector<double> maxCommutingHRtoMeasuredRatio; Ratios of maximum commuting heart rate to measured heart rate

*************************
   Functionality:
*************************

1. Reads input data from the "HR.txt" file, including:
    a) Subject ID
    b) Measured maximum heart rate
    c) Age
    d) Average commuting heart rate over 5 days
    e) Maximum commuting heart rate over 5 days
    f) Exercise heart rate over 5 days

2. Calculates the results needed for output, including:
    a) Average commuting heart rate
    b) Number of days exercised
    c) Estimated maximum heart rate
    d) Ratio of measured to estimated maximum heart rate
    e) Ratio of maximum commuting heart rate to measured heart rate

3. Sorts the data by subject number.

4. Outputs the calculated results in the following order:
    a) Subject number
    b) Average commuting heart rate
    c) Number of days exercised
    d) Estimated maximum heart rate
    e) Ratio of measured to estimated maximum heart rate
    f) Ratio of maximum commuting heart rate to measured heart rate

*****************************************************************************/

int main() {
    // Vector to store all subjects' data
    vector<SubjectData> subjects;
    // Open the input file
    ifstream inputFile("HR.txt");
    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        cerr << "Failed to open HR.txt file." << endl;
        return 1;
    }
    // Variables to store the input data for each subject
    int id, measuredMaxHR, age;
    double avgCommutingHR_single, exerciseHR;
    int maxCommutingHR;
    // Read the input data for each subject
    while (inputFile >> id >> measuredMaxHR >> age) {
        // Create a new SubjectData object to store this subject's data
        SubjectData subjectData;
        subjectData.id = id;
        subjectData.measuredMaxHR = measuredMaxHR;
        subjectData.age = age;
        // Read the commuting and exercise heart rates for each day
        for (int i = 0; i < 5; i++) {
            inputFile >> avgCommutingHR_single >> maxCommutingHR >> exerciseHR;
            subjectData.avgCommutingHRs.push_back(avgCommutingHR_single);
            subjectData.maxCommutingHRs.push_back(maxCommutingHR);
            subjectData.exerciseHRs.push_back(exerciseHR);
        }
        // Add this subject's data to the vector of all subjects' data
        subjects.push_back(subjectData);
    }
    // Close the input file now that we're done reading from it
    inputFile.close();
    // Create vectors to store the calculated results
    vector<int> subjectNumber;
    vector<double> avgCommutingHRs;
    vector<int> daysExercised;
    vector<int> estimatedMaxHR;
    vector<double> measuredToEstimatedRatio;
    vector<double> maxCommutingHRtoMeasuredRatio;
    // Calculate the results for each subject
    for (const SubjectData &subject : subjects) {
        // Add this subject's ID to the vector of subject numbers
        subjectNumber.push_back(subject.id);
        // Calculate this subject's average commuting heart rate
        double sumCommutingHR = 0;
        int validDays = 0;
        int exercisedDays = 0;
        int highestCommutingHR = 0;
        // Loop through each day
        for (int i = 0; i < 5; i++) {
            // Only consider days where the average commuting heart rate is not -1
            if (subject.avgCommutingHRs[i] != -1) {
                sumCommutingHR += subject.avgCommutingHRs[i];
                validDays++;
            }
            // Count the number of days where the subject exercised
            if (subject.exerciseHRs[i] != 0) {
                exercisedDays++;
            }
            // Keep track of the highest commuting heart rate
            highestCommutingHR = max(highestCommutingHR, subject.maxCommutingHRs[i]);
        }
        // Calculate the average commuting heart rate and add it to the corresponding vector
        double weeklyAvgCommutingHR = sumCommutingHR / validDays;
        avgCommutingHRs.push_back(weeklyAvgCommutingHR);
        // Add the number of days the subject exercised to the corresponding vector
        daysExercised.push_back(exercisedDays);


        // Calculate the estimated maximum heart rate and add it to the corresponding vector
        int estMaxHR = 220 - subject.age;
        estimatedMaxHR.push_back(estMaxHR);
        // Calculate the ratio of measured to estimated maximum heart rate and add it to the corresponding vector
        double ratioMeasuredToEstimated = (subject.measuredMaxHR * 100.0) / estMaxHR;
        measuredToEstimatedRatio.push_back(ratioMeasuredToEstimated);

        double ratioMaxCommutingToMeasured = (highestCommutingHR * 100.0) / subject.measuredMaxHR;
        maxCommutingHRtoMeasuredRatio.push_back(ratioMaxCommutingToMeasured);
    }
    // Create a vector to store the order in which to sort the subjects
    vector<size_t> sortOrder(subjectNumber.size());
    iota(sortOrder.begin(), sortOrder.end(), 0);
    // Sort the order vector based on the subject numbers
    sort(sortOrder.begin(), sortOrder.end(), [&](size_t a, size_t b) {
        return subjectNumber[a] < subjectNumber[b];
    });
    // Define a helper function to apply the sort order to a vector
    auto applySortOrder = [&](const auto &v) {
        vector<typename remove_reference<decltype(v)>::type::value_type> sorted(v.size());
        for (size_t i = 0; i < sortOrder.size(); i++) {
            sorted[i] = v[sortOrder[i]];
        }
        return sorted;
    };
    
    
    // Apply the sort order to each result vector
    subjectNumber = applySortOrder(subjectNumber);
    avgCommutingHRs = applySortOrder(avgCommutingHRs);
    daysExercised = applySortOrder(daysExercised);
    estimatedMaxHR = applySortOrder(estimatedMaxHR);
    measuredToEstimatedRatio = applySortOrder(measuredToEstimatedRatio);
    maxCommutingHRtoMeasuredRatio = applySortOrder(maxCommutingHRtoMeasuredRatio);
    // Output the calculated results
    cout << "COMMUTING AND EXERCISE HEART RATE SUMMARY\n\n";
    cout << setw(7) << "SUBJECT" << setw(15) << "AVERAGE" << setw(12) << "DAYS" << setw(14) << "ESTIMATED" << setw(15) << "%MEASURED TO" << setw(12) << "%MAX\n";
    cout << setw(7) << "NUMBER" << setw(15) << "COMMUTING" << setw(12) << "EXERCISED" << setw(14) << "MAX HR" << setw(15) << "ESTIMATED" << setw(12) << "COMMUTING\n";
    cout << setw(7) << "" << setw(15) << "HR" << setw(12) << "" << setw(14) << "" << setw(15) << "MAX HR" << setw(12) << "HR TO\n";
    cout << setw(7) << "" << setw(15) << "" << setw(12) << "" << setw(14) << "" << setw(15) << "" << setw(12) << "MEASURED\n";
    cout << string(80, '-') << '\n';


    // Loop over each subject 
    for (size_t i = 0; i < subjectNumber.size(); i++) {
        cout << setw(7) << subjectNumber[i] << setw(15) << fixed << setprecision(1) << avgCommutingHRs[i] << setw(12) << daysExercised[i] << setw(12) << estimatedMaxHR[i] << setw(12) << setprecision(1) << measuredToEstimatedRatio[i] << setw(12) << maxCommutingHRtoMeasuredRatio[i] << '\n';
    }

    return 0;
}







