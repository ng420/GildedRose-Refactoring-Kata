#include "GildedRose.h"
#include <iostream>

const string SULFURAS = "Sulfuras, Hand of Ragnaros";
const string AGED_BRIE = "Aged Brie";
const string BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
const string CONJURED = "Conjured Mana Cake";

GildedRose::GildedRose(vector<Item> &items) : items(items)
{
}

CommonItem *ItemFactory::create(Item &item)
{
    if (item.name == SULFURAS)
    {
        return new Sulfuras(item);
    }
    else if (item.name == AGED_BRIE)
    {
        return new AgedBrie(item);
    }
    else if (item.name == BACKSTAGE_PASS)
    {
        return new BackStagePass(item);
    }
    else if (item.name == CONJURED) {
        return new Conjured(item);
    }
    return new CommonItem(item);
}

CommonItem::CommonItem(Item &item) : item(item) {}
void CommonItem::updateQuality()
{
    item.quality--;
    if (item.sellIn <= 0)
        item.quality--;
    item.quality = max(item.quality, 0);
}

CommonItem *CommonItem::updateSellin()
{
    item.sellIn--;
    return this;
}

AgedBrie::AgedBrie(Item &item) : CommonItem(item) {}
void AgedBrie::updateQuality()
{
    item.quality++;
    if (item.sellIn <= 0)
        item.quality++;
    item.quality = min(item.quality, 50);
}

Sulfuras::Sulfuras(Item &item) : CommonItem(item) {}
void Sulfuras::updateQuality() {}
CommonItem *Sulfuras::updateSellin() { return this; }

BackStagePass::BackStagePass(Item &item) : CommonItem(item) {}
void BackStagePass::updateQuality()
{
    item.quality++;
    if (item.sellIn < 11)
        item.quality++;
    if (item.sellIn < 6)
        item.quality++;
    if (item.sellIn <= 0)
        item.quality = 0;
    item.quality = min(item.quality, 50);
}

Conjured::Conjured(Item& item): CommonItem(item) {}
void Conjured::updateQuality() {
    item.quality = max(item.quality - 2, 0);
}

void GildedRose::updateQuality()
{
    for (Item& item: items)
    {
        ItemFactory::create(item)->updateSellin()->updateQuality();
    }
}
