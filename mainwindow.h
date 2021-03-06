#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "schaakStuk.h"

class ChessBoard;
class QSettings;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void update();

private:
    ChessBoard *scene;
    game g;
private slots:
    void clicked(int x, int y);
};

#endif // MAINWINDOW_H
