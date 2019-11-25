#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <QWidget>


class RecipeBook : public QWidget
{
    Q_OBJECT
public:
    RecipeBook (const double &s): scale(s){}
    void mousePressEvent ( QMouseEvent * event ) override;
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

signals:
    void clicked();

public slots:
  //  void is_clicked();

private:
    double scale;

friend class recipecreator;
};

#endif // RECIPEBOOK_H
