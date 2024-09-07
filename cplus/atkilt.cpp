#include <iostream>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding the random number generator

using namespace std;

// Function to display the menu options
void showChoice() {
	cout << "            //////////////////////////////////////////////////////////////////////////////////// "<<endl;
    cout << "                     *         MENU:                                                 *          "<<endl;
    cout << "                     *           +. Addition                                         *          "<<endl;
    cout << "                     *           -. Subtraction                                      *          "<<endl;
    cout << "                     *           *. Multiplication                                   *          "<<endl;
    cout << "                     *           /. Division                                         *          "<<endl;
    cout << "                     #################################################################         "<<endl;
    cout << "                     *           1. Pass by Value                                    *          "<<endl;
    cout << "                     *           2. Pass by Reference                                *         "<<endl;
    cout << "                     *           3. Function overloading                             *         "<<endl;
    cout << "                     *           4. Default argument                                 *         "<<endl;
    cout << "                     *           5. Recursive                                        *        "<<endl;
    cout << "                     *           6. Inline Function                                  *         "<<endl;
    cout << "                     *           7. Built in function                                *         "<<endl;
    cout << "                     *           8. Passing arry as argument                         *         "<<endl;
    cout << "                     *           9. Playing game using random function for dice      *         "<<endl;
    cout << "                     *           E. Exit                                             *         "<<endl;
    cout << "           /////////////////////////////////////////////////////////////////////////////////////"<<endl;
}
void PassArry_as_argument(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		arr[i]=arr[i]+2;
	}
	cout<<"\n\n";
	for(int i=0; i<size; i++)
	{
	cout<<arr[i]<<" ";
	}
	cout<<"\n\n";
}
// Function to perform addition
double add(double a, double b)
 {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) 
{
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b)
 {
    return a * b;
}

// Function to perform division
double divide(double a, double b) 
{
    return a / b;
}

// Function to demonstrate passing by value
void passing_by_value(int x)
 {
    x += 10;
    cout << "Value inside the function: " << x << endl;
}

// Function to demonstrate passing by reference
void passing_by_reference(int& x)
 {
    x += 10;
    cout << "Value inside the function: " << x << endl;
}

// Function overloading example
int sum(int a, int b)
 {
    return a + b;
}

double sum(double a, double b) 
{
    return a + b;
}

// Function with default arguments
int multiply(int a, int b = 2)
 {
    return a * b;
}

