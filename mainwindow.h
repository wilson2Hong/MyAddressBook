#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_search_clicked();

    void on_clear_clicked();

    void on_quit_clicked();

    void on_Add_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
