/** \file bugExample.cpp
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then commit
 *                   the code with a comment on the fix you did
 *                3) There are a four functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      20/10/2025
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;
const double VAT = 0.21;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[][2], const int);
void displayArray(const int[][2], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
bool avgOddArray(const int[], const int, double&);
void revertNumbers(int arr[], const int size);
/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
  int choice;
  const int SIZE = 10;
srand(time(NULL));
    
  // Initialize array price
    int price[SIZE];

    for (int i = 0; i < SIZE; ++i){
      price[i] = rand() % 41 + 10; // range 10–50
    }
  // Declare array quantity and total
    int quantity[SIZE] = {0}, total[SIZE][2] = {0};
    
  // Interactive menu
  do {
    choice = printMenu();

      switch (choice){
        // Enter quantity
        case 1:
          fillInArray(quantity, SIZE);
          break;
        // Calculate total
        case 2:
          multArrays(quantity, price, total, SIZE);
          break;
        // Print total
        case 3:
          displayArray(total, SIZE);
          break;
        // All positive
        case 4:
          if (isAllPositive(quantity, SIZE))
            cout << "\nAll elements of the array are positive";
          else
            cout << "\nAt-least one of the elements are not positive";
          break;
        // Sum odd numbers
        case 5:
          cout << "\nThe sum of odd numbers is: " << sumOddArray(quantity, SIZE);
          break;
        // Average odd numbers
        case 6: {
          double avgOdd;
          if (avgOddArray(quantity, SIZE, avgOdd))
            cout << "\nThe average of odd numbers is: " << avgOdd;
          else
            cout << "\nThere are no odd numbers in the array";
          break;
        }
        // Revert numbers
        case 7:
          revertNumbers(quantity, SIZE);
          cout << "\nThe array has been reverted.";
          break;
        // Exit
        case 0:
          // No code needed
          break;
        default:
          cout << "\nInvalid choice.";
      }
  } while (choice != 0);

  cout << "\nHave a nice day:)" << endl;
  return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu(){
  int choice;

  do {
      cout << "\n == MENU ==";
      cout << "\n1) Enter quantity";
      cout << "\n2) Calculate total";
      cout << "\n3) Print total";
      cout << "\n4) All positive";
      cout << "\n5) Sum odd numbers";
      cout << "\n6) Average odd numbers";
      cout << "\n7) Revert numbers";
      cout << "\n0) Exit";

    cout << "\nEnter the choice: ";
    cin >> choice;

      if (choice < 0 || choice > 7){
        cout << "\nWrong choice, try again.";
      }
      } while (choice < 0 || choice > 7);
  return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size){
  assert (size > 1);

  for (int i = 0; i < size; ++i){
    cout << "\nEnter an element for the array at " << i << ": ";
    cin >> arr[i];
  }
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrQuantity ...
 * @param arrPrice ...
 * @param arrTotal ...
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[][2], const int size){
  assert(size > 0);

  for (int i = 0; i < size; ++i){
    arrTotal[i][0] = arrQuantity[i] * arrPrice[i];
    arrTotal[i][1] = arrQuantity[i] * static_cast<int>(arrPrice[i] * (1 + VAT));
  }
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[][2], const int size){
  int sumNoVat = 0;
  int sumWithVat = 0;

  for (int i = 0; i < size; ++i){
      cout << "\nIndex " << i
           << " | Without VAT: " << arr[i][0]
           << " | With VAT: " << arr[i][1];
    sumNoVat += arr[i][0];
    sumWithVat += arr[i][1];
  }
  cout << "\nThe total without VAT is: " << sumNoVat;
  cout << "\nThe total with VAT is: " << sumWithVat;
}

/**
 * <code>sumOddArray</code> sums all the odd numbers in the array.
 * <BR>
 * @param arr The array containing the values.
 * @param size The size of the array.
 * @return The sum of all odd elements in the array.
 */
int sumOddArray(const int arr[], const int size){
  assert(size > 0);

  int sum = 0;

  for (int i = 0; i < size; ++i){
    if (arr[i] % 2 != 0){
      sum += arr[i];
    }
  }

  return sum;
}

/**
 * <code>isAllPositive</code> checks whether all elements in the array are positive.
 * <BR>
 * @param arr The array containing the values.
 * @param size The size of the array.
 * @return Returns true if all elements are positive, false otherwise.
 */
bool isAllPositive(const int arr[], const int size){
    assert (size>0);
    bool ret = true;
    for (int i=0; i<size; i++){
        if (arr[i]<1){
            ret = false;
            break;
        }
    }
    
    
    return ret;
}
    
/**
 * <code>avgOddArray</code> finds the average of all odd numbers in the array.
 * <BR>
 * @param arr The array containing the values.
 * @param size The size of the array.
 * @param avgOdd The average of all odd numbers in the array.
 * @return Returns true if the array contains odd numbers, false otherwise.
 */
bool avgOddArray(const int arr[], const int size, double& avgOdd){
  assert(size > 0);

  int sum = 0;
  int count = 0;

  for (int i = 0; i < size; ++i){
    if (arr[i] % 2 != 0){
      sum += arr[i];
      ++count;
    }
  }

  if (count == 0){
    return false;
  }

  avgOdd = static_cast<double>(sum) / count;
  return true;
}

/**
 * <code>revertNumbers</code> reverses the elements of the array in place.
 * <BR>
 * @param arr The array to be reversed.
 * @param size The size of the array.
 */
void revertNumbers(int arr[], const int size) {
  assert(size > 0);

  for (int i = 0; i < size / 2; ++i){
    int temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
  }
}

