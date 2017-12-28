#include "mainwindow.h"
#include "schaakStuk.h"
#include <QMessageBox>

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    scene = new ChessBoard;
    QGraphicsView *view = new QGraphicsView(scene);
    setCentralWidget(view);
    connect(scene,SIGNAL(clicked(int,int)),this,SLOT(clicked(int,int)));

    //EXAMPLE
    scene->setInitialPositions();

    scene->
}

// Update de inhoud van de grafische weergave van het schaakbord (scene)
// en maak het consistent met de game state in variabele g.
void MainWindow::update() {
    for (auto i : schaakStukken) {
        scene->setItem(positie::charToInt(i.first[0]), (int)i.first[1], i.second->piece());
    }
}

// Deze functie wordt opgeroepen telkens er op het schaakbord
// geklikt wordt. x,y geeft de positie aan waar er geklikt
// werd; r is de 0-based rij, k de 0-based kolom
void MainWindow::clicked(int r, int k) {

    scene->setTileFocus(r,k,!scene->hasTileFocus(r,k));
    scene->setPieceFocus(r,k,!scene->hasPieceFocus(r,k));

    schaakStuk* s=new pion(wit);
    scene->setItem(r,k,s->piece());
    delete s;

    QMessageBox joehoe;
    joehoe.setText(QString("Je hebt een pion gezet. Wat knap!"));
    joehoe.exec();

    scene->removeAllFocus();

    for (int i=0;i<5;i++) {
        scene->setTileFocus(0, i, !scene->hasTileFocus(r, k));
        scene->setTileFocus(i, 2, !scene->hasTileFocus(r, k));
    }

    joehoe.setText(QString("Kijk, de letter T!"));
    joehoe.exec();

    scene->removeAllFocus();

}

