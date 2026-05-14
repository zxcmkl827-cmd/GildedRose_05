#pragma once
#include "GildedRoseItem.h"

class FoodBegerageItem : public GildedRoseItem {
public:
  using GildedRoseItem::GildedRoseItem;
  void UpdateQuality() override {
    if (item.quality > GildedRoseConstants::MinQuality) {
      item.quality--;
      if (item.quality > GildedRoseConstants::MinQuality) {
        item.quality--;
      }
    }

    if (item.sellIn < 1) {
      if (item.quality > GildedRoseConstants::MinQuality) {
        item.quality--;
        if (item.quality > GildedRoseConstants::MinQuality) {
          item.quality--;
        }
      }
    }
  }
};