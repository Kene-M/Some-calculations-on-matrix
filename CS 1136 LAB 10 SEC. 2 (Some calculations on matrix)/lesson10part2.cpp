// This program will read the contents of a file into an 2D-array and calculate various values based on the contents of the file.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Global constants.
const int MAX_COLUMNS = 5;  // To hold the maximum number of columns in the matrix.

    // Function for reading numbers from the input file and storing in the 2D-array
int readFile (double [][MAX_COLUMNS], int, string);

    // Function for calculating the average of the numbers in the 2D-array.
double average (double [][MAX_COLUMNS], int);

    // Function for calculating the average for a specified column.
double columnAverage (double [][MAX_COLUMNS], int, int);

    // Function for finding the smallest value in a row.
double minValueInRow (double [][MAX_COLUMNS],int);

    // Main function.
int main()
{
        // Declare constants.
    const int MAX_ROWS = 30;  // To hold the maximum number of rows in the matrix.

        // Declare variables.
    double grades[MAX_ROWS][MAX_COLUMNS];  // Array that stores decimal values.
    int actualRows;  // To hold the actual number of rows in the matrix (based on the file).
    double arrAverage;  // To hold the average of the all the numbers contained in the matrix.
    double avgCols; // To hold the average of the numbers in each column in the matrix.
    double minRowVal;  // To hold the smallest value in each row of the matrix.
    string inputFileName;  // To hold the name of the input file.

        // Ask the user to enter the name of the input file.
    cout << "Enter input file name";
    cin >> inputFileName;
    cout << endl;

        // Call the function for reading numbers from the input file and storing in the 2D-array.
    actualRows = readFile(grades, MAX_ROWS, inputFileName);

        // If the file does not open, display error message to the user and quit the program.
    if (actualRows == -1)
    {
        cout << "File \"" << inputFileName << "\" could not be opened" << endl;
        exit(0);
    }

        // If the file does not contain at least one complete row of values, display error message and quit the program.
    else if (actualRows == 0)
    {
        cout << "The input file \"" << inputFileName << "\" did not contain any data" << endl;
        exit(0);
    }

        // Set the desired output formatting for the decimals.
    cout << setprecision(2) << fixed << showpoint;

        // Display the number of rows and columns in the matrix.
    cout << "Processing " << actualRows << " rows, and " << MAX_COLUMNS << " columns" << endl;

        // Call the function for calculating the average of the numbers in the 2D-array.
        // Store and display the average of the numbers in the 2D array.
    arrAverage = average(grades, actualRows);
    cout << "Average for all values is " << arrAverage << endl;

        // Access each column of the matrix.
    for (int column = 0; column < MAX_COLUMNS; column++)
    {
            // Call the function for calculating the average for a specified column.
            // Store and display the average of the numbers in each column.
        avgCols = columnAverage(grades, column, actualRows);

        cout << "Average for column " << column << " is " << avgCols << endl;
    }

        // Access each row of the matrix.
    for (int row = 0; row < actualRows; row++)
    {
            // Call the function for finding the smallest value in a row.
            // Store and display the smallest value in each row.
        minRowVal = minValueInRow(grades, row);

        cout << "Smallest value for row " << row << " is " << minRowVal << endl;
    }

    return 0;
}

    // Function for reading numbers from the input file and storing in the 2D-array
int readFile(double grades[][MAX_COLUMNS], int maxRows, string inputFileName)
{
        // Declare variables.
    ifstream inputFile;  // To hold the input file object.
    int numRows = 0;  // Row subscript.
    int numCols = 0;  // Column subscript.

        // Open the input file.
    inputFile.open(inputFileName);

        // If the file does not open return to the calling function.
    if (!inputFile)
        return -1;

        // Access each matrix row and store each value from the file.
    while ((numRows < maxRows) && (inputFile >> grades[numRows][numCols]))
    {
            // Update the number of columns detected in the file.
        numCols++;

            // Continue reading from the file and updating the matrix if the number of columns read reaches 5.
        if (numCols == 5)
        {
            numCols = 0;
            numRows++;
        }
    }

        // Close the input file.
    inputFile.close();

        // Return the number of rows that the matrix has.
    return numRows;
}

    // Function for calculating the average of the numbers in the 2D-array.
double average(double grades[][MAX_COLUMNS], int numberRows)
{
    double total = 0.0;  // To hold the total of all the values in the matrix.

        // Access each matrix row.
    for (int row = 0; row < numberRows; row++)
    {
            // Access each matrix column.
        for (int numCols = 0; numCols < MAX_COLUMNS; numCols++)
        {
                // Update the total of all the values in the matrix.
            total += grades[row][numCols];
        }
    }

        // Return the results to the calling function.
    return total / static_cast<double>(MAX_COLUMNS * numberRows);
}

    // Function for calculating the average for a specified column.
double columnAverage(double grades[][MAX_COLUMNS],int column, int numberRows)
{
    double total = 0;  // To hold the total of all the values in each column of the matrix.

        // Access each matrix row.
    for (int rows = 0; rows < numberRows; rows++)
    {
            // Update the total of all the values in the current accessed column of the matrix.
        total += grades[rows][column];
    }

        // Return the results to the calling function.
    return total / numberRows;
}

    // Function for finding the smallest value in a row.
double minValueInRow (double grades[][MAX_COLUMNS],int row)
{
    double minValue = grades[row][0];  // To hold the smallest value in the accessed row.

        // Access each matrix column (except the first).
    for (int numCols = 1; numCols < MAX_COLUMNS; numCols++)
    {
            // If the current accessed array element is less than the current min, update the smallest value in the current row.
        if (grades[row][numCols] < minValue)
            minValue = grades[row][numCols];
    }

        // Return the results to the calling function.
    return minValue;
}
