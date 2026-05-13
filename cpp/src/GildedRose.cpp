#include "GildedRose.h"
#include "GildedRoseConstants.h"

GildedRose::GildedRose(std::vector<Item> &items) : items(items) {}
void GildedRose::UpdateAgedBrie(int idx) {
  if (items[idx].quality < GildedRoseConstants::MaxQuality) {
    items[idx].quality++;
  }

  items[idx].sellIn--;
  if (items[idx].sellIn < 0) {
    if (items[idx].quality < GildedRoseConstants::MaxQuality) {
      items[idx].quality++;
    }
  }
}

void GildedRose::UpdateBackstage(int idx) {
  if (items[idx].quality < GildedRoseConstants::MaxQuality) {
    items[idx].quality++;
  }

  if (items[idx].sellIn < 11) {
    if (items[idx].quality < GildedRoseConstants::MaxQuality) {
      items[idx].quality++;
    }
  }

  if (items[idx].sellIn < 6) {
    if (items[idx].quality < GildedRoseConstants::MaxQuality) {
      items[idx].quality++;
    }
  }
  items[idx].sellIn--;
  if (items[idx].sellIn < 0) {
    items[idx].quality = 0;
  }
}

void GildedRose::UpdateSulfuras(int idx) { return; }

void GildedRose::UpdateNormal(int idx) {
  if (items[idx].quality > GildedRoseConstants::MinQuality) {
    items[idx].quality--;
  }
  items[idx].sellIn--;
  if (items[idx].sellIn < 0) {
    if (items[idx].quality > GildedRoseConstants::MinQuality) {
      items[idx].quality--;
    }
  }
}

void GildedRose::UpdateConjured(int idx) {
  if (items[idx].quality > GildedRoseConstants::MinQuality) {
    items[idx].quality--;
  }
  items[idx].sellIn--;
  if (items[idx].sellIn < 0) {
    if (items[idx].quality >= 4) {
      items[idx].quality -= 4;
    } else {
      items[idx].quality = 0;
    }
  } else {
    items[idx].quality--;
  }
}

void GildedRose::updateQuality() {
  for (size_t i = 0; i < items.size(); i++) {
    if (items[i].name == GildedRoseConstants::AGEDBRIE) {
      UpdateAgedBrie(i);
    } else if (items[i].name == GildedRoseConstants::BACKSTAGE) {
      UpdateBackstage(i);
    } else if (items[i].name == GildedRoseConstants::SULFURAS) {
      UpdateSulfuras(i);
    } else if (items[i].name == GildedRoseConstants::CONJURED) {
      UpdateConjured(i);
    } else {
      UpdateNormal(i);
    }
  }
}
