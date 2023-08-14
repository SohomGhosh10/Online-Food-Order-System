#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Declare the food items
const vector<string> foodItems = {
  "Pizza",
  "Burger",
  "Biryani",
  "Chicken Tikka Masala",
  "Idli Doosa",
};

// Declare the prices of the food items
const vector<int> foodPrices = {
  150,
  50,
  275,
  150,
  100,
};

// Define the User class
class User {
public:
  string email;
  string password;
  string otp;

  User(string email, string password) {
    this->email = email;
    this->password = password;
    this->otp = "";
  }

  bool isLoggedIn() {
    return this->otp != "";
  }

  void sendOTP() {
    this->otp = "123456";
  }

  bool verifyOTP(string otp) {
    return this->otp == otp;
  }

  void regenerateOTP() {
    this->otp = "123456";
    cout << "Your OTP has been regenerated. Please check your email." << endl;
  }
};

int main() {
  // Create a user
  User user("johndoe@example.com", "password");

  // Check if the user is logged in
  if (!user.isLoggedIn()) {
    // Send the user an OTP
    user.sendOTP();

    // Ask the user to enter the OTP
    cout << "Please enter your OTP: ";
    string otp;
    cin >> otp;

    // Verify the OTP
    if (!user.verifyOTP(otp)) {
      cout << "The OTP is incorrect. Please try again." << endl;

      // If the OTP is incorrect, regenerate the OTP and ask the user to verify their email id again
      cout << "Would you like to regenerate the OTP? (y/n): ";
      char choice;
      cin >> choice;

      if (choice == 'y') {
        user.regenerateOTP();
      }
    }
  }

  // Show the food items
  cout << "Here are the food items available: " << endl;
  for (int i = 0; i < foodItems.size(); i++) {
    cout << i + 1 << ". " << foodItems[i] << " -" << foodPrices[i] << "INR" << endl;
  }

  // Let the user select some food items
  int foodIndex;
  cout << "Please select your food items (enter the numbers): ";
  cin >> foodIndex;

  // Calculate the total price of the food items
  int totalPrice = foodPrices[foodIndex - 1];

  // Ask the user if they want to confirm the order
  cout << "The total price of your order is $" << totalPrice << endl;
  cout << "Do you want to confirm your order? (y/n): ";
  char confirm;
  cin >> confirm;

  // If the user confirms the order, print a receipt
  if (confirm == 'y') {
    cout << "Thank you for your order! Here is your receipt: " << endl;
    cout << "Food items: " << foodItems[foodIndex - 1] << endl;
    cout << "Price: $" << totalPrice << endl;
  }

  return 0;
}