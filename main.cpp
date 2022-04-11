// MAIN.CPP - Case Study, Recorded atmospheric events
//
// Calculate the average of wind speed and ambient temperature specific month and year
// Calculate average wind speed and ambient temperature for each month of a specific year
// Calculate total solar radiation
// Calculate average wind speed, average ambient air temperature and total solar radiation
//
// Author Andreas Lau
// Modified on 09/04/2021, Andreas edited the inFileList to met_index file.

//--------------------------------------------------------------------------------------------
//Includes

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

#include "windlogtype.h"
#include "windlog.h"
//--------------------------------------------------------------------------------------------

void ReadData(Map<int, Map<int, WindLogType>> &windlog, std::string fileNameList, std::string path);

void PrintMenu(Map<int, Map<int, WindLogType>> &windlog, WindLog &output, std::string file);

void MonthYearAvgWindTemp(WindLog &output);

void YearAvgWindTemp(WindLog &output);

void YearTotalSolarRadiation(WindLog &output);

void YearAvgWsAtSrToFile(WindLog &output, std::string file);

void TimeHighSolarRadiation(Map<int, Map<int, WindLogType>> &windlog, WindLog &output);

int main()
{
    Map<int, Map<int, WindLogType>> windlog;

    std::string outFile = "WindTempSolar.csv";

    std::string path = "./data/";
    std::string inFileList = path + "met_index.txt";

    ReadData(windlog, inFileList, path);

    WindLog output(windlog);

    PrintMenu(windlog, output, outFile);

    return(0);
}

//Reads data from file
void ReadData(Map<int, Map<int, WindLogType>> &windlog, std::string fileNameList, std::string path)
{
    std::ifstream fileList(fileNameList);
    if(!fileList)
        exit(-1);

    std::string fileName;

    int year;
    int month;
    int vi = 0;

    while(getline(fileList, fileName))
    {
        fileName = path + fileName;

        //open file
        std::ifstream inFile(fileName);
        if(!inFile)
            exit(-2);
        std::string input;
        int i, windSpeedLoc, airTempLoc, solarRadLoc;

        //Find the collumn location of wind speed
        i=0;
        while(getline(inFile, input, ','))
        {
            if(input == "S")
                windSpeedLoc = i-1;
            else if(input == "SR")
                solarRadLoc = i-windSpeedLoc-2;
            else if(input == "Sx")
            {
                airTempLoc = i-(windSpeedLoc+solarRadLoc)-3+1;
                break;
            }
            i++;
        }
        inFile.ignore(999, '\n');

        //read data into structure
        while(getline(inFile, input, ' '))
        {
            Date tempDate = input;
            year = tempDate.GetYear();
            if(month != tempDate.GetMonth())
                vi = 0;
            month = tempDate.GetMonth();

            bool dataValid = true;
            windlog[std::move(year)][std::move(month)].ddate[vi] = input;

            getline(inFile, input, ',');
            windlog[std::move(year)][std::move(month)].ttime[vi] = input;

            for(int j=0; j<windSpeedLoc; j++)
                inFile.ignore(999, ',');
            getline(inFile, input, ',');
            if(input == "N/A")
                dataValid = false;
            else
                windlog[std::move(year)][std::move(month)].wwindspeed[vi] = stof(input);

            for(int j=0; j<solarRadLoc; j++)
                inFile.ignore(999, ',');
            getline(inFile, input, ',');
            if(input == "N/A")
                dataValid = false;
            else
                windlog[std::move(year)][std::move(month)].ssolarRadiation[vi] = stof(input);

            for(int j=0; j<airTempLoc; j++)
                inFile.ignore(999, ',');
            getline(inFile, input, '\n');
            if(input == "N/A")
                dataValid = false;
            else
                windlog[std::move(year)][std::move(month)].aairTemp[vi] = stof(input);

            if(dataValid)
                vi++;
        }
        std::cout << "Successfully loaded: " << fileName << std::endl;
        inFile.close();
    }
    fileList.close();
    std::cout << std::endl;
}

//Displays menu
void PrintMenu(Map<int, Map<int, WindLogType>> &windlog, WindLog &output, std::string file)
{
    std::string choice;
    do
    {
        std::cout << '\n' << "Enter '1' to display the average wind speed and average ambient air temperature for a specified month and year."<<'\n';
        std::cout << "Enter '2' to display the average wind speed and average ambient air temperature for each month of a specified year."<<'\n';
        std::cout << "Enter '3' to display the total solar radiation in KWh/m^2 for each month of a specified year."<<'\n';
        std::cout << "Enter '4' to display the average wind speed(km/h), ambient air temperature and total solar radiation in kWh/m^2 for each month of a specified year in a file named 'WindTempSolar.csv"<<'\n';
        std::cout << "Enter '5' to display highest solar radiation time"<<'\n';
        std::cout << "Enter '6' to quit the program"<<'\n';
        std::cout << '\n' << "Please enter an option: " ;

        std::cin >> choice;

        if(choice == "1")
            MonthYearAvgWindTemp(output);
        else if(choice == "2")
            YearAvgWindTemp(output);
        else if(choice == "3")
            YearTotalSolarRadiation(output);
        else if(choice == "4")
            YearAvgWsAtSrToFile(output, file);
        else if(choice == "5")
            TimeHighSolarRadiation(windlog, output);
        else if(choice == "6")
            std::cout << "End!";
        else
            std::cout << "Invalid option, try again\n";

        std::cout << std::endl;

    }
    while(choice != "6");
}


