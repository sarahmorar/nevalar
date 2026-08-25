/* 
+---------------------------------------------------------------------+
|    N   N    EEEEE    V     V    AAAAA    L        AAAAA    RRRR     |
|    NN  N    E        V     V    A   A    L        A   A    R  R     |
|    N N N    EEE       V   V     AAAAA    L        AAAAA    RRR      |
|    N  NN    E          V V      A   A    L        A   A    R  R     |
|    N   N    EEEEE       V       A   A    LLLLL    A   A    R   R    |
+---------------------------------------------------------------------+

Nevalar v.0.1.0-alpha
by Sarah Morar
github: https://www.github.com/sarahmorar/nevalar

Welcome to the world of Nevalar, traveler.

This program is a C++ text adventure. The program demonstrates my knowledge of C++ conditionals, logic, and loops, and more.
*/

// Libraries
#include <iostream>
#include <string>

// Player Menus
    // Display Player Inventory
    void showInventory(std::string weapons, int healthPotions) {
        std::cout << "\n--- Inventory ---\n";
        std::cout << "Weapons: " << weapons << "\n";
        std::cout << "Health Potion: " << healthPotions << "\n";
        std::cout << "Map of Nevalar\n";
        std::cout << "-----------------\n\n";
    }

    // Display Player Stats
    void showStats(std::string name, std::string playerClass = "Unknown") {
        std::cout << "\n--- Player Stats ---\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Class: " << playerClass << "\n";
        std::cout << "Health: 100\n";
        std::cout << "Strength: 15\n";
        std::cout << "Agility: 12\n";
        std::cout << "Intelligence: 14\n";
        std::cout << "--------------------\n\n";
    }

    // Display Player Gold
    void showGold(int gold) {
        std::cout << "\n--- Money Bag ---\n";
        std::cout << "Gold: " << gold << "\n";
        std::cout << "-----------------\n\n";
    }

