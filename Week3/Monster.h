#ifndef OOP_CLASS_MONSTER_H
#define OOP_CLASS_MONSTER_H
#include <string>
#include <iostream>

class Monster {
private:
    std::string name;
    int health;
    bool is_alive;
public:
    Monster() {
        name = "Terror Beast";
        health = 100;
        is_alive = true;
    }
    Monster(std::string name) {
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
    int claw_attack() {
        std::cout << name << " slashes with its claws!";
        return 8;
    }
    int bite_attack() {
        std::cout << name << " bites ferociously!";
        return 12;
    }
    int roar_attack() {
        std::cout << name << " unleashes a terrifying roar!!";
        return 15;
    }
    int heal() {
        int points = rand() % 11 + 10;
        std::cout << name << " regains " << points << " health points!!";
        return points;
    }
};

#endif