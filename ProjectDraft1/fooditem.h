#ifndef FOODITEM_H
#define FOODITEM_H

#include <QString>
#include <QDate>

class FoodItem
{
public:
    FoodItem() : name(""), expiration(QDate::currentDate()), size(0) {}
    FoodItem(const QString& n, const QDate& e, const int& s) : name(n), expiration(e), size(s) {}
    bool operator < (const FoodItem& f);
    bool operator > (const FoodItem& f);
    bool operator == (const FoodItem& f);

    QString get_name() const;
    QDate get_expiration() const;
    int get_size() const;
    void set_name(const QString& new_name);
    void set_expiration(const QDate& new_expiration);
    void set_size(const double& new_size);

    bool expired();

private:
    QString name;
    QDate expiration;
    double size;

};

#endif // FOODITEM_H