int main(){

    // Declare variables
    std::string name;
    std::string playerClass; 
    int userClass = 0; // Initialize userClass to 0 to ensure the while loop runs at least once.

    // Declare inventory, stats, and gold variables.
    std::string weapons = "Sword, Bow, Dagger"; // Example inventory items.
    int healthPotions = 5; // Starting health potions for the player.
    int gold = 200; // Starting gold for the player.

    // Declare variables for meal choice and daily special.
    int mealChoice = 0;
    int dailySpecial = 0;
    std::string dish_of_the_day;
    

    // Adventure start. Prompt for user name.
    std::cout << "Welcome to the land of Nevalar, traveler. What's your name?\n";
    std::cin >> name;

    // Prompt for user role/class.
    std::cout << "Well met, " << name <<". In Nevalar, adventurers such as yourself tend to fall in one of nine categories.\n\n";

    // Conditional statements to determine user role/class.
    while (userClass < 1 || userClass > 9) {
        // Prompt user to choose a class.
        std::cout << "Choose your path: \n";
        std::cout << "1. Warrior   2. Ranger   3. Rogue   4. Wizard\n";
        std::cout << "5. Cleric   6. Bard   7. Paladin   8. Druid   9. Monk\n";

        std::cin >> userClass; // Get user input for class selection.

        // Output the chosen class and a brief description.
        if (userClass == 1){
            playerClass = "Warrior";
            std::cout << "Ah, a Warrior! You are strong and brave, ready to face any foe.\n";
        } else if (userClass == 2){
            playerClass = "Ranger";
            std::cout << "A Ranger! You are skilled in the ways of the wild, able to track and hunt with ease.\n";
        } else if (userClass == 3){
            playerClass = "Rogue";
            std::cout << "A Rogue! You are cunning and stealthy, able to slip past enemies unnoticed.\n";
        } else if (userClass == 4){
            playerClass = "Wizard";
            std::cout << "A Wizard! You are wise and powerful, able to wield magic to your advantage.\n";
        } else if (userClass == 5){
            playerClass = "Cleric";
            std::cout << "A Cleric! You are devoted and compassionate, able to heal and protect your allies.\n";
        } else if (userClass == 6){
            playerClass = "Bard";
            std::cout << "A Bard! You are charming and charismatic, able to inspire and entertain those around you.\n";
        } else if (userClass == 7){
            playerClass = "Paladin";
            std::cout << "A Paladin! You are noble and righteous, able to smite evil and uphold justice.\n";
        } else if (userClass == 8){
            playerClass = "Druid";
            std::cout << "A Druid! You are attuned to nature, able to shape-shift and command the forces of the wild.\n";
        } else if (userClass == 9){
            playerClass = "Monk";
            std::cout << "A Monk! You are disciplined and focused, able to harness your inner strength and martial arts skills.\n";
        } else {
            std::cout << "I'm sorry, " << name <<", but that is not a valid class. Please choose a number between 1 and 9.\n";
        }
    }

    // Final message to the user after class selection.
    std::cout << "You have chosen your path, " << name <<". May your journey in Nevalar be filled with adventure and glory!\n";
    std::cout << "*     *     *     *   *     *     *     *     *     *\n";

    // Begin adventure narrative.
    std::cout << "This story begins as most do. After all, you are no different than any other adventurer in Nevalar.\n";
    std::cout << "After collecting your last commission pay from the adventurer's guild, you find that your purse is full of gold, but your stomach is empty.\n";
    std::cout << "You decide to head to the local tavern, The Rusty Dagger, to find a warm meal and a place to rest your weary bones.\n\n";

    std::cout << "As you enter the tavern, the smell of roasted meat and ale fills your senses. The tavern is bustling with activity, filled with adventurers and townsfolk alike.\n";
    std::cout << "'Welcome, traveler!' the barkeep greets you. 'What can I get for you today?'\n";
    std::cout << "You check your coin purse. You have " << gold << " gold.\n\n";

    // Prompt user for their choice of meal.
    std::cout << "You have a few options for your meal. What would you like to order?\n";
    std::cout << "1. A hearty stew (10 gold)\n";
    std::cout << "2. A roasted chicken (15 gold)\n";
    std::cout << "3. A plate of fresh vegetables (5 gold)\n";
    std::cout << "4. A pint of ale (3 gold)\n";
    std::cout << "5. Ask for the daily special (price varies)\n";
    std::cout << "6. Exit the tavern without ordering (0 gold)\n";

    // Loop to ensure valid meal choice input.
    while (mealChoice < 1 || mealChoice > 6) {
        std::cin >> mealChoice; // Get user input for meal selection.

        // Logic to determine the meal choice and output the corresponding message.
        if (mealChoice == 1){
            std::cout << "You order the hearty stew. The barkeep serves you a steaming bowl of stew, filled with tender meat and vegetables. You savor each bite, feeling your strength return.\n";
            gold -= 10; // Deduct the cost of the stew from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n";
        } else if (mealChoice == 2){
            std::cout << "You order the roasted chicken. The barkeep serves you a succulent roasted chicken, seasoned to perfection. You enjoy the meal, feeling satisfied and content.\n";
            gold -= 15; // Deduct the cost of the chicken from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n";
        } else if (mealChoice == 3){
            std::cout << "You order the plate of fresh vegetables. The barkeep serves you a colorful plate of fresh vegetables, crisp and flavorful. You feel refreshed and energized after your meal.\n";
            gold -= 5; // Deduct the cost of the vegetables from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n";
        } else if (mealChoice == 4){
            std::cout << "You order a pint of ale. The barkeep serves you a frothy pint of ale, rich and flavorful. You take a sip, feeling the warmth spread through your body.\n";
            gold -= 3; // Deduct the cost of the ale from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n";
        } else if (mealChoice == 5){
            int dailySpecial = rand() % 3 + 1; // Randomly select a dish of the day (1-3).
                if (dailySpecial == 1){
                    dish_of_the_day = "a savory potato stew";
                    gold -= 10; // Deduct the cost of the daily special from the player's gold.
                } else if (dailySpecial == 2){
                    dish_of_the_day = "a delicious roasted lamb";
                    gold -= 12; // Deduct the cost of the daily special from the player's gold.
                } else {
                    dish_of_the_day = "a fresh seafood platter";
                    gold -= 28; // Deduct the cost of the daily special from the player's gold.
                }
            std::cout << "You ask for the daily special. The barkeep smiles and serves you the dish of the day, which turns out to be " << dish_of_the_day << ". You enjoy the meal, feeling satisfied and grateful for the barkeep's recommendation.\n";
            std::cout << "You have " << gold << " gold remaining.\n";
        } else if (mealChoice == 6){
            std::cout << "You decide to exit the tavern without ordering. The barkeep nods in understanding, and you step back into the bustling streets of Nevalar, ready for your next adventure.\n";
        } else {
            std::cout << "'What?' the barkeep asks, looking at you with confusion. 'Come, now, traveler. I'm sure I've got something that will suit your taste.\n";
            std::cout << "I'm sorry, " << name << ", but that is not a valid meal choice. Please choose a number between 1 and 6.\n";
        }
    }

    return 0; // End of the program.
}
