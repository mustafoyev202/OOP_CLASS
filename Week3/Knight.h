#ifndef OOP_CLASS_KNIGHT_H
#define OOP_CLASS_KNIGHT_H
#include <string>
#include <iostream>

class Knight {
private:
    std::string name;
    int health;
    bool is_alive;
public:
    Knight() {
        name = "Unknown";
        health = 100;
        is_alive = true;
    }
    Knight(std::string name) {
        this->name = name;
        health = 100;
        is_alive = true;
    }
    std::string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    bool getAlive() {
        return is_alive;
    }
    void setName(std::string name) {
        this->name = name;
    }
    void setHealth(int health) {
        this->health = health;
        if (this->health <= 0) {
            this->is_alive = false;
        }
        if (this->health > 100) {
            this->health = 100;
        }
    }
    void setAlive(bool is_alive) {
        this->is_alive = is_alive;
    }
    int shield_strike() {
        std::cout << name << " uses Shield Strike!!!";
        return 5;
    }
    int basic_attack() {
        std::cout << name << " attacks with Basic Attack!";
        return 10;
    }
    int sword_attack() {
        std::cout << name << " swings their Sword!";
        return 15;
    }
    int heavy_attack() {
        std::cout << name << " unleashes Heavy Attack!";
        return 20;
    }
    int heal() {
        int points = rand() % 16 + 5;
        std::cout << name << " heals for " << points << " health points!";
        return points;
    }
};
#endif