void MonthYearAvgWindTemp(WindLog &output)
{
    int year, month;
    try
    {
        std::cout << "Year: ";
        std::cin >> year;
        if(year < 1 || year > 9999)
            throw "INVALID YEAR";

        std::cout << "Month: ";
        std::cin >> month;
        std::cout << std::endl;
        if(month > 12 || month < 1)     //Month has to be between 1-12
            throw "INVALID MONTH";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);
        std::cout << Date::GetMonthString(month) << " " << year << ": ";
        if(!output.SearchOutput(year*100 + month))
                std::cout << "No Data\n";
        else
        {
            std::cout << "\nAverage speed: " << output.GetAvgWindSpeed()[std::move(year)][std::move(month)] << " Km/h \n";
            std::cout << "Sample stdev: " << output.GetWindStdDev()[std::move(year)][std::move(month)] << "\n";
        }
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');
        MonthYearAvgWindTemp(output);
    }
}



void YearAvgWindTemp(WindLog &output)
{
    int year;
    try
    {
        std::cout << "Year: ";
        std::cin >> year;
        std::cout << std::endl;

        if(std::cin.fail() || year < 1 || year > 9999)
                throw "INVALID YEAR";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);
        for(int month=1; month<=12; month++)
        {
            std::cout << Date::GetMonthString(month) << ": ";
            if(!output.SearchOutput(year*100 + month))
                    std::cout << "No Data\n";
            else
            {
                std::cout << "Average: " << output.GetAvgAirTemp()[std::move(year)][std::move(month)] << " degrees C, ";
                std::cout << "stdev: " << output.GetTempStdDev()[std::move(year)][std::move(month)] << "\n";
            }
        }
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');
        YearAvgWindTemp(output);
    }
}

void YearTotalSolarRadiation(WindLog &output)
{
    int year;
    try
    {
        std::cout << "Year: ";
        std::cin >> year;
        std::cout << std::endl;

        if(std::cin.fail() || year < 1 || year > 9999)
            throw "INVALID YEAR";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);
        for(int month=1; month<=12; month++)
        {
            std::cout << Date::GetMonthString(month) << ": ";
            if(!output.SearchOutput(year*100 + month))
                    std::cout << "No Data\n";
            else
                std::cout << output.GetTotalSolarRadiation()[std::move(year)][std::move(month)] << " kWh/m^2\n";
        }
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');
        YearTotalSolarRadiation(output);
    }
}


void YearAvgWsAtSrToFile(WindLog &output, std::string file)
{
    int year;
    int counter = 0;
    try
    {
        std::ofstream outFile(file);

        std::cout << "Year: ";
        std::cin >> year;
        std::cout << std::endl;

        if(std::cin.fail() || year < 1 || year > 9999)
            throw "INVALID YEAR";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);
        outFile << year << "\n";
        for(int month=1; month<=12; month++)
        {
            if(output.SearchOutput(year*100 + month))
            {
                outFile << Date::GetMonthString(month) << ",";
                if(output.GetWindStdDev()[std::move(year)][std::move(month)] < 0)
                        outFile << ",";
                else
                    outFile << output.GetAvgWindSpeed()[std::move(year)][std::move(month)] << "(" << output.GetWindStdDev()[std::move(year)][std::move(month)] << "),";
                if(output.GetTempStdDev()[std::move(year)][std::move(month)] < 0)
                    outFile << ",";
                else
                    outFile << output.GetAvgAirTemp()[std::move(year)][std::move(month)] << "(" << output.GetTempStdDev()[std::move(year)][std::move(month)] << ")";
                if(output.GetTotalSolarRadiation()[std::move(year)][std::move(month)] < 0)
                    outFile << " \n";
                else
                    outFile << output.GetTotalSolarRadiation()[std::move(year)][std::move(month)] << "\n";
            }
            else
                counter++;
        }
        if(counter == 12)
            std::cout << "No Data\n";

        std::cout << "Successfuly saved: " << file << std::endl;
        outFile.close();
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');
        YearAvgWsAtSrToFile(output, file);
    }
}

void TimeHighSolarRadiation(Map<int, Map<int, WindLogType>> &windlog, WindLog &output)
{
    std::string dateString;
    std::cout << "Date (DD/MM/YYYY): ";
    std::cin >> dateString;
    std::cout << std::endl;

    try
    {
        Date date(dateString);
        int year = date.GetYear();
        int month = date.GetMonth();
        output.CalculateHighSolar(windlog, date);

        std::cout << std::fixed << std::showpoint << std::setprecision(1);
        std::cout << "Date: " << dateString << std::endl;
        if(!output.SearchOutput(year*100 + month))
            std::cout << "No data" << std::endl;
        else
        {
            std::cout <<  "High solar radiation for the day: " << output.GetHighestRadiationDay() << "W/m2\n\n";
            std::cout << "Time:\n";
            for(int i=0; i<output.GetHighestRadiationTime().GetCurrentSize(); i++)
                std::cout << output.GetHighestRadiationTime()[i].GetTimeString() << std::endl;
        }
    }
    catch(std::invalid_argument& e)
    {
        std::cout << "INVALID DATE" << std::endl;
        TimeHighSolarRadiation(windlog, output);
    }
}
