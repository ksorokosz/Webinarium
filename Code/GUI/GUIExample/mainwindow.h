#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <aboutdialog.h>

namespace Ui {
class MainWindow;
}

// MainWindow dziedziczy po QMainWindow
// dziedziczenie jak w biologii
// dziedziczymy wszystkie publiczne cechy
class MainWindow : public QMainWindow
//dziecko (MainWindow)  otrzymuje cechy        rodzica (QMainWindow)
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    AboutDialog *about;

};

#endif // MAINWINDOW_H
