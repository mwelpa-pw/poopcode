#ifndef FRUIT_HPP
#define FRUIT_HPP

enum class Color {Red, Orange, Green, Violet};
enum class FruitType {Apple, Orange, Plum};

struct Fruit {
    Color color;
    FruitType fruit_type;

    constexpr Fruit(Color c, FruitType ft) : color(c), fruit_type(ft) {}
};

static constexpr Fruit ripe_apple(Color::Red, FruitType::Apple);
static constexpr Fruit apple{Color::Green, FruitType::Apple};
static constexpr Fruit ripe_orange{Color::Orange, FruitType::Orange};
static constexpr Fruit orange{Color::Green, FruitType::Orange};
static constexpr Fruit ripe_plum{Color::Violet, FruitType::Plum};
static constexpr Fruit plum{Color::Green, FruitType::Plum};

#endif