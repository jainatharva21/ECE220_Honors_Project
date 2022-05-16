#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;

double money;
double spendmoney;
int stockbuy;
int stocksell;
int stockowned = 0;
int stockowned1= 0;
int stockowned2 = 0;
int stockowned3 = 0;
int stockowned4 = 0;
int day = 1;

vector<vector< string> > AAPL;
vector<vector< string> > TSN;
vector<vector< string> > XLNX;
vector<vector< string> > YUM;
vector<vector< string> > DLR;

// BUY FUNCTION
double buy(vector<vector<string> > change, vector<vector<string> > change1, vector<vector<string> > change2,
vector<vector<string> > change3, vector<vector<string> > change4)
{
    int stock;
    cout << "What stock do you want to buy: "  << endl;
    cout << "(1) AAPL " << endl;
    cout << "(2) TSN" << endl;
    cout << "(3) XLNX" << endl;
    cout << "(4) YUM" << endl;
    cout << "(5) DLR" << endl << endl;
    cout << ">> ";
    cin >> stock;
    if (stock == 1){
        cout << "Price of stock on this day: " << change[day][4] << endl;
        cout << "How many stocks would you like to buy: " << endl;
        cout << ">> ";
        cin >> stockbuy;
        spendmoney = std::stod(change[day][4]) * stockbuy;
        if (spendmoney <= money){
            stockowned = stockowned + stockbuy;
            money = money - spendmoney;
        }
    } else if (stock == 2){
        cout << "Price of stock on this day: " << change1[day][4] << endl;
        cout << "How many stocks would you like to buy: " << endl;
        cout << ">> ";
        cin >> stockbuy;
        spendmoney = std::stod(change1[day][4]) * stockbuy;
        if (spendmoney <= money){
            stockowned1 = stockowned1 + stockbuy;
            money = money - spendmoney;
        }
    } else if (stock == 3){
        cout << "Price of stock on this day: " << change2[day][4] << endl;
        cout << "How many stocks would you like to buy: " << endl;
        cout << ">> ";
        cin >> stockbuy;
        spendmoney = std::stod(change2[day][4]) * stockbuy;
        if (spendmoney <= money){
            stockowned2 = stockowned2 + stockbuy;
            money = money - spendmoney;
        }
    } else if (stock == 4){
        cout << "Price of stock on this day: " << change3[day][4] << endl;
        cout << "How many stocks would you like to buy: " << endl;
        cout << ">> ";
        cin >> stockbuy;
        spendmoney = std::stod(change3[day][4]) * stockbuy;
        if (spendmoney <= money){
            stockowned3 = stockowned3 + stockbuy;
            money = money - spendmoney;
        }
    } else if (stock == 5){
        cout << "Price of stock on this day: " << change4[day][4] << endl;
        cout << "How many stocks would you like to buy: " << endl;
        cout << ">> ";
        cin >> stockbuy;
        spendmoney = std::stod(change4[day][4]) * stockbuy;
        if (spendmoney <= money){
            stockowned4 = stockowned4 + stockbuy;
            money = money - spendmoney;
        }
    } 
    return money;
}

// SELL FUNCTION
double sell(vector<vector<string> > change, vector<vector<string> > change1, vector<vector<string> > change2,
vector<vector<string> > change3, vector<vector<string> > change4)
{
    int stock;
    cout << "What stock do you want to sell: "  << endl << endl;  
    cout << "(1) AAPL " << endl;
    cout << "(2) TSN" << endl;
    cout << "(3) XLNX" << endl;
    cout << "(4) YUM" << endl;
    cout << "(5) DLR" << endl << endl;
    cout << ">> ";
    cin >> stock;

    if (stock == 1){
        cout << "Price of stock on this day: " << change[day][4] << endl;
        cout << "How many stocks would you like to sell: "<< endl;
        cout << ">> ";
        cin >> stocksell;
        if (stocksell <= stockowned){
            stockowned = stockowned - stocksell;
            stocksell = std::stod(change[day][4]) * stocksell;
            money = money + stocksell;
        }
    } else if (stock == 2){
        cout << "Price of stock on this day: " << change1[day][4] << endl;
        cout << "How many stocks would you like to sell: "<< endl;
        cout << ">> ";
        cin >> stocksell;
        if (stocksell <= stockowned){
            stockowned1 = stockowned1 - stocksell;
            stocksell = std::stod(change1[day][4]) * stocksell;
            money = money + stocksell;
        }
    } else if (stock == 3){
        cout << "Price of stock on this day: " << change2[day][4] << endl;
        cout << "How many stocks would you like to sell: "<< endl;
        cout << ">> ";
        cin >> stocksell;
        if (stocksell <= stockowned){
            stockowned2 = stockowned2 - stocksell;
            stocksell = std::stod(change2[day][4]) * stocksell;
            money = money + stocksell;
        }
    } else if (stock == 4){
        cout << "Price of stock on this day: " << change3[day][4] << endl;
        cout << "How many stocks would you like to sell: "<< endl;
        cout << ">> ";
        cin >> stocksell;
        if (stocksell <= stockowned){
            stockowned3 = stockowned3 - stocksell;
            stocksell = std::stod(change3[day][4]) * stocksell;
            money = money + stocksell;
        }
    } else if (stock == 5){
        cout << "Price of stock on this day: " << change4[day][4] << endl;
        cout << "How many stocks would you like to sell: "<< endl;
        cout << ">> ";
        cin >> stocksell;
        if (stocksell <= stockowned){
            stockowned4 = stockowned4 - stocksell;
            stocksell = std::stod(change4[day][4]) * stocksell;
            money = money + stocksell;
        }
    }
    return money;
}

