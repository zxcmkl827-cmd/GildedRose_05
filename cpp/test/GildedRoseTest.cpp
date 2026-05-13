#include "GildedRose.h"
#include <gtest/gtest.h>

TEST(GildedRoseTest, NormalItemQualityLowerLimit) {
  std::vector<Item> items = {Item("noname", 0, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, -1);
  EXPECT_EQ(items[0].quality, 0);
}

TEST(GildedRoseTest, NormalItemSellInSpecOut) {
  std::vector<Item> items = {Item("noname", 0, 5)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, -1);
  EXPECT_EQ(items[0].quality, 3);
}

TEST(GildedRoseTest, SulfurasNoQualityDecrease_SellinSpecIn) {
  std::vector<Item> items = {Item("Sulfuras", 0, 5)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, 0);
  EXPECT_EQ(items[0].quality, 5);
}

TEST(GildedRoseTest, SulfurasNoQualityDecrease_SellinSpecOut) {
  std::vector<Item> items = {Item("Sulfuras", -1, 5)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, -1);
  EXPECT_EQ(items[0].quality, 5);
}

TEST(GildedRoseTest, AgedBrieQualityIncrease_SellinSpecOut) {
  std::vector<Item> items = {Item("AgedBrie", 0, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, -1);
  EXPECT_EQ(items[0].quality, 2);
}

TEST(GildedRoseTest, AgedBrieQualityUpperLimit) {
  std::vector<Item> items = {Item("AgedBrie", 0, 50)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, -1);
  EXPECT_EQ(items[0].quality, 50);
}

TEST(GildedRoseTest, BackStageOver10Days) {
  std::vector<Item> items = {Item("Backstage", 15, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, 14);
  EXPECT_EQ(items[0].quality, 1);
}

TEST(GildedRoseTest, BackStageQualityAfterConcert) {
  std::vector<Item> items = {Item("Backstage", 0, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, -1);
  EXPECT_EQ(items[0].quality, 0);
}

TEST(GildedRoseTest, BackStageOver50Quality) {
  std::vector<Item> items = {Item("Backstage", 0, 51)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items[0].sellIn, -1);
  EXPECT_EQ(items[0].quality, 0);
}

TEST(GildedRoseTest, EmptyItems) {
  std::vector<Item> items;
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(items.size(), 0);
}