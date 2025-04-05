#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FoodItem {
    string name;
    int calories;
    int nutrient_value;
};

// Function to compare items by their nutrient value per calorie
bool compareByNutrientValuePerCalorie(const FoodItem &a, const FoodItem &b) {
    return (a.nutrient_value * 1.0 / a.calories) > (b.nutrient_value * 1.0 / b.calories);
}

// Function to optimize food selection within calorie limits
vector<FoodItem> calorie_optimizer(vector<FoodItem> &food_items, int calorie_limit) {
    sort(food_items.begin(), food_items.end(), compareByNutrientValuePerCalorie);

    vector<FoodItem> selected_items;
    int total_calories = 0;

    for (const auto &item : food_items) {
        if (total_calories + item.calories <= calorie_limit) {
            selected_items.push_back(item);
            total_calories += item.calories;
        }
    }

    return selected_items;
}

int main() {
    vector<FoodItem> foods = {
        {"Chicken Breast", 165, 25},
        {"Brown Rice", 215, 5},
        {"Broccoli", 55, 3},
        {"Salmon", 208, 22},
        {"Almonds", 575, 20},
        {"Egg", 78, 6},
        {"Apple", 95, 2}
    };

    int limit;
    cout << "Enter your calorie limit: ";
    cin >> limit;

    vector<FoodItem> result = calorie_optimizer(foods, limit);

    cout << "\nSelected Food Items:\n";
    if (result.empty()) {
        cout << "No food items fit within the given calorie limit.\n";
    } else {
        for (const auto &item : result) {
            cout << item.name << " - Calories: " << item.calories
                 << ", Nutrient Value: " << item.nutrient_value << endl;
        }
    }

    return 0;
}