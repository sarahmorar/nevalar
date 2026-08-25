/* 


+---------------------------------------------------------------------+
|    N   N    EEEEE    V     V    AAAAA    L        AAAAA    RRRR     |
|    NN  N    E        V     V    A   A    L        A   A    R  R     |
|    N N N    EEE       V   V     AAAAA    L        AAAAA    RRR      |
|    N  NN    E          V V      A   A    L        A   A    R  R     |
|    N   N    EEEEE       V       A   A    LLLLL    A   A    R   R    |
+---------------------------------------------------------------------+



Nevalar 
v.0.1.1-alpha
by Sarah Morar

Last update: 25 Aug 2026, 1:32 AM EDT

*************************************************
Github: https://www.github.com/sarahmorar/nevalar
my LinkedIn: https://www.linkedin.com/in/sarahmorar
*************************************************

Welcome to the world of Nevalar, traveler.

This program is a C++ text adventure. The program demonstrates my knowledge of C++ conditionals, logic, and loops, and more.
*/

// Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

// Player Menu Functions

    // Function to display player inventory
    void showInventory(std::string weapons[], int weaponCount, std::string potions[], int potionCount) {
        std::cout << "\n--- Inventory ---\n";

        std::cout << "Weapons:\n";
        for (int i = 0; i < weaponCount; i++) {
            std::cout << "- " << weapons[i] << "\n";
        }
        std::cout << "Potions: n";
        for (int i= 0; i < potionCount; i++) {
            std::cout << "- " << potions[i] << "\n"; // Display health potions based on the count.
        }
        std::cout << "Map of Nevalar\n";

        std::cout << "-----------------\n\n";
    }

    // Function to display player stats
    void showStats(
        std::string name, 
        std::string playerClass, 
        int level,
        int experience, 
        int xpNeeded, 
        int health,
        int mana, 
        int maxMana,
        int strength, 
        int agility, 
        int intelligence,
        int wisdom,
        int charisma,
        int constitution){
        std::cout << "\n--- Player Stats ---\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Class: " << playerClass << "\n";
        std::cout << "Level: " << level << "\n";
        std::cout << "XP: " << experience << "/" << xpNeeded << "\n";
        std::cout << "--------------------\n";
        std::cout << "Health: " << health << "/100\n";
        std::cout << "Mana: " << mana << "/" << maxMana << "\n";
        std::cout << "--------------------\n";
        std::cout << "Strength: " << strength << "\n";
        std::cout << "Agility: " << agility << "\n";
        std::cout << "Intelligence: " << intelligence << "\n";
        std::cout << "Wisdom: " << wisdom << "\n";
        std::cout << "Charisma: " << charisma << "\n";
        std::cout << "Constitution: " << constitution << "\n";
        std::cout << "--------------------\n";
    }

    // Function to display player gold
    void showGold(int gold) {

        std::cout << "\n--- Money Bag ---\n";
        std::cout << "Gold: " << gold << "\n";
        std::cout << "-----------------\n\n";
    }

    // Level up function
    void levelUp(int &level, int &maxMana, int &mana, int manaGrowth) {
    level++;
    maxMana += manaGrowth;
    mana = maxMana;

    std::cout << "\n*** LEVEL UP! ***\n";
    std::cout << "You are now level " << level << "!\n";
    std::cout << "Maximum mana increased to " << maxMana << ".\n\n";
}

    // Using a potion function
    void usePotion(int &health, int &healthPotions) {
        if (healthPotions <= 0) {
            std::cout << "You don't have any potions.\n"; 
            return;
        }
            if (health >= 100) {
                std::cout << "Your health is already full. You cannot use a Health Potion right now.\n";
                return;
            }

            health += 25;

            if (health > 100) {
                health = 100; // Cap health at 100.
            }

            healthPotions--; // Decrease the number of health potions.

            std::cout << "You used a Health Potion.\n";
            std::cout << "Your health is now " << health << ".\n";
            std::cout << "Health Potions remaining: " << healthPotions << ".\n";
    }

    // Function to use an item from the inventory
    void useItem(std::string item, int &health, int &healthPotions) {
        if (item == "potion") {
            usePotion(health, healthPotions);
        } 
        else if (item == "sword") {
            std::cout << "You ready your sword.\n";
        } 
        else if (item == "bow") {
            std::cout << "You ready your bow.\n";
        } 
        else if (item == "dagger") {
            std::cout << "You ready your dagger.\n";
        } 
        else {
            std::cout << "You don't have that item in your inventory.\n";
        }
    }

    // Function to pause the program until the user presses Enter
    void pressEnter() {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

int main(){

    srand(time(NULL)); // Seed the random number generator for randomization.

    // Player variables
    std::string name;
    std::string playerClass; 
    int userClass = 0; // Initialize userClass to 0 to ensure the while loop runs at least once.
    
    std::string command; // Variable to store user commands.

    int level = 1; // Starting level for the player.
    int experience = 0; // Starting experience points for the player.
    int xpNeeded = 100; // Experience points needed to level up.
    

    int health = 100; // Starting health for the player.

    int mana = 0; // Starting mana for the player.
    int maxMana = 0; // Maximum mana for the player, will be set based on class.
    int manaGrowth = 0; // Mana growth per level, will be set based on class.
    

    int strength = 0;
    int agility = 0;
    int intelligence = 0;
    int charisma = 0;
    int wisdom = 0;
    int constitution = 0;

    // Inventory
    std::string weapons[] = {
        "Iron Sword", 
        "Arcane Bow", 
        "Dagger"
    }; // Weapons available to the player.
    int weaponCount = 3; // Number of weapons in the inventory.

    std::string potions[] = {
        "Health Potion (Restores 50 HP)", 
        "Mana Potion (Restores 30 MP)", 
        "Stamina Potion (Restores 20 SP)"
    }; // Potions available to the player.
    int potionCount = 5; // Starting health potions for the player.

    int gold = 200; // Starting gold for the player.

    // Tavern variables
    int mealChoice = 0;
    int dailySpecial = 0;
    std::string dish_of_the_day;
    

    // Adventure start. Prompt for user name.
    std::cout << "\n\nWelcome to the land of Nevalar, traveler. What's your name?\n\n";
    std::cin >> name;

    // Prompt for user role/class.
    std::cout << "\nWell met, " << name <<". In Nevalar, adventurers such as yourself tend to fall in one of nine categories.\n\n";

    // Conditional statements to determine user role/class.
    while (userClass < 1 || userClass > 9) {
        // Prompt user to choose a class.
        std::cout << "Choose your path: \n";
        std::cout << "1. Warrior   2. Ranger   3. Rogue   4. Wizard\n";
        std::cout << "5. Cleric   6. Bard   7. Paladin   8. Druid   9. Monk\n\n";

        std::cin >> userClass; {// Get user input for class selection. Output class and brief description based on selection.
            if (userClass == 1){
                playerClass = "Warrior";
                mana = 20; // Starting mana for Warrior class.
                maxMana = 20; // Set maximum mana for Warrior class.
                manaGrowth = 5; // Set mana growth per level for Warrior class.

                std::cout << "\nAh, a Warrior! You are strong and brave, ready to face any foe.\n\n";
            } 
            else if (userClass == 2){
                playerClass = "Ranger";
                mana = 40; // Starting mana for Ranger class.
                maxMana = 40; // Set maximum mana for Ranger class.
                manaGrowth = 7; // Set mana growth per level for Ranger class.

                std::cout << "\nA Ranger! You are skilled in the ways of the wild, able to track and hunt with ease.\n\n";
            } 
            else if (userClass == 3){
                playerClass = "Rogue";
                mana = 25; // Starting mana for Rogue class.
                maxMana = 25; // Set maximum mana for Rogue class.
                manaGrowth = 5; // Set mana growth per level for Rogue class.

                std::cout << "\nA Rogue! You are cunning and stealthy, able to slip past enemies unnoticed.\n\n";
            } 
            else if (userClass == 4){
                playerClass = "Wizard";
                mana = 100; // Starting mana for Wizard class.
                maxMana = 100; // Set maximum mana for Wizard class.
                manaGrowth = 15; // Set mana growth per level for Wizard class.

                std::cout << "\nA Wizard! You are wise and powerful, able to wield magic to your advantage.\n\n";
            } 
            else if (userClass == 5){
                playerClass = "Cleric";
                mana = 85; // Starting mana for Cleric class.
                maxMana = 85; // Set maximum mana for Cleric class.
                manaGrowth = 12; // Set mana growth per level for Cleric class.

                std::cout << "\nA Cleric! You are devoted and compassionate, able to heal and protect your allies.\n\n";
            } 
            else if (userClass == 6){
                playerClass = "Bard";
                mana = 60; // Starting mana for Bard class.
                maxMana = 60; // Set maximum mana for Bard class.
                manaGrowth = 10; // Set mana growth per level for Bard class.

                std::cout << "\nA Bard! You are charming and charismatic, able to inspire and entertain those around you.\n\n";
            } 
            else if (userClass == 7){
                playerClass = "Paladin";
                mana = 55; // Starting mana for Paladin class.
                maxMana = 55; // Set maximum mana for Paladin class.
                manaGrowth = 8; // Set mana growth per level for Paladin class.

                std::cout << "\nA Paladin! You are noble and righteous, able to smite evil and uphold justice.\n\n";
            } 
            else if (userClass == 8){
                playerClass = "Druid";
                mana = 90; // Starting mana for Druid class.
                maxMana = 90; // Set maximum mana for Druid class.
                manaGrowth = 13; // Set mana growth per level for Druid class.

                std::cout << "\nA Druid! You are attuned to nature, able to shape-shift and command the forces of the wild.\n\n";
            } 
            else if (userClass == 9){
                playerClass = "Monk";
                mana = 45; // Starting mana for Monk class.
                maxMana = 45; // Set maximum mana for Monk class.
                manaGrowth = 7; // Set mana growth per level for Monk class.

                std::cout << "\nA Monk! You are disciplined and focused, able to harness your inner strength and martial arts skills.\n\n";
            } 
            else {
            std::cout << "I'm sorry, " << name <<", but that is not a valid class. Please choose a number between 1 and 9.\n\n";
            }
            // Randomly generate player stats
            strength = rand() % 11 + 8;
            agility = rand() % 11 + 8;
            intelligence = rand() % 11 + 8;
            wisdom = rand() % 11 + 8;
            charisma = rand() % 11 + 8;
            constitution = rand() % 11 + 8;
            
            // Apply class stat bonuses
            if (playerClass == "Warrior") {
                strength += 2;
                constitution += 2;
            }
            else if (playerClass == "Ranger") {
                agility += 2;
                wisdom += 2;
            }
            else if (playerClass == "Rogue") {
                agility += 2;
                charisma += 1;
            }
            else if (playerClass == "Wizard") {
                intelligence += 2;
                wisdom += 1;
            }
            else if (playerClass == "Cleric") {
                wisdom += 2;
                constitution += 1;
            }
            else if (playerClass == "Bard") {
                charisma += 2;
                agility += 1;
            }
            else if (playerClass == "Paladin") {
                strength += 2;
                charisma += 1;
            }
            else if (playerClass == "Druid") {
                wisdom += 2;
                intelligence += 1;
            }
            else if (playerClass == "Monk") {
            agility += 2;
            wisdom += 1;
        }
        }
    }
        std::cout << "\nYou have chosen your path, " << name << ".\n";
        
        std::cout << "\nYour starting stats are as follows:\n"; {
        showStats(
            name,
            playerClass,
            level,
            experience,
            xpNeeded,
            health,
            mana,
            maxMana,
            strength,
            agility,
            intelligence,
            wisdom,
            charisma,
            constitution
        );
    }
    pressEnter();
    
    std::cout << "\nUse the following commands to check your stats, inventory, and more:\n\n";
    std::cout << "inventory - Displays weapons, potions, and other carried items\n";
    std::cout << "gold - Displays current gold\n";
    std::cout << "stats - Displays name, class, level/XP, health, mana, and attributes\n";
    std::cout << "use - Use/equip an item, such as a potion or weapon\n";
    std::cout << "\nMay your journey in Nevalar be filled with adventure and glory!\n\n";

    pressEnter();
   
    // Begin adventure narrative.
    std::cout << "+----------------------------------------------+\n";
    std::cout << "|     DDD      AAAAA     Y     Y          1    |\n";
    std::cout << "|     D  D     A   A      Y   Y          11    |\n";
    std::cout << "|     D   D    AAAAA       Y Y            1    |\n";
    std::cout << "|     D  D     A   A        Y             1    |\n";
    std::cout << "|     DDD      A   A        Y             1    |\n";
    std::cout << "+----------------------------------------------+\n\n\n";  

    std::cout << "This story begins as most do. After all, you are no different than any other adventurer in Nevalar.\n";
    std::cout << "After collecting your last commission pay from the adventurer's guild, you find that your purse is full of gold, but your stomach is empty.\n";
    std::cout << "You decide to head to the local tavern, The Rusty Dagger, to find a warm meal and a place to rest your weary bones.\n\n";

    pressEnter();

    std::cout << "As you enter the tavern, the smell of roasted meat and ale fills your senses. The tavern is bustling with activity, filled with adventurers and townsfolk alike.\n";
    std::cout << "'Welcome, traveler!' the barkeep greets you. 'What can I get for you today?'\n";
    std::cout << "You check your coin purse. You have " << gold << " gold.\n\n";

    // Prompt user for their choice of meal.
    std::cout << "You have a few options for your meal. What would you like to order?\n\n";
    std::cout << "+-----------------------------+\n";
    std::cout << "1. A hearty stew (10 gold)\n";
    std::cout << "2. A roasted chicken (15 gold)\n";
    std::cout << "3. A plate of fresh vegetables (5 gold)\n";
    std::cout << "4. A pint of ale (3 gold)\n";
    std::cout << "5. Ask for the daily special (price varies)\n";
    std::cout << "6. Exit the tavern without ordering (0 gold)\n";
    std::cout << "+-----------------------------+\n\n";

    // Loop to ensure valid meal choice input.
    while (mealChoice < 1 || mealChoice > 6) {
        std::cin >> command; // Get user input for meal selection.

        if (command == "inventory") {
            showInventory(weapons, weaponCount, potions, potionCount); // Show inventory if user types "inventory".
            continue; // Continue the loop to prompt for meal choice again.
        } else if (command == "stats") {
            showStats(
                name,
                playerClass,
                level,
                experience,
                health,
                mana,
                maxMana,
                strength,
                agility,
                intelligence,
                wisdom,
                charisma,
                constitution,
                gold
            ); // Show stats if user types "stats".
            continue; // Continue the loop to prompt for meal choice again.
        } else if (command == "gold") {
            showGold(gold); // Show gold if user types "gold".
            continue; // Continue the loop to prompt for meal choice again.
        } else if (command == "use") {
            std::string item;
            
            std::cout << "Use what?\n\n";
            std::cin >> item;
            useItem(item, health, potionCount); // Use item if user types "use".
            continue; // Continue the loop to prompt for meal choice again.
        } else if (command == "1"){
            std::cout << "You order the hearty stew. The barkeep serves you a steaming bowl of stew, filled with tender meat and vegetables. You savor each bite, feeling your strength return.\n";
            gold -= 10; // Deduct the cost of the stew from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n\n";
        } else if (command == "2"){
            std::cout << "You order the roasted chicken. The barkeep serves you a succulent roasted chicken, seasoned to perfection. You enjoy the meal, feeling satisfied and content.\n";
            gold -= 15; // Deduct the cost of the chicken from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n\n";
        } else if (command == "3"){
            std::cout << "You order the plate of fresh vegetables. The barkeep serves you a colorful plate of fresh vegetables, crisp and flavorful. You feel refreshed and energized after your meal.\n";
            gold -= 5; // Deduct the cost of the vegetables from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n\n";
        } else if (command == "4"){
            std::cout << "You order a pint of ale. The barkeep serves you a frothy pint of ale, rich and flavorful. You take a sip, feeling the warmth spread through your body.\n";
            gold -= 3; // Deduct the cost of the ale from the player's gold.
            std::cout << "You have " << gold << " gold remaining.\n\n";
        } else if (command == "5"){
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
            std::cout << "You have " << gold << " gold remaining.\n\n";
        } else if (command == "6"){
            std::cout << "You decide to exit the tavern without ordering. The barkeep nods in understanding, and you step back into the bustling streets of Nevalar, ready for your next adventure.\n\n";
        } else {
            std::cout << "'What?' the barkeep asks, looking at you with confusion. 'Come, now, traveler. I'm sure I've got something that will suit your taste.\n";
            std::cout << "I'm sorry, " << name << ", but that is not a valid meal choice. Please choose a number between 1 and 6.\n\n";
        }
    }


        return 0; // End of the program.
}
