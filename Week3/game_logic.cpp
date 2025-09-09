#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Knight.h"
#include "Monster.h"
using namespace std;

void knight_turn(Knight &player, Monster &opponent) {
    int attack = rand() % 4 + 1;
    int damage;
    switch (attack) {
        case 1:
            damage = player.shield_strike();
            cout << player.getName() << " uses Shield Strike for " << damage << " damage!" << endl;
            break;
        case 2:
            damage = player.sword_attack();
            cout << player.getName() << " uses Sword Attack for " << damage << " damage!" << endl;
            break;
        case 3:
            damage = player.basic_attack();
            cout << player.getName() << " uses Basic Attack for " << damage << " damage!" << endl;
            break;
        case 4:
            damage = player.heavy_attack();
            cout << player.getName() << " uses Heavy Attack for " << damage << " damage!" << endl;
            break;
    }
    int newHealth = opponent.getHealth() - damage;
    if (newHealth < 0) newHealth = 0;
    opponent.setHealth(newHealth);
}

void monster_turn(Monster &opponent, Knight &player) {
    int action = rand() % 4 + 1;
    int value;
    switch (action) {
        case 1:
            value = opponent.claw_attack();
            cout << opponent.getName() << " slashes with its claws for " << value << " damage!" << endl;
            player.setHealth(player.getHealth() - value);
            break;
        case 2:
            value = opponent.bite_attack();
            cout << opponent.getName() << " bites ferociously for " << value << " damage!" << endl;
            player.setHealth(player.getHealth() - value);
            break;
        case 3:
            value = opponent.roar_attack();
            cout << opponent.getName() << " unleashes a terrifying roar for " << value << " damage!" << endl;
            player.setHealth(player.getHealth() - value);
            break;
        case 4:
            value = opponent.heal();
            cout << opponent.getName() << " regains " << value << " health points!" << endl;
            int newHealth = opponent.getHealth() + value;
            if (newHealth > 100) newHealth = 100;
            opponent.setHealth(newHealth);
            break;
    }
    if (player.getHealth() <= 0) {
        player.setAlive(false);
    }
}

void startGame() {
    srand(time(0));
    string name;
    cout << "Enter your name: ";
    cin >> name;
    Knight player(name);
    Monster opponent;

    cout << "Battle begins between " << player.getName() << " and " << opponent.getName() << "!" << endl;

    while (player.getAlive() && opponent.getAlive()) {
        // Knight's turn
        knight_turn(player, opponent);
        cout << player.getName() << " health: " << player.getHealth() << endl;
        cout << opponent.getName() << " health: " << opponent.getHealth() << endl;

        if (!opponent.getAlive()) {
            cout << player.getName() << " has defeated " << opponent.getName() << "!" << endl;
            break;
        }

        // Monster's turn
        monster_turn(opponent, player);
        cout << player.getName() << " health: " << player.getHealth() << endl;
        cout << opponent.getName() << " health: " << opponent.getHealth() << endl;

        if (!player.getAlive()) {
            cout << opponent.getName() << " has defeated " << player.getName() << "!" << endl;
            break;
        }

        cout << "------------------------" << endl;
    }
}