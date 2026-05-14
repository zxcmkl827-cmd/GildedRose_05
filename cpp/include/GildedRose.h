#pragma once
#include "FoodBeverageItem.h"
#include "GildedRoseItem.h"
#include "Item.h"
#include <vector>

class GildedRose {
public:
  std::vector<Item> &items;
  GildedRose(std::vector<Item> &items);
  GildedRoseItem *CreateGildedItem(Item &item);
  void UpdateQuality();
};