// DAILY PCT CHANGE FUNTION
double daily_pct_changes(vector<vector<string> > change, vector<vector<string> > change1, vector<vector<string> > change2,
vector<vector<string> > change3, vector<vector<string> > change4)
{
    string names[] = {"AAPL", "TSN", "XLNX", "YUM", "DLR"};
    string newValData[] = {change[day+1][4], change1[day+1][4], change2[day+1][4], change3[day+1][4], change4[day+1][4]};
    string oldValData[] = {change[day][4], change1[day][4], change2[day][4], change3[day][4], change4[day][4]};

    for (int i = 0; i < 5; i++){

        double newVal = std::stod(newValData[i]);
        double oldVal = std::stod(oldValData[i]);

        double pct_change = ((newVal - oldVal) / oldVal) * 100.00;
        if (newVal < oldVal)
        {
            cout << "The " << names[i] <<" Stock went down by: " << pct_change << "%\n";
        }
        else
        {
            cout << "The " << names[i] << " Stock went up by: " << pct_change << "%\n";
        }
    }
    return 0;
}

// OPENING THE CSV FILE FUNCTION
void options ()
{
    int in;
    cout << "\nWhat would you like to do?\n\nYou can:\n" << endl;
    cout << "(1). Buy a stock" << endl;
    cout << "(2). Sell a stock" << endl;
    cout << "(3). End day" << endl;
    cout << ">> ";
    cin >> in;
    if (in == 1)
    {
        buy(AAPL,TSN,XLNX,YUM,DLR);
        cout << "Current Money: $" << money << endl;
        cout << "Current Spend Money: $" << spendmoney << endl;
        cout << "AAPL Stock Owned: " << stockowned << endl;
        cout << "TSN Stock Owned: " << stockowned1 << endl;
        cout << "XLNX Stock Owned: " << stockowned2 << endl;
        cout << "YUM Stock Owned: " << stockowned3 << endl;
        cout << "DLR Stock Owned: " << stockowned4 << endl;
        options ();
    }
    else if (in == 2)
    {
        sell(AAPL,TSN,XLNX,YUM,DLR);
        cout << "Current Money: $" << money << endl;
        cout << "Current Spend Money: $" << spendmoney << endl;
        cout << "AAPL Stock Owned: " << stockowned << endl;
        cout << "TSN Stock Owned: " << stockowned1 << endl;
        cout << "XLNX Stock Owned: " << stockowned2 << endl;
        cout << "YUM Stock Owned: " << stockowned3 << endl;
        cout << "DLR Stock Owned: " << stockowned4 << endl;
        options();
    }
    else if (in == 3)
    {
        day += 1;
        cout << "Current Money: $" << money << endl;
        cout << "Current Spend Money: $" << spendmoney << endl;
        daily_pct_changes(AAPL,TSN,XLNX,YUM,DLR);
        options ();
    }
}
// READING THE CSV FILES
int file_main()
{
    string stock[] = {"AAPL_data.csv", "TSN_data.csv", "XLNX_data.csv", "YUM_data.csv", "DLR_data.csv"};
    AAPL.clear();
    fstream file (stock[0], ios::in);
    vector<string> row;
    string line,word;

    if(file.is_open()){
        while(getline(file, line)){
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
                AAPL.push_back(row);
        }
    } else {
        cout<<"Could not open the file\n";
    }
    file.close();
    TSN.clear();
    fstream file1 (stock[1], ios::in);
    vector<string> row1;
    string line1,word1;

    if(file1.is_open()){
        while(getline(file1, line1)){
            row1.clear();

            stringstream str1(line1);

            while(getline(str1, word1, ','))
                row1.push_back(word1);
                TSN.push_back(row1);
            
        }
    } else {
        cout<<"Could not open the file\n";
    }
    file1.close();
    XLNX.clear();
    fstream file2 (stock[2], ios::in);
    vector<string> row2;
    string line2,word2;

    if(file2.is_open()){
        while(getline(file2, line2)){
            row2.clear();

            stringstream str2(line2);

            while(getline(str2, word2, ','))
                row2.push_back(word2);
                XLNX.push_back(row2);
            
        }
    } else {
        cout<<"Could not open the file\n";
    }
    
    file2.close();
    YUM.clear();
    fstream file3 ("YUM_data.csv", ios::in);
    vector<string> row3;
    string line3,word3;

    if(file3.is_open()){
        while(getline(file3, line3)){
            row3.clear();

            stringstream str3(line3);

            while(getline(str3, word3, ','))
                row3.push_back(word3);
                YUM.push_back(row3);
            
        }
    } else {
        cout<<"Could not open the file\n";
    }
    file3.close();
    DLR.clear();
    fstream file4 ("DLR_data.csv", ios::in);
    vector<string> row4;
    string line4,word4;

    if(file4.is_open()){
        while(getline(file4, line4)){
            row4.clear();

            stringstream str4(line4);

            while(getline(str4, word4, ','))
                row4.push_back(word4);
                DLR.push_back(row4);
            
        }
    } else {
        cout<<"Could not open the file\n";
    }
    file4.close();
    options();
    return 0;
}

// MAIN FUNTION
int main()
{
    money = 10000;
    spendmoney = 5000;
    file_main();
}
