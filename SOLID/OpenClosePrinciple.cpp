#include <iostream>
#include <bits/stdc++.h>
using namespace std;

enum class Color
{
    red,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    vector<Product *> by_color(vector<Product *> items, Color color)
    {
        vector<Product *> result;
        for (auto &x : items)
        {
            if (x->color == color)
                result.push_back(x);
        }
        return result;
    }

    vector<Product *> by_size(vector<Product *> items, Size size)
    {
        vector<Product *> result;
        for (auto &x : items)
        {
            if (x->size == size)
                result.push_back(x);
        }
        return result;
    }
};

template <typename T>
struct Specifications
{
    virtual bool is_satisfied(T *item) = 0;
};

template <typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> items, Specifications<T> &spec)  = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items,  Specifications<Product> &spec) override
    {
        vector<Product *> result;
        for (auto &x : items)
        {
            if (spec.is_satisfied(x))
                result.push_back(x);
        }
        return result;
    }
};

struct ColorSpecification : Specifications<Product>
{
    Color color;
    explicit ColorSpecification(const Color color)
    {
        this->color = color;
    }
    bool is_satisfied(Product *item) override
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specifications<Product>
{
    Size size;
    explicit SizeSpecification(const Size size)
    {
        this->size = size;
    }
    bool is_satisfied(Product *item) override
    {
        return item->size == size;
    }
};


int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product *> items{&apple, &tree, &house};


    BetterFilter bf;
    ColorSpecification green(Color::green);
    SizeSpecification large(Size::large);

    auto green_things = bf.filter(items, green);
    for (auto &x : green_things)
    {
        cout << x->name << " " << endl;
    }

    auto large_things = bf.filter(items, large);
    for (auto &x : large_things)
    {
        cout << x->name << " " << endl;
    }

}