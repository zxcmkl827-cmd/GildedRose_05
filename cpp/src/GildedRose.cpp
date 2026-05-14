#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> &items) : items(items) {}

GildedRoseItem *GildedRose::CreateGildedItem(Item &item) {
  if (item.name == GildedRoseConstants::AGEDBRIE) {
    AgedBrieItem *PtrAgedBrieItem = new AgedBrieItem(item);
    return PtrAgedBrieItem;
  } else if (item.name == GildedRoseConstants::BACKSTAGE) {
    BackStageItem *PtrBackStageItem = new BackStageItem(item);
    return PtrBackStageItem;
  } else if (item.name == GildedRoseConstants::SULFURAS) {
    SulfurasItem *PtrSulfurasItem = new SulfurasItem(item);
    return PtrSulfurasItem;
  } else if (item.name == GildedRoseConstants::CONJURED) {
    ConjuredItem *PtrConjuredItem = new ConjuredItem(item);
    return PtrConjuredItem;
  } else {
    NormalItem *PtrNormalItem = new NormalItem(item);
    return PtrNormalItem;
  }
}

void GildedRose::UpdateQuality() {
  for (auto &item : items) {
    GildedRoseItem *ptrGildedRoseItem = CreateGildedItem(item);
    ptrGildedRoseItem->UpdateQuality();
    ptrGildedRoseItem->UpdateSellin();
    delete ptrGildedRoseItem;
  }
}