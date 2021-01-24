#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QInputDialog>
#include <QGraphicsView>
#include <QFileDialog>
#include <QErrorMessage>
#include <QMessageBox>
#include <QGraphicsPixmapItem>

#include <cmath>
#include <map>
#include <vector>

#include "quick.h"
#include "Graphics_view_zoom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void SetWindow();
    void LoadImages();

private:
    Ui::MainWindow *ui;

    std::map<std::pair<int, int>, QWidget*> elements;
    std::vector<Graphics_view_zoom*> zoomers;

    auto removeAll() -> void;
};
#endif // MAINWINDOW_H
