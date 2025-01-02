#include <iostream>


class Entity {
protected:
    std::string name;
    int level;
    double damage;
    double hp;
public:
    
    Entity(std::string n, int l, double d, double h) : name(n), level(l), damage(d), hp(h) {} // default constructor
    Entity() : name("NONAME"), level(1), damage(1), hp(1) {} // no-args constructor
    
    double show_hp() {
        std::cout << "Entity hp: " << this->hp << std::endl;
        return this->hp;
    }
    double show_damage() {
        std::cout << "Entity damage: " << this->damage << std::endl;
        return this->damage;
    }
    
    void level_up() {
        this->level += 1;
    }
};

class Player : public Entity {
protected:
    std::string email;
    std::string pw;
public:
    double show_hp() {
        std::cout << "Player hp: " << this->hp << std::endl;
        return this->hp;
    }
    
    double show_damage() {
        std::cout << "Player damage: " << this->damage << std::endl;
        return this->damage;
    }
    
    void level_up() {
        Entity::level_up();
        std::cout << "Congratulations! You just leveled up to level " << this->level << "!" << std::endl;
    }
};

int main() {
    
    //What is meant by member function inheritance?
    // The derived classes having access to the public members of the base class
    
    //• Write a simple program with a child class that inherits a member function from its parent
    Player player;
    player.show_hp();
    player.show_damage();
    
    //• Write a simple program with a child class that reimplements a member function from the parent class
    // reimplementation done inside the Player class definition
    
    //• Write a simple program with a child class that extends a member function from its parent class
    player.level_up();
    
    //What does it mean to have protected access to a member function?
    // derived classes can access the protected members of their "base class part". they cannot access the private part.
    
    //Write a simple program that uses the protected keyword
    // Above
    
	return 0;
}
