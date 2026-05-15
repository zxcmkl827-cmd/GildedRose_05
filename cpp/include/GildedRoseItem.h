#pragma once
#include "GildedRoseConstants.h"
#include "Item.h"

class GildedRoseItem {
protected:
  Item &item;

public:
  explicit GildedRoseItem(Item &i) : item(i) {}
  virtual void UpdateQuality() = 0;
  virtual void UpdateSellin() { item.sellIn--; }
  virtual ~GildedRoseItem() = default;
};

class AgedBrieItem : public GildedRoseItem {
public:
  using GildedRoseItem::GildedRoseItem;
  void UpdateQuality() override {
    if (item.quality < GildedRoseConstants::MaxQuality)
      item.quality++;
    if (item.sellIn < 1 && item.quality < GildedRoseConstants::MaxQuality)
      item.quality++;
  }
};

class BackStageItem : public GildedRoseItem {
public:
  using GildedRoseItem::GildedRoseItem;
  void UpdateQuality() override {
    if (item.quality < GildedRoseConstants::MaxQuality)
      item.quality++;

    if (item.sellIn < 11 && item.quality < GildedRoseConstants::MaxQuality)
      item.quality++;

    if (item.sellIn < 6 && item.quality < GildedRoseConstants::MaxQuality)
      item.quality++;

    if (item.sellIn < 1)
      item.quality = 0;
  }
};

class SulfurasItem : public GildedRoseItem {
public:
  using GildedRoseItem::GildedRoseItem;
  void UpdateQuality() override { return; }
  void UpdateSellin() override { return; }
};

class NormalItem : public GildedRoseItem {
public:
  using GildedRoseItem::GildedRoseItem;
  void UpdateQuality() override {
    if (item.quality > GildedRoseConstants::MinQuality)
      item.quality--;

    if (item.sellIn < 1 && item.quality > GildedRoseConstants::MinQuality)
      item.quality--;
  }
};

class ConjuredItem : public GildedRoseItem {
public:
  using GildedRoseItem::GildedRoseItem;
  void UpdateQuality() override {
    if (item.quality > GildedRoseConstants::MinQuality)
      item.quality--;

    if (item.sellIn < 1) {
      if (item.quality >= 4)
        item.quality -= 4;
      else
        item.quality = 0;
    } else {
      item.quality--;
    }
  }
};