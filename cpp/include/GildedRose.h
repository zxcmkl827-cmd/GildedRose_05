#pragma once
#include "Item.h"
#include <vector>

class GildedRose {
public:
  std::vector<Item> &items;

  GildedRose(std::vector<Item> &items);
  void UpdateAgedBrie(int idx);
  void UpdateBackstage(int idx);
  void UpdateSulfuras(int idx);
  void UpdateConjured(int idx);
  void UpdateNormal(int idx);
  void updateQuality();
};
