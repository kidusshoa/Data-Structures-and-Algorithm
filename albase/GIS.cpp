#include <iostream>
using namespace std;

int main() {
    

    
    cout << "Enter the presence of symptoms (\n 0 for Never, \n 1 for Rarely, \n 2 for Uncommon \n 3 for High \n 4 for Common \n 5 for Usual \n):\n";
        
    int fever, headache, generalPains, fatigue, exhaustion, runnyNose, sneezing, soreThroat, cough, chestDiscomfort, lossOfTaste;

    cout << "Fever: "; 
    cin >> fever;
    cout << "Headache: "; 
    cin >> headache;
    cout << "General Pains: "; 
    cin >> generalPains;
    cout << "Fatigue, Weakness: "; 
    cin >> fatigue;
    cout << "Extreme Exhaustion: "; 
    cin >> exhaustion;
    cout << "Runny Nose: "; 
    cin >> runnyNose;
    cout << "Sneezing: "; 
    cin >> sneezing;
    cout << "Sore Throat: "; 
    cin >> soreThroat;
    cout << "Cough: "; 
    cin >> cough;
    cout << "Chest Discomfort: "; 
    cin >> chestDiscomfort;
    cout << "Loss of Taste or Smell: "; 
    cin >> lossOfTaste;
    cout <<"\n";

    int diseaseCode = 0;
    if (cough == 4 && lossOfTaste == 4 && chestDiscomfort ==4 && soreThroat ==4 && runnyNose == 4 && sneezing <= 2) {
        diseaseCode = 3; 
    } else {
        if (headache == 4 && lossOfTaste == 1 && fever == 3 && exhaustion == 5 ) {
            diseaseCode = 2;  
        } else if (exhaustion == 0 && sneezing == 5 && headache == 2 && lossOfTaste == 1 ) {
            diseaseCode = 1;  
        }
    }
      
    if(diseaseCode == 1){
        cout << "Identified Disease Code: 1 " << "Common Cold" << endl;
    }else if(diseaseCode == 2){
        cout << "Identified Disease Code: 2 " << "Flu" << endl;
    }else if(diseaseCode == 3){
        cout << "Identified Disease Code: 3 " << "COVID-19" << endl;
    }else{
        cout << "Unknown disease identified \n";
    }
    
    cout <<"-----------------------------------------\n";
    cout << "Prevention Methods:\n";
    cout << "===================\n";
    switch (diseaseCode) {
        case 1:
            cout << "1. Wash your hands often.\n";
            cout << "2. Avoid close contact with anyone who has a cold.\n";
            cout << "3. Drink plenty of fluids to stay hydrated and help loosen congestion.\n";
            cout <<"-----------------------------------------------------------------------------\n";
            break;
        case 2:
            cout << "1. Get the flu vaccine each year.\n";
            cout << "2. Wash your hands often.\n";
            cout << "3. Avoid close contact with anyone who has the flu.\n";
            cout <<"-----------------------------------------------------------------------------\n";
            break;
        case 3:
            cout << "1. Get the COVID-19 vaccine.\n";
            cout << "2. Wear a mask in indoor public places. Avoid crowds.\n";
            cout << "3. Wash your hands often and avoid touching your eyes, nose, and mouth.\n";
            cout << "4. Get tested if you think you might have COVID-19.\n";
            cout <<"-----------------------------------------------------------------------------\n";
            break;
        default:
            cout << "Unknown Disease. No specific prevention methods suggested.\n";
            cout <<"-----------------------------------------------------------------------------\n";
    }

  

    return 0;
}

