#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Catch.hpp"
#include "GildedRose.h"

TEST_CASE("GildedRoseUnitTest", "Foo")
{
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    items.push_back(Item("Bar", -1, 8));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE("Foo" == app.items[0].name);
    REQUIRE(0 == app.items[0].quality);
    REQUIRE(-1 == app.items[0].sellIn);
    REQUIRE(6 == app.items[1].quality);
}

TEST_CASE("GildedRoseUnitTest2", "AgedBrieImprovesQuality")
{
    vector<Item> items;
    items.push_back(Item("Aged Brie", 5, 4));
    items.push_back(Item("Aged Brie", 0, 4));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(5 == app.items[0].quality);
    REQUIRE(4 == app.items[0].sellIn);
    REQUIRE(6 == app.items[1].quality);
}

TEST_CASE("GildedRoseUnitTest3", "BackstagePass")
{
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 4));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 10));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 48));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 48));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(5 == app.items[0].quality);
    REQUIRE(14 == app.items[0].sellIn);
    REQUIRE(12 == app.items[1].quality);
    REQUIRE(9 == app.items[1].sellIn);
    REQUIRE(50 == app.items[2].quality);
    REQUIRE(4 == app.items[2].sellIn);
    REQUIRE(0 == app.items[3].quality);
    REQUIRE(-1 == app.items[3].sellIn);
}

TEST_CASE("GildedRoseUnitTest4", "Sulfuras")
{
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 5, 80));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(80 == app.items[0].quality);
    REQUIRE(5 == app.items[0].sellIn);
}
