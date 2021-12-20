#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
};

class CommonItem
{
public:
    Item &item;
    CommonItem(Item &item);
    virtual void updateQuality();
    virtual CommonItem *updateSellin();
};

class AgedBrie : public CommonItem
{
public:
    AgedBrie(Item &item);
    void updateQuality();
};

class Sulfuras : public CommonItem
{
public:
    Sulfuras(Item &item);
    void updateQuality();
    virtual CommonItem *updateSellin();
};

class BackStagePass : public CommonItem
{
public:
    BackStagePass(Item &item);
    void updateQuality();
};

class Conjured : public CommonItem
{
public:
    Conjured(Item &item);
    void updateQuality();
};

class ItemFactory
{
public:
    static CommonItem *create(Item &item);
};
