#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <QDialog>
#include <QLabel>
#include <QList>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
enum   Direction {D_UP,D_DOWN,
     D_LEFT,D_RIGHT };
class  SnakeGame:public QDialog{
    Q_OBJECT
private:
QLabel    *food;
QList<QLabel*>  snake;
Direction   dire;
QTimer      *timer;
int         footLen;
int          score;
public:
SnakeGame();
~SnakeGame();
public slots:
void  snakeMove();
public:
void keyPressEvent(QKeyEvent *e);
QLabel*  getFood();
};
#endif // SNAKEGAME_H



