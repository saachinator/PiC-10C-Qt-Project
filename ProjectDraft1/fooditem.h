#ifndef FOODITEM_H
#define FOODITEM_H

#include <QString>

class FoodItem
{
public:
    FoodItem() : name(""), expiration(""), size(0) {}
    FoodItem(const QString& n, const QString& e, const int& s) : name(n), expiration(e), size(s) {}
    bool operator < (const FoodItem& f);
    bool operator > (const FoodItem& f);
    bool operator == (const FoodItem& f);
    QString get_name() const;
    QString get_expiration() const;
    int get_size() const;
private:
    QString name;
    QString expiration;
    int size;

};

#endif // FOODITEM_H
