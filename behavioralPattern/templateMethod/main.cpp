#include <iostream>

class Fighter
{
public:
    Fighter(int life, int magic, int attack) 
    : life_(life)
    , magic_(magic)
    , attack_(attack)
    {} 

    virtual ~Fighter() {}

    void burn()
    {
        intro_self();
        if (!CanUseBurn())
        {
            std::cout << "生命不足，无法使用该技能" << std::endl;
        }
        else
        {
            effect_enemy();
            effect_self();
        }
    }

private:
    virtual void intro_self() = 0;
    virtual void effect_enemy() = 0;
    virtual void effect_self() = 0;
    virtual bool CanUseBurn() = 0;

    void paly_effect()
    {
        std::cout << "播放技能 '燃烧' 的技能特效" << std::endl;
    }

protected:
    int life_;
    int magic_;
    int attack_;
};

class F_Warrior : public Fighter
{
public:
    F_Warrior(int life, int magic, int attack) : Fighter(life, magic, attack){}

private:
    virtual void intro_self()
    {
        std::cout << "我是战士" << std::endl;
    }

    virtual void effect_enemy()
    {
        std::cout << "对敌人造成1000点伤害" << std::endl;
    }

    virtual void effect_self()
    {
        std::cout << "对自己造成300点伤害" << std::endl;
        life_ -= 300;
    }

    virtual bool CanUseBurn()
    {
        if (life_ > 300)
            return true;
        else
            return false;
    }

};

class F_Mage : public Fighter
{
public:
    F_Mage(int life, int magic, int attack) : Fighter(life, magic, attack){}

private:

    virtual void intro_self()
    {
        std::cout << "我是法师" << std::endl;
    }
    virtual void effect_enemy()
    {
        std::cout << "对敌人造成800点伤害" << std::endl;
    }

    virtual void effect_self()
    {
        std::cout << "对自己造成150点伤害" << std::endl;
        life_ -= 150;
    }

    virtual bool CanUseBurn()
    {
        if (life_ > 150)
            return true;
        else
            return false;
    }

};

int main()
{
    Fighter* ptr1 = new F_Warrior(1000, 0, 300);
    Fighter* ptr2 = new F_Mage(800, 500, 0);

    ptr1->burn();
    std::cout << "----------------------------" << std::endl;
    ptr2->burn();

    delete ptr1;
    delete ptr2;

    return 0;
}