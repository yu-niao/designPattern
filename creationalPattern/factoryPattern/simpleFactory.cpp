#include <iostream>

enum MonsterType
{
    undead,
    element,
    mechanic
};

class Monster
{
public:
    Monster(int life, int magic, int attack)
    : life_(life)
    , magic_(magic)
    , attack_(attack)
    {}

    virtual ~Monster() {};

protected:
    int life_;
    int magic_;
    int attack_;

private:
};

class M_Undead : public Monster
{
public:
    M_Undead(int life, int magic, int attack) : Monster(life, magic, attack)
    {
        std::cout << "出现一只亡灵" << std::endl;
    }

};

class M_Element : public Monster
{
public:
    M_Element(int life, int magic, int attack) : Monster(life, magic, attack)
    {
        std::cout << "出现一只元素怪物" << std::endl;
    }

};

class M_Mechanic : public Monster
{
public:
    M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack)
    {
        std::cout << "出现一只机械怪物" << std::endl;
    }

};

class MonsterFactory
{
public:
    Monster* createMonster(MonsterType mt)
    {
        switch(mt)
        {
        case undead :
            return new M_Undead(200, 0, 30);
            break;
        case element :
            return new M_Element(100, 100, 20);
            break;
        case mechanic :
            return new M_Mechanic(500, 0, 20);
            break;
        default :
            std::cout << "输入参数错误" << std::endl;
            break;
        }
    }

};

int main()
{
    MonsterFactory* fac;
    Monster* ptr1 = fac->createMonster(undead);
    Monster* ptr2 = fac->createMonster(element);
    Monster* ptr3 = fac->createMonster(mechanic);

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}