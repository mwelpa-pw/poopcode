#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class NoManaException : std::exception{
    public:
        const char* what() const noexcept override {
            return "No Mana";
        }
};

class Character
{
    public:
        Character(int max_health=100, std::string name="Twoja stara") : maxHealth(max_health), name(name), health(max_health) {}
    private:
        std::string name;
        int health;
        int maxHealth;

    public:
        int getHealth() const
        {
            return health;
        }

        std::string getName() const
        {
            return name;
        }

        bool isAlive() const
        {
            return health > 0;
        }

        void takeDamage(int damage)
        {
            health -= damage;
        }

        void heal(int g_health)
        {
            health += g_health;
        }

        virtual void attack(Character* target) = 0;
        virtual ~Character() = 0;

};

class CanUseMelee {
    public:
        virtual void performMeleeAttack(Character* target) = 0;
        virtual ~CanUseMelee() = 0;
};

class CanCastSpells
{
    protected:
        int mana;
        int maxMana;

    public:
        CanCastSpells(int initialMana = 100) : mana(initialMana), maxMana(initialMana) {}
        int getMana() {
            return mana;
        }

        void addMana(int amount) {
            mana += amount;
            mana -= (mana - maxMana);
        }

        void useMana(int amount) {
            if (mana - amount < 0) {
                throw NoManaException();
            }

            mana -= amount;
        }

        virtual void castSpell(Character* target) = 0;
        virtual ~CanCastSpells() = 0;
};

class Warrior : public Character, public CanUseMelee
{
    private:
        int meleeDamage;

    public:
        Warrior(const std::string& name, int health = 120, int damage = 15)
        : Character(health, name), CanUseMelee(), meleeDamage(damage) {}

        void performMeleeAttack(Character* person) override
        {
            person->takeDamage(meleeDamage);
        }

        void attack(Character* target) {
            performMeleeAttack(target);
        }
};

class Mage : public Character, public CanCastSpells
{
    private:
        int spellDamage;
        int mana;

    public:
    Mage(const std::string& name, int health = 80, int mana = 150, int damage = 20)
    : Character(health, name), CanCastSpells(mana), spellDamage(damage) {}

        void castSpell(Character* person) override
        {
            int damageDealt = spellDamage;
            const std::type_info& type = typeid(*person);
            if (type == typeid(Warrior) || type == typeid(CanUseMelee)) {
                damageDealt += 10;
            }
            person->takeDamage(damageDealt);
            useMana(10);
        }

        void attack(Character* target) {
            try {
                castSpell(target);
            } catch (const NoManaException& e) {
                std::cerr << e.what() << std::endl;
            }
        }
};

class BattleMage : public Character, public CanCastSpells, public CanUseMelee {
    public:
        int mdmg;
        int sdmg;
        int backstabDamage = 30;
        BattleMage(std::string name, int health=100, int mana=100, int meleeDmg=10, int spellDmg=15) : Character(100, name), sdmg(spellDmg), mdmg(meleeDmg) {};

        void attack(Character* target) override {
            srand(time(NULL));
            const int randomBit = rand() % 2;
            const std::type_info& type = typeid(*target);
            if (randomBit) {
                castSpell(target);
            } else {
                performMeleeAttack(target);
            }
        }

        void backstab(Character* target) {
            if (typeid(*target) != typeid(Mage) && typeid(*target) != typeid(BattleMage) &&
                dynamic_cast<CanCastSpells*>(target) == nullptr)
            {
                int damageDealt = backstabDamage;
                std::cout  << " successfully backstabs " << target->getName() << " for " << damageDealt
                        << " massive damage!" << std::endl;
                target->takeDamage(damageDealt);
            }
            else
            {
                std::cout << "'s backstab failed against a magic-user!" << std::endl;
            }
        }

        void castSpell(Character* target) {
            useMana(8);
            target->takeDamage(sdmg);
        }

        void performMeleeAttack(Character* person) {
            person->takeDamage(sdmg);
        }
};

class Rogue : public Character, public CanUseMelee {
    int basicAttackDamage;
    int backstabDamage;

    public:
        Rogue(const std::string& name, int health=90, int basicDmg=12, int backstabDmg=90) : Character(100, name), basicAttackDamage(basicDmg), backstabDamage(backstabDmg) {};

        void backstab(Character* target)
        {
            if (!target || !target->isAlive())
            {
                std::cout<< " tries to backstab but the target is invalid or already defeated." << std::endl;
                return;
            }
        
            std::cout << " attempts a backstab on " << target->getName() << "." << std::endl;
        
            if (typeid(*target) != typeid(Mage) && typeid(*target) != typeid(BattleMage) &&
                dynamic_cast<CanCastSpells*>(target) == nullptr)
            {
                int damageDealt = backstabDamage;
                std::cout  << " successfully backstabs " << target->getName() << " for " << damageDealt
                          << " massive damage!" << std::endl;
                target->takeDamage(damageDealt);
            }
            else
            {
                std::cout << "'s backstab failed against a magic-user!" << std::endl;
            }
        }

        void performMeleeAttack(Character* target)
        {
            if (!target || !target->isAlive())
                return;
            int damageDealt = basicAttackDamage;
            target->takeDamage(damageDealt);
        }

        void attack(Character* target)
        {

            if (rand() % 2 == 0)
                performMeleeAttack(target);
            else
                backstab(target);
        }
};


#endif