// Recursive function
int factorial(int n)
 {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Inline function example
inline int square(int x)
 {
    return x * x;
}

// Built-in function example
void built_in_function_example()
 {
	int size=5;
    int arr[size];
    
    cout << "Enter Array elements"<<endl;
    for (int i = 0; i < size; i++)
	 {
    	 cout << "Enter Array elements for arry["<<i<<"] =  "<<endl;
        cin >> arr[i];
    }
       for (int i = 0; i < size; i++)
	    {
        cout << arr[i] << " ";
    }
    cout << "\nMaximum element: " << max(arr[0], arr[size - 1])<<endl;
    cout << "\nMinimum element: " << min(arr[0], arr[size - 1]) << endl;
}

// Function to play a dice game using random number generation
void playDiceGame()
 {
    srand(time(0)); // Seed the random number generator with current time

    cout << "Rolling the dice..."<<endl;
    int diceResult = rand() % 6 + 1; // Generate a random number between 1 and 6

    cout << "You rolled a " << diceResult << "!"<<endl;
}
void group_members()
{
	cout<<"*****************************************************"<<endl;
	cout<<"*        1. Arsema mamush............1064/15        *"<<endl;
	cout<<"*        2. tihtina zebene...........1004/15        *"<<endl;	
	cout<<"*        3. obsa mustefa.............1778/15        *"<<endl;
	cout<<"*        4. matiwos bizuneh..........0707/15        *"<<endl;
	cout<<"*****************************************************"<<endl;
	cout<<"                                                     "<<endl;
	cout<<"                                                     "<<endl;
}
int main() 
{
    char choice,choice1;
    double num1, num2;
    do{
    	cout<<"----------------------------------------------"<<endl;
    	cout<<"press 1 to Show Project Menu                  "<<endl;
    	cout<<"press 2 to Show Group Members                 "<<endl;
    	cout<<"press 3 to Exit                               "<<endl;
    	cout<<"Enter Your Choice :                           "<<endl;
    	cout<<"----------------------------------------------"<<endl;
    	cin>>choice1;
    	if(choice1 == '1')
		{
        showChoice();
        cout << "                           "<<endl;
        cout << "Enter your choice:         "<<endl;
        cin >> choice;

        switch (choice)
		 {
            case '+':
                cout << "Enter two numbers: "<<endl;
                cin >> num1 >> num2;
                cout << "Sum: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Enter two numbers: "<<endl;
                cin >> num1 >> num2;
                cout << "Difference: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Enter two numbers: "<<endl;
                cin >> num1 >> num2;
                cout << "Product: " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << "Enter two numbers: "<<endl;
                cin >> num1 >> num2;
                cout << "Quotient: " << divide(num1, num2) << endl;
                break;
            case '1':
            	int value;
            	cout << "enter integer number: "<<endl;
            	cin>>value;
            	cout << "Value before function call: " << value << endl;
                passing_by_value(value);
                cout << "Value after function call: " << value << endl;
                break;
            case '2':
               	int valuee;
            	cout << "enter integer number: "<<endl;
            	cin>>valuee;
            	cout << "Value before function call: " << valuee << endl;
                passing_by_reference(valuee);
                cout << "Value after function call: " << valuee << endl;
                break;
            case '3':
            	int ch;
                    cout << "1 for sum integer numbers"<<endl;
                    cout << "2 for sum floating point numbers"<<endl;
                    cout << "Enter your choice: "<<endl;
                    cin>>ch;
                    if(ch==1)
					{
                    	int n1,n2;
                     cout << "Enter first integer: "<<endl;
					 cin>>n1;
					  cout << "Enter second integer: "<<endl;
					 cin>>n2;	
                    cout << "Sum using int: " << sum(n1, n2) << endl;
					}else if(ch==2)
					{
							double nm1,nm2;
                     cout << "Enter first floating number: "<<endl;
					 cin>>nm1;
					  cout << "Enter second floating number: "<<endl;
					 cin>>nm2;
						cout << "Sum using double: " << sum(nm1, nm1) << endl;
					}else{
						cout << "wrong choice try again "<<endl;
					}
                break;
            case '4':
              	int num1,num2;
                 cout << "Enter a first number: "<<endl;
		    	 cin>>num1;
		    	 cout << "Enter a second number: "<<endl;
		    	 cin>>num2;
                cout << "Multiply "<<num1<<" by default (2): "<< multiply(num1) << endl;
                cout << "Multiply "<<num1<<" by "<<num2<<": " << multiply(num1, num2)<<endl;
                break;
            case '5':
            	int num;
                cout << "Factorial of any Numbers Using Recursive function "<<endl; 
                cout << "Enter an integer number :"<<endl;
                cin>>num;
                cout << "Factorial of "<<num<<" is "<< factorial(num) << endl;
                break;
            case '6':
                cout << "Example of Inline Function"<<endl;
                int inl;
                cout<<"Enter a number :"<<endl;
                cin>>inl;
                cout << "Square of "<<inl<<" : "<< square(inl) << endl;                
                break;
            case '7':
                cout << "Example of Built in Function"<<endl;
                 built_in_function_example();
                break;
            case '8':{
				
			     	cout << "Example of Passing Arry As Argument "<<endl;
                 	int size=5;
                    int arr[size];
    
                    cout << "Enter Array elements"<<endl;
                    for (int i = 0; i < size; i++)
					 {
    	            cout << "Enter Array elements for arry["<<i<<"] = "<<endl;
                    cin >> arr[i];
                    }
                    PassArry_as_argument(arr, size);
                break;
			}
                    
            case '9':
                cout << "Playing game using random function for dice"<<endl;
                playDiceGame();
                break;
            
            default:
                cout << "Invalid choice. Please try again."<<endl;
                break;
        }

        cout << endl;

			
		}else if(choice1 == '2')
		{
		group_members();
		}else if(choice1 == '3')
		{
		cout<<"Exit....."<<endl;	
		}else{
		cout<<"Wrong Choice "<<endl;
		}
	}while(choice1 != '3');

    


    return 0;
